/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 06:02:03 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/30 06:12:09 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void rra(t_ps *ps)
{
	t_stack_elem *tmp;
	t_stack_elem *curr;

	if (ps->a->size < 2)
		return;
	curr = ps->a->top;
	while (curr->prev->prev)
		curr = curr->prev;
	tmp = curr->prev;
	curr->prev = NULL;
	tmp->prev = ps->a->top;
	ps->a->top = tmp;
}
