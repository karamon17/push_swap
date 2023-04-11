/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:19:53 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/10 18:19:54 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_length(t_list *head)
{
	int		length;
	t_list	*current;

	length = 1;
	current = head;
	if (head == NULL)
	{
		return (0);
	}
	while (current->next != head)
	{
		length++;
		current = current->next;
	}
	return (length);
}

void	sorting(t_list	**a, t_list	**b)
{
	int		length_a;
	int		length_b;

	length_a = get_list_length(*a);
	length_b = get_list_length(*b);
}

