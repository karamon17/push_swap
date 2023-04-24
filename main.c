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

void	create_list(t_list	**a, char **arr)
{
	int		i;
	t_list	*cursor;

	*a = ft_lstnew(ft_atoi(arr[0], arr));
	cursor = *a;
	i = 1;
	while (arr[i])
	{
		cursor->next = ft_lstnew(ft_atoi(arr[i], arr));
		cursor->next->prev = cursor;
		cursor = cursor->next;
		i++;
	}
	cursor->next = *a;
	(*a)->prev = cursor;
	free_arr(arr);
}

void	free_lst(t_list	*a)
{
	t_list	*current;

	if (!a)
		return ;
	current = a;
	while (current->next != a)
	{
		current = current->next;
		free(current->prev);
	}
	free(current);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{	
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	count_numbers(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (arr[i][0] == '-' && !arr[i][1])
			error(NULL, NULL, arr);
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*str;
	char	**arr;
	int		i;

	if (argc == 1)
		exit(0);
	i = 1;
	str = malloc(sizeof(char));
	str[0] = 0;
	while (i < argc)
	{
		if (argv[i][0] == 0)
			free_str(str);
		str = ft_strjoin(str, argv[i++]);
	}
	arr = ft_split(str, ' ');
	i = count_numbers(arr);
	check_argumets(i, arr);
	create_list(&a, arr);
	b = NULL;
	sorting(&a, &b);
	return (0);
}
