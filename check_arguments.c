/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 19:03:18 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/06 19:03:22 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(int *n, int current, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (n[i] == current)
		{
			write(1, "Error\n", 6);
			free(n);
			exit(0);
		}
		i++;
	}
}

void	check_sort(int *n, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i > 0 && n[i] < n[i -1])
			return ;
		i++;
	}
	free(n);
	exit(0);
}

void	check_argumets(int argc, char **argv)
{
	int	i;
	int	j;
	int	*n;

	i = 1;
	n = malloc(sizeof(int) * (argc - 1));
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((j == 0 && !ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				|| (j > 0 && !ft_isdigit(argv[i][j])))
			{
				write(1, "Error\n", 6);
				free(n);
				exit(0);
			}
			j++;
		}
		n[i - 1] = ft_atoi(argv[i]);
		check_duplicates(n, n[i - 1], i - 1);
		i++;
	}
	check_sort(n, argc - 1);
}
