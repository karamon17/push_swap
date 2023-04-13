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

void	push_2to_b(t_list	**a, t_list	**b, int *count)
{
	if (get_list_length(*a) >= 5)
	{
		pa_or_pb(a, b, count);
		pa_or_pb(a, b, count);
	}
	else if (get_list_length(*a) >= 4)
		pa_or_pb(a, b, count);
}

void	push_allto_b(t_list	**a, t_list	**b, int *count)
{
	int		max_b;
	int		min_b;

	while (get_list_length(*a) > 3)
	{
		max_b = find_max(*b);
		min_b = find_min(*b);
		if ((*a)->data > max_b || (*a)->data < min_b) //если верхнее число в *a больше или меньше макс/мин в *b, то его надо поместить над макс
		{
			if ((*b)->data == max_b) //если верхнее в *b является макс, то пушим из *a в *b
				pa_or_pb(a, b, count);
			else
			{
				while ((*b)->data != max_b) //иначе крутим *b пока там вверху не станет макс
					ra_or_rb(b, count);
				pa_or_pb(a, b, count); //пушим из *a в *b
			}
		}
		else //если верхнее число в *a не больше и не меньше макс/мин в *b, значит его надо вставить куда-то внутрь *b
		{
			while (!((*a)->data > (*b)->data && (*a)->data < (*b)->prev->data)) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
				ra_or_rb(b, count);
			pa_or_pb(a, b, count); //пушим из *a в *b
		}
	}
}

void	sorting(t_list	**a, t_list	**b)
{
	int		count;

	count = 0;
	push_2to_b(a, b, &count);
	push_allto_b(a, b, &count);
	sort_three(a, &count);
	while (*b)
	{
		if ((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data)
			pa_or_pb(b, a, &count);
		else if ((*b)->data < find_min(*a) || (*b)->data > find_max(*a))
		{
			while ((*a)->data != find_min(*a))
				ra_or_rb(a, &count);
			pa_or_pb(b, a, &count);
		}
		else
		{
			while (!((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data))
			{
				ra_or_rb(a, &count);
			}
			pa_or_pb(b, a, &count);
		}
	}
	while ((*a)->data != find_min(*a))
		ra_or_rb(a, &count);
	printf("%d это кол-во операций\n", count);
}


	// printf("%d это а\n", get_list_length(*a));
	// printf("%d это b\n", get_list_length(*b));
	//length_b = get_list_length(*b);
	//printf("%d\n", count);
	// printf("%d это а\n", get_list_length(*a));
	// printf("%d это b\n", get_list_length(*b));
	//printf("%d", (*b)->data);
	//printf("%d это второй b\n", (*b)->next->data);
	//printf("%d это max_b\n", find_max(*b));
	// printf("стек а до сортировки\n");
	// printf("%d\n", (*a)->data);
	// printf("%d\n", (*a)->next->data);
	// printf("%d\n", (*a)->next->next->data);
	//printf("%d это b\n", get_list_length(*b));
	//printf("%d это b\n", get_list_length(*b));
	// t_list	*current;
	// current = *a;
	// while (current->next != *a)
	// {
	// 	printf("%d\n", current->data);
	// 	current = current->next;
	// }// printf("%d\n", current->data);
	// printf("стек а после сортировки\n");
	// printf("%d\n", (*a)->data);
	// printf("%d\n", (*a)->next->data);
	// printf("%d\n", (*a)->next->next->data);