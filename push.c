/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:19:27 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/13 13:19:28 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push1(t_list **from, t_list **to, t_list **tmp)
{
	if (*to && (*to)->next != (*to))
	{
		*tmp = (*from);
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
		(*to)->prev->next = *tmp;
		(*tmp)->prev = (*to)->prev;
		(*to)->prev = *tmp;
		(*tmp)->next = (*to);
		(*to) = *tmp;
		return (1);
	}
	return (0);
}

void	push2(t_list **from, t_list **to, t_list **tmp)
{
	if (*to)
	{
		*tmp = (*from);
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
		(*to)->prev = *tmp;
		(*tmp)->next = (*to);
		(*to)->next = *tmp;
		(*tmp)->prev = (*to);
		(*to) = *tmp;
	}
	else
	{
		*tmp = (*from);
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
		(*to) = *tmp;
		(*to)->prev = *tmp;
		(*to)->next = *tmp;
	}
}

void	pa_or_pb(t_list **from, t_list **to, char *str)
{
	t_list	*tmp;

	if (*from == NULL)
		return ;
	if (*from && (*from)->next == *from)
	{
		tmp = (*from);
		(*to)->prev->next = tmp;
		tmp->prev = (*to)->prev;
		(*to)->prev = tmp;
		tmp->next = (*to);
		(*to) = tmp;
		(*from) = NULL;
		write(1, str, ft_strlen(str));
		return ;
	}
	if (push1(from, to, &tmp))
	{
		write(1, str, ft_strlen(str));
		return ;
	}
	push2(from, to, &tmp);
	write(1, str, ft_strlen(str));
}
