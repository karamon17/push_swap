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

void	push_2to_b(t_list	**a, t_list	**b)
{
	if (get_list_length(*a) >= 5)
	{
		pa_or_pb(a, b);
		pa_or_pb(a, b);
		write(1, "pb\n", 3);
		write(1, "pb\n", 3);
	}
	else if (get_list_length(*a) >= 4)
	{	
		pa_or_pb(a, b);
		write(1, "pb\n", 3);
	}
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
		if (!(score >= min_score && min_score > 1))
		{
			while (j)
			{
				current_a = current_a->next;
				j--;
			}
			if (current_a->data > find_max(b) || current_a->data < find_min(b))
			{
				while (current_b->data != find_max(b))
				{	
					if (find_index(b, find_max(b)) < get_list_length(b) / 2)
						current_b = current_b->next;
					else
						current_b = current_b->prev;
					if (score >= min_score && min_score != -1)
						break;
					score++;
				}
				if (min_score > score || min_score == -1)
				{
					min_score = score;
					*num = current_a->data;
				}
			}
			else
			{
				while (!(current_a->data > current_b->data && current_a->data < current_b->prev->data)) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
				{	
					if (find_index(b, find_nearest(b, current_a->data)) < get_list_length(b) / 2)
						current_b = current_b->next;
					else
						current_b = current_b->prev;
					score++;
					if (score >= min_score && min_score != -1)
						break;
				}
				if (min_score > score || min_score == -1)
				{
					min_score = score;
					*num = current_a->data;
				}
			}
			if (min_score == 0 || min_score == 1)
				break;
		}
		i++;
	}
}

void	rotate_push(t_list	**a, t_list	**b, int num)
{
	if (num > find_max(*b) || num < find_min(*b)) //если нужное число в *a больше или меньше макс/мин в *b, то его надо поместить над макс
	{
		while ((*b)->data != find_max(*b) && (*a)->data != num) //крутим *b и *a пока там вверху не станет макс и num
			if (find_index(*a, num) < get_list_length(*a) / 2)
				rr(a, b);
			else
				rrr(a, b);
		if((*b)->data == find_max(*b) && (*a)->data != num) //если b докрутили до нужного места, то продолжаем крутить только a
			while((*a)->data != num)
			{	
				if (find_index(*a, num) < get_list_length(*a) / 2)
				{
					ra_or_rb(a);
					write(1, "ra\n", 3);
				}
				else
				{	
					rra_or_rrb(a);
					write(1, "rra\n", 4);
				}
			}
		else if((*b)->data != find_max(*b) && (*a)->data == num) //и наоборот
			while((*b)->data != find_max(*b))
			{
				if (find_index(*b, find_max(*b)) < get_list_length(*b) / 2)
				{	
					ra_or_rb(b);
					write(1, "rb\n", 3);
				}
				else
				{
					rra_or_rrb(b);
					write(1, "rrb\n", 4);
				}
			}
		pa_or_pb(a, b);
		write(1, "pb\n", 3);
	}
	else //если нужное число в *a не больше и не меньше макс/мин в *b, значит его надо вставить куда-то внутрь *b
	{
		while (!(num > (*b)->data && num < (*b)->prev->data) && (*a)->data != num) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
			if (find_index(*a, num) < get_list_length(*a) / 2)
				rr(a, b);
			else
				rrr(a, b);
		if((*a)->data == num)
		{
			while (!(num > (*b)->data && num < (*b)->prev->data)) //крутим пока не найдем нужное место (то есть пока верхнее число в *a не больше чем верхнее *b  и не меньше чем prev *b)
			{	
				if (find_index(*b, find_nearest(*b, num)) < get_list_length(*b) / 2)
				{	
					ra_or_rb(b);
					write(1, "rb\n", 3);
				}
				else
				{
					rra_or_rrb(b);
					write(1, "rrb\n", 4);
				}
			}
		}
		else if((*a)->data != num)
		{
			while ((*a)->data != num)
			{
				if (find_index(*a, num) < get_list_length(*a) / 2)
				{	
					ra_or_rb(a);
					write(1, "ra\n", 3);
				}
				else
				{
					rra_or_rrb(a);
					write(1, "rra\n", 4);
				}
			}
		}
		pa_or_pb(a, b);
		write(1, "pb\n", 3);
	}
}

void	push_allto_b(t_list	**a, t_list	**b)
{
	int	num;

	while (get_list_length(*a) > 3)
	{
		find_min_score(*a, *b, &num);
		rotate_push(a, b, num);
		if (check_sort_stack(a))
			return ;
	}
	if (get_list_length(*a) == 3 && !check_sort_stack(a))
		sort_three(a);
}

void	push_backto_a(t_list	**a, t_list	**b)
{
	while (*b)
	{
		if ((*b)->data < find_min(*a) || (*b)->data > find_max(*a))
			while ((*a)->data != find_min(*a))
			{
				if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
				{	
					ra_or_rb(a);
					write(1, "ra\n", 3);
				}
				else
				{	
					rra_or_rrb(a);
					write(1, "rra\n", 4);
				}
			}
		else
			while (!((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data))
			{	
				if (find_index(*a, find_nearest(*a, (*b)->data)) < get_list_length(*a) / 2)
				{	
					ra_or_rb(a);
					write(1, "ra\n", 3);
				}
				else
				{	
					rra_or_rrb(a);
					write(1, "rra\n", 4);
				}
			}
		pa_or_pb(b, a);
		write(1, "pa\n", 3);
	}
}

void	sorting(t_list	**a, t_list	**b)
{
	push_2to_b(a, b);
	push_allto_b(a, b);
	push_backto_a(a, b);
	while ((*a)->data != find_min(*a))
	{
		if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
		{	
			ra_or_rb(a);
			write(1, "ra\n", 3);
		}
		else
		{	
			rra_or_rrb(a);
			write(1, "rra\n", 4);
		}
	}
}
