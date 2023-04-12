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
	int		count;

	count = 0;
	// printf("%d это а\n", get_list_length(*a));
	// printf("%d это b\n", get_list_length(*b));
	//length_b = get_list_length(*b);
	if (get_list_length(*a) > 5)
	{
		pa_or_pb(a, b, &count);
	}
	printf("%d\n", count);
	printf("%d это а\n", get_list_length(*a));
	printf("%d это b\n", get_list_length(*b));
	//printf("%d", (*b)->data);
	// while(get_list_length(*a) > 3)
	// {

	// }
}
