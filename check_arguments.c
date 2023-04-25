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

void	check_duplicates(int *n, int current, int len, char **arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (n[i] == current)
		{
			write(2, "Error\n", 6);
			free(n);
			free_arr(arr);
			exit(1);
		}
		i++;
	}
}

void	check_sort(int *n, int len, char **arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i > 0 && n[i] < n[i - 1])
		{
			free(n);
			return ;
		}
		i++;
	}
	free(n);
	free_arr(arr);
	exit(0);
}

void	check_str(char *ar, char *str)
{
	int	i;

	i = 0;
	if (ar[0] == 0)
		free_str(str);
	while (ar[i] == ' ')
		i++;
	if (ar[i] == 0)
		free_str(str);
}

void	check_argumets(int count, char **arr)
{
	int	i;
	int	j;
	int	*n;

	n = malloc(sizeof(int) * (count));
	i = -1;
	while (arr[++i])
	{
		j = 0;
		while (arr[i][j])
		{
			if ((j == 0 && !ft_isdigit(arr[i][j]) && arr[i][j] != '-')
				|| (j > 0 && !ft_isdigit(arr[i][j])))
			{
				write(2, "Error\n", 6);
				free_arr(arr);
				free(n);
				exit(1);
			}
			j++;
		}
		n[i] = ft_atoi(arr[i], arr);
		check_duplicates(n, n[i], i, arr);
	}
	check_sort(n, count, arr);
}
