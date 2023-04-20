/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:40:44 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/02/13 18:40:46 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000000
#endif

static void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

static char	*ft_checknext(char **next, char **res)
{
	char	*p_n;

	p_n = 0;
	if (*next)
	{
		p_n = ft_strchr(*next, '\n');
		if ((p_n))
		{
			*p_n = 0;
			*res = ft_strdup(*next);
			*res = ft_strjoin_gnl(*res, "\n");
			ft_strcpy(*next, ++p_n);
		}
		else
		{
			*res = ft_strdup(*next);
			free(*next);
			*next = 0;
		}
	}
	else
		*res = ft_calloc(1, 1);
	return (p_n);
}

static char	*free_end(char **res)
{
	if (*res[0] == 0)
	{
		free(*res);
		*res = 0;
	}
	return (*res);
}

void	addict(char **p_n, char **res, char *str, char **next)
{
	*p_n = ft_strchr(str, '\n');
	**p_n = 0;
	*next = ft_strdup(++(*p_n));
	*res = ft_strjoin_gnl(*res, str);
	*res = ft_strjoin_gnl(*res, "\n");
}

char	*get_next_line(int fd)
{
	char static	*next;
	char		*res;
	char		str[BUFFER_SIZE + 1];
	char		*p_n;
	int			read_bites;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	p_n = ft_checknext(&next, &res);
	if (!p_n)
		read_bites = read(fd, str, BUFFER_SIZE);
	while (!p_n && read_bites > 0)
	{
		str[read_bites] = 0;
		if (ft_strchr(str, '\n'))
			addict(&p_n, &res, str, &next);
		else
		{
			res = ft_strjoin_gnl(res, str);
			read_bites = read(fd, str, BUFFER_SIZE);
		}
		if (!res)
			return (0);
	}
	return (free_end(&res));
}