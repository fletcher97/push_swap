/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 06:02:03 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:22:45 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

#include "actions.h"

void	rrb(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

	if (ps->b->size < 2)
		return ;
	curr = ps->b->top;
	while (curr->prev->prev)
		curr = curr->prev;
	tmp = curr->prev;
	curr->prev = NULL;
	tmp->prev = ps->b->top;
	ps->b->top = tmp;
}

void print_rrb(t_ps *ps)
{
	ft_putstr_fd("rrb\n", STDOUT);
	rrb(ps);
}
