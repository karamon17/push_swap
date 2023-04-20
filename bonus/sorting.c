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
	while (head->data != find_min(head))
		head = head->next;
	current1 = head;
	while (current1->next != head)
	{
		if (current1->data > current1->next->data)
			return (0);
		current1 = current1->next;
	}
	return (1);
}

void	sorting(t_list	**a, t_list	**b)
{
	char *line;

	line = get_next_line(0);
    while (line > 0)
    {
        if (line[0] == 's' && line[1] == 'a')
			sa_or_sb(a);
		else if (line[0] == 's' && line[1] == 'b')
			sa_or_sb(b);
		else if (line[0] == 'p' && line[1] == 'a')
			pa_or_pb(b, a);
		else if (line[0] == 'p' && line[1] == 'b')
			pa_or_pb(a, b);
		else if (line[0] == 'r' && line[1] == 'a')
			ra_or_rb(a);
		else if (line[0] == 'r' && line[1] == 'b')
			ra_or_rb(b);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a')
			rra_or_rrb(a);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b')
			rra_or_rrb(b);
		else if (line[0] == 'r' && line[1] == 'r' && !line[2])
			rr(a, b);
		else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r')
			rrr(a, b);
        free(line);
		line = get_next_line(0);
    }
	if (line)
		free(line);
	if (check_sort_stack(*a, *b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
