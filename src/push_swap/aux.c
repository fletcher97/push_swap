/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:24:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/06 11:00:49 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_stdlib.h"

void bring_up(t_ps *ps, int sizea, int sizeb)
{
	while (sizea < 0 && sizeb < 0)
	{
		push_rrr(ps);
		sizea++;
		sizeb++;
	}
	while (sizea < 0)
	{
		push_rra(ps);
		sizea++;
	}
	while (sizeb < 0)
	{
		push_rrb(ps);
		sizeb++;
	}
}

void sswap(t_ps *ps, int s1, int s2)
{
	if (ft_abs(s1) == 2 && ps->a->top->cont.i > ps->a->top->prev->cont.i)
	{
		if (ft_abs(s2) == 2 && ps->b->top->cont.i < ps->b->top->prev->cont.i)
			push_ss(ps);
		else
			push_sa(ps);
	}
	else if (ft_abs(s2) == 2 && ps->b->top->cont.i < ps->b->top->prev->cont.i)
		push_sb(ps);
}
