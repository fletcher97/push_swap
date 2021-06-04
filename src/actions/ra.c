/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:49:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:22:24 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

#include "ft_stdlib.h"
#include "ft_stack.h"
#include "actions.h"

void	ra(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

	if (ps->a->size < 2)
		return ;
	tmp = ps->a->top;
	ps->a->top = ps->a->top->prev;
	tmp->prev = NULL;
	curr = ps->a->top;
	while (curr->prev)
		curr = curr->prev;
	curr->prev = tmp;
}

void print_ra(t_ps *ps)
{
	ft_putstr_fd("ra\n", STDOUT);
	ra(ps);
}
