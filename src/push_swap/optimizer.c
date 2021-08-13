/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:04:11 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/12 02:27:06 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include "actions.h"
#include "push_swap.h"

static int	check_next(t_list *l, char *op)
{
	if (ft_strcmp(op, "ra\n") || ft_strcmp(op, "rra\n"))
		return ft_strcmp(l->content, "ra\n") || ft_strcmp(l->content, "sa\n")
			|| ft_strcmp(l->content, "rra\n");
	if (ft_strcmp(op, "rb\n") || ft_strcmp(op, "rrb\n"))
		return ft_strcmp(l->content, "rb\n") || ft_strcmp(l->content, "sb\n")
			|| ft_strcmp(l->content, "rrb\n");
	return (0);
}

int	print_op_p(t_list **l)
{
	char	*op1;
	char	*op2;

	if ((*l)->next && ft_strcmp((*l)->content, "pa\n")
		&& ft_strcmp((*l)->next->content, "rrb\n") && (*l)->next->next
		&& ft_strcmp((*l)->next->next->content, "pb\n"))
	{
		op1 = "rrb\n";
		op2 = "sb\n";
	}
	else if ((*l)->next && ft_strcmp((*l)->next->content, "rra\n")
		&& (*l)->next->next && ft_strcmp((*l)->next->next->content, "pa\n"))
	{
		op1 = "rra\n";
		op2 = "sa\n";
	}
	else
		return (0);
	replace_content(*l, op1);
	replace_content((*l)->next, op2);
	rem_next((*l)->next);
	return (1);
}

int	print_op_r(t_list **l)
{
	t_list	*curr;

	curr = (*l);
	while (curr->next && check_next(curr->next, (*l)->content))
		curr = curr->next;
	if (curr->next && ((ft_strcmp((*l)->content, "ra\n")
		&& ft_strcmp(curr->next->content, "rb\n"))
		|| (ft_strcmp((*l)->content, "rb\n")
		&& ft_strcmp(curr->next->content, "ra\n"))))
	{
		replace_content(*l, "rr\n");
		rem_next(curr);
		return (1);
	}
	return (0);
}

int	print_op_rr(t_list **l)
{
	t_list	*curr;

	curr = (*l);
	while (curr->next && check_next(curr->next, (*l)->content))
		curr = curr->next;
	if (curr->next && ((ft_strcmp((*l)->content, "rra\n")
		&& ft_strcmp(curr->next->content, "rrb\n"))
		|| (ft_strcmp((*l)->content, "rrb\n")
		&& ft_strcmp(curr->next->content, "rra\n"))))
	{
		replace_content(*l, "rrr\n");
		rem_next(curr);
		return (1);
	}
	return (0);
}

void	optimize(t_ps *ps)
{
	t_list	*curr;
	char	*op;
	int		changed;

	changed = 1;
	while (changed)
	{
		changed = 0;
		curr = ps->out;
		while (curr)
		{
			op = curr->content;
			if ((ft_strcmp(op, "pa\n") || ft_strcmp(op, "pb\n"))
				&& print_op_p(&curr))
				changed = 1;
			else if ((ft_strcmp(op, "ra\n") || ft_strcmp(op, "rb\n"))
				&& print_op_r(&curr))
				changed = 1;
			else if ((ft_strcmp(op, "rra\n") || ft_strcmp(op, "rrb\n"))
				&& (print_op_rr(&curr)))
				changed = 1;
			curr = curr->next;
		}
		changed = changed || rem_dups(ps->out);
	}
	curr = ps->out;
	while (curr)
	{
		ft_putstr_fd(curr->content, 1);
		curr = curr->next;
	}
	ft_lstclear(&(ps->out), ft_free);
}
