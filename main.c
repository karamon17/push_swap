/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:15:37 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/06 12:15:38 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	check_argumets(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((j == 0 && !ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				|| (j > 0 && !ft_isdigit(argv[i][j])))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		ft_atoi(argv[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		*n;
	t_list	*list;
	t_list	*start;
	int		i;

	if (argc == 1)
		exit(1);
	check_argumets(argv);
	list = (t_list *)malloc(sizeof(t_list));
	start = list;
	list->data = ft_atoi(argv[1]);
	list->next = 0;
	list->prev = 0;
	i = 2;
	while (argv[i])
	{
		list->next = ft_lstnew(list, ft_atoi(argv[i]));
		list = list->next;
		i++;
	}
	// i = 0;
	// while(start)
	// {
	// 	printf("%d\n", start->data);
	// 	start = start->next;
	// }
	
}
