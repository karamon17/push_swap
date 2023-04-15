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

int	find_index(t_list *stack, int num)
{
	int index;

	index = 0;
	while (stack->data != num)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	find_nearest(t_list *head, int num)
{
	t_list	*current;

	while(1)
	{
		num--;
		current = head;
		while(current->next != head)
		{	
			if (current->data == num)
				return (num);
			current = current->next;
		}
		if (current->data == num)
			return (num);
	}
}

void	find_min_score(t_list *a, t_list *b, int *num)
{
	int min_score;
	int	score;
	int	i;
	int	j;
	t_list	*current_b;
	t_list	*current_a;
	
	i = 0;
	min_score = -1;
	while (get_list_length(a) - i > 0)
	{
		score = 0;
		current_a = a;
		current_b = b;
		j = i;
		if (j > get_list_length(a) / 2)
			score = get_list_length(a) - j;
		else
			score = j;
		while (j)
		{
			current_a = current_a->next;
			j--;
		}
		if (current_a->data > find_max(b) || current_a->data < find_min(b)) //если верхнее число в *a больше или меньше макс/мин в *b, то его надо поместить над макс
		{
			while (current_b->data != find_max(b)) //крутим *b пока там вверху не станет макс
			{	
				if (find_index(b, find_max(b)) < get_list_length(b) / 2)
					current_b = current_b->next;
				else
					current_b = current_b->prev;
				score++;
			}
			if (min_score > score || min_score == -1)
			{
				min_score = score;
				*num = current_a->data;
			}
		}
		else //если верхнее число в *a не больше и не меньше макс/мин в *b, значит его надо вставить куда-то внутрь *b
		{
			while (!(current_a->data > current_b->data && current_a->data < current_b->prev->data)) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
			{	
				if (find_index(b, find_nearest(b, current_a->data)) < get_list_length(b) / 2)
					current_b = current_b->next;
				else
					current_b = current_b->prev;
				score++;
			}
			if (min_score > score || min_score == -1)
			{
				min_score = score;
				*num = current_a->data;
			}
		}
		i++;
		if (min_score == 0 || min_score == 1)
			break;
	}
}

void	rotate_push(t_list	**a, t_list	**b, int *count, int num)
{
	if (num > find_max(*b) || num < find_min(*b)) //если нужное число в *a больше или меньше макс/мин в *b, то его надо поместить над макс
	{
		while ((*b)->data != find_max(*b) && (*a)->data != num) //крутим *b и *a пока там вверху не станет макс и num
		{	
			if (find_index(*a, num) < get_list_length(*a) / 2)
				rr(a, b, count);
			else
				rrr(a, b, count);
		}
		if ((*b)->data == find_max(*b) && (*a)->data == num)
			pa_or_pb(a, b, count); //пушим из *a в *b
		else if((*b)->data == find_max(*b) && (*a)->data != num) //если b докрутили до нужного места, то продолжаем крутить только a
		{
			while((*a)->data != num)
			{	
				if (find_index(*a, num) < get_list_length(*a) / 2)
					ra_or_rb(a, count);
				else
					rra_or_rrb(a, count);
			}
			pa_or_pb(a, b, count);
		}
		else if((*b)->data != find_max(*b) && (*a)->data == num) //и наоборот
		{
			while((*b)->data != find_max(*b))
			{
				if (find_index(*b, find_max(*b)) < get_list_length(*b) / 2)
					ra_or_rb(b, count);
				else
					rra_or_rrb(b, count);
			}
			pa_or_pb(a, b, count);
		}
	}
	else //если нужное число в *a не больше и не меньше макс/мин в *b, значит его надо вставить куда-то внутрь *b
	{
		while (!(num > (*b)->data && num < (*b)->prev->data) && (*a)->data != num) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
		{
			if (find_index(*a, num) < get_list_length(*a) / 2)
				rr(a, b, count);
			else
				rrr(a, b, count);
		}
		if((*a)->data == num)
		{
			while (!(num > (*b)->data && num < (*b)->prev->data)) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
			{	
				if (find_index(*b, find_nearest(*b, num)) < get_list_length(*b) / 2)
					ra_or_rb(b, count);
				else
					rra_or_rrb(b, count);
			}
			pa_or_pb(a, b, count);
		}
		else if((*a)->data != num)
		{
			while ((*a)->data != num)
			{
				if (find_index(*a, num) < get_list_length(*a) / 2)
					ra_or_rb(a, count);
				else
					rra_or_rrb(a, count);
			}
			pa_or_pb(a, b, count); //пушим из *a в *b
		}
	}
}

void	push_allto_b(t_list	**a, t_list	**b, int *count)
{
	int	num;

	while (get_list_length(*a) > 3)
	{
		find_min_score(*a, *b, &num);
		rotate_push(a, b, count, num);
		if (check_sort_stack(a))
			return ;
	}
}

void	push_backto_a(t_list	**a, t_list	**b, int *count)
{
	while (*b) //пока *b не пустой пушим из *b в *a в нужное место
	{
		if ((*b)->data < find_min(*a) || (*b)->data > find_max(*a))
		{
			while ((*a)->data != find_min(*a))
			{
				if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
					ra_or_rb(a, count);
				else
					rra_or_rrb(a, count);
			}
			pa_or_pb(b, a, count);
		}
		else
		{
			while (!((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data))
			{	
				if (find_index(*a, find_nearest(*a, (*b)->data)) < get_list_length(*a) / 2)
					ra_or_rb(a, count);
				else
					rra_or_rrb(a, count);
			}
			pa_or_pb(b, a, count);
		}
	}
}

void	sorting(t_list	**a, t_list	**b)
{
	int		count;

	count = 0;
	push_2to_b(a, b, &count);
	push_allto_b(a, b, &count);
	if (get_list_length(*a) == 3 && !check_sort_stack(a))
		sort_three(a, &count);
	push_backto_a(a, b, &count);
	while ((*a)->data != find_min(*a))
	{
		if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
			ra_or_rb(a, &count);
		else
			rra_or_rrb(a, &count);
	}
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
	// t_list	*current;
	// current = *a;
	// while (current->next != *a)
	// {
	// 	printf("%d\n", current->data);
	// 	current = current->next;
	// }
	//printf("%d\n", current->data);