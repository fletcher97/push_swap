/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 07:46:06 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 15:38:10 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include "ft_string.h"
#include "common.h"
#include "actions.h"

char	issorted(t_stack *s)
{
	t_content		tmp;
	t_stack_elem	*curr;

	curr = s->top;
	if (curr)
		tmp = curr->cont;
	while (curr->prev)
	{
		if (tmp.i > curr->prev->cont.i)
			return (0);
		curr = curr->prev;
		tmp = curr->cont;
	}
	return (1);
}

static void	run(t_ps *ps, char *op)
{
	if (ft_strcmp(op, "sa"))
		sa(ps);
	else if (ft_strcmp(op, "sb"))
		sb(ps);
	else if (ft_strcmp(op, "ss"))
		ss(ps);
	else if (ft_strcmp(op, "pa"))
		pa(ps);
	else if (ft_strcmp(op, "pb"))
		pb(ps);
	else if (ft_strcmp(op, "ra"))
		ra(ps);
	else if (ft_strcmp(op, "rb"))
		rb(ps);
	else if (ft_strcmp(op, "rr"))
		rr(ps);
	else if (ft_strcmp(op, "rra"))
		rra(ps);
	else if (ft_strcmp(op, "rrb"))
		rrb(ps);
	else if (ft_strcmp(op, "rrr"))
		rrr(ps);
}

int	sorts(t_ps *ps, t_stack *ops)
{
	t_ps			*s;
	int				ret;
	t_stack_elem	*aux;

	if (!ps || !ps->a || !ps->b || !ops || !ops)
		return (0);
	s = dup_ps(ps);
	aux = ops->top;
	while (aux)
	{
		run(s, aux->cont.str);
		aux = aux->prev;
	}
	ret = s->b->size == 0 && issorted(s->a);
	destroy_ps(s);
	return (ret);
}
