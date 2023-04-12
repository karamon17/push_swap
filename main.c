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

void	create_list(t_list	**a, char **arr)
{
	int		i;
	t_list	*cursor;

	*a = ft_lstnew(ft_atoi(arr[0]));
	cursor = *a;
	i = 1;
	while (arr[i])
	{
		cursor->next = ft_lstnew(ft_atoi(arr[i]));
		cursor->next->prev = cursor;
		cursor = cursor->next;
		i++;
	}
	cursor->next = *a;
	(*a)->prev = cursor;
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*str;
	char	**arr;
	int		i;

	if (argc == 1)
		exit(1);
	i = 1;
	str = malloc(sizeof(char));
	str[0] = 0;
	while (i < argc)
		str = ft_strjoin(str, argv[i++]);
	arr = ft_split(str, ' ');
	check_argumets(argc, arr);
	a = (t_list *)malloc(sizeof(t_list));
	create_list(&a, arr);
	b = NULL;
	sorting(&a, &b);
}
