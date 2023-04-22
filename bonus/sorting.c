/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:33 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/21 15:17:35 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

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

int	find_min(t_list *head)
{
	int		min;
	t_list	*current;

	current = head;
	min = current->data;
	while (current->next != head)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	if (current->data < min)
		min = current->data;
	return (min);
}

int	check_sort_stack(t_list	*head, t_list *b)
{
	t_list	*current1;

	if (get_list_length(b))
		return (0);
	current1 = head;
	while (current1->next != head)
	{
		if (current1->data > current1->next->data)
			return (0);
		current1 = current1->next;
	}
	return (1);
}

void	sorting_help(char *l, t_list **a, t_list **b)
{
	if (l[0] == 's' && l[1] == 'a' && l[2] == '\n')
		sa_or_sb(a);
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\n')
		sa_or_sb(b);
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\n')
		ss(a, b);
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\n')
		pa_or_pb(b, a);
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\n')
		pa_or_pb(a, b);
	else if (l[0] == 'r' && l[1] == 'a' && l[2] == '\n')
		ra_or_rb(a);
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\n')
		ra_or_rb(b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\n')
		rra_or_rrb(a);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\n')
		rra_or_rrb(b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\n')
		rr(a, b);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\n')
		rrr(a, b);
	else
		error(*a, *b, NULL);
}

void	sorting(t_list	**a, t_list	**b)
{
	char	*line;

	line = get_next_line(0);
	while (line > 0)
	{
		sorting_help(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (line)
		free(line);
	if (check_sort_stack(*a, *b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_lst(*a);
}
