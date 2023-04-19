/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:00:41 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/06 13:00:44 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (res * sign > INT_MAX || res * sign < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return ((int)res * sign);
}

int	ft_isdigit(int arg)
{
	return (arg >= '0' && arg <= '9');
}

t_list	*ft_lstnew(int data)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (0);
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = ' ';
	res[i + 1] = 0;
	free((void *)s1);
	return (res);
}
