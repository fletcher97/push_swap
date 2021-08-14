/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 08:24:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 17:20:33 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_list.h"
#include "ft_string.h"

void	bring_up(t_ps *ps, int sizea, int sizeb)
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

void	sswap(t_ps *ps, int s1, int s2)
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

void	rem_next(t_list *l)
{
	t_list	*tmp;

	if (!l->next)
		return ;
	tmp = l->next->next;
	ft_lstdelone(l->next, ft_free);
	l->next = tmp;
}

void	replace_content(t_list *l, char *str)
{
	ft_free(l->content);
	l->content = ft_strdup(str);
}

void	print_list(t_list *curr)
{
	while (curr)
	{
		ft_putstr_fd(curr->content, 1);
		curr = curr->next;
	}
}
