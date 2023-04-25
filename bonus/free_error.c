/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:23:55 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/25 12:23:58 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error(t_list *a, t_list *b, char **arr)
{
	write(2, "Error\n", 6);
	free_arr(arr);
	free_lst(a);
	free_lst(b);
	exit(1);
}

void	free_str(char *str)
{
	free(str);
	write(2, "Error\n", 6);
	exit(1);
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
