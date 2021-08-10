/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:04:11 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:17:00 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_string.h"

#include "actions.h"

void	print_op_p(t_list **l)
{
	char	*op;

	if (!(*l)->next)
		return ft_putstr_fd((*l)->content, 1);
	if (ft_strcmp((*l)->content, "pa\n"))
	{
		op = (char *)(*l)->next->content;
		if (!ft_strcmp(op, "rrb\n") || !(*l)->next->next)
			return ft_putstr_fd("pa\n", 1);
		op = (char *)(*l)->next->next->content;
		if (!ft_strcmp(op, "pb\n"))
			return ft_putstr_fd("pa\n", 1);
		ft_putstr_fd("rrb\nsb\n", 1);
		*l = (*l)->next->next;
		return ;
	}
	op = (char *)(*l)->next->content;
	if (!ft_strcmp(op, "rra\n") || !(*l)->next->next)
		return ft_putstr_fd("pb\n", 1);
	op = (char *)(*l)->next->next->content;
	if (!ft_strcmp(op, "pa\n"))
		return ft_putstr_fd("pb\n", 1);
	ft_putstr_fd("rra\nsa\n", 1);
	*l = (*l)->next->next;
}

void	print_op_r(t_list **l)
{
	t_list	*curr;

	curr = (*l)->next;
	while (curr && (ft_strcmp(curr->content, (*l)->content)
		|| ft_strcmp(curr->content, "")))
		curr = curr->next;
	if (!(*l)->next)
		return ft_putstr_fd((*l)->content, 1);
	if ((ft_strcmp((*l)->content, "ra\n") && ft_strcmp(curr->content, "rb\n"))
		|| (ft_strcmp((*l)->content, "rb\n")
		&& ft_strcmp(curr->content, "ra\n")))
	{
		ft_putstr_fd("rr\n", 1);
		ft_free(curr->content);
		curr->content = ft_strdup("");
		*l = (*l)->next;
		return ;
	}
	ft_putstr_fd((*l)->content, 1);
}

void	optimize(t_ps *ps)
{
	t_list	*curr;
	char	*op;

	curr = ps->out;
	while (curr)
	{
		op = curr->content;
		if (ft_strcmp(op, "pa\n") || ft_strcmp(op, "pb\n"))
			print_op_p(&curr);
		else if (ft_strcmp(op, "ra\n") || ft_strcmp(op, "rb\n"))
			print_op_r(&curr);
		else
			ft_putstr_fd(op, 1);
		curr = curr->next;
	}
}
