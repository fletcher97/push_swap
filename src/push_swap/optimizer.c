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

#include "ft_stdio.h"
#include "ft_string.h"

#include "actions.h"

void	print_op_pa(t_list **l)
{
	char	*op;

	if (!(*l)->next)
		return ft_putstr_fd("pa", 1);
	op = (char *)(*l)->next->content;
	if (ft_strcmp(op, "rrb") || !(*l)->next->next)
		return ft_putstr_fd("pa", 1);
	op = (char *)(*l)->next->next->content;
	if (ft_strcmp(op, "pb"))
		return ft_putstr_fd("pa", 1);
	ft_putstr_fd("rrb", 1);
	ft_putstr_fd("sb", 1);
	*l = (*l)->next->next;
}

void	optimize(t_ps *ps)
{
	t_list	*curr;
	char	*op;

	curr = ps->out;
	while (curr)
	{
		op = curr->content;
		if (!ft_strcmp(op, "pa"))
			print_op_pa(&curr);
		else
			ft_putstr_fd(op, 1);
		curr = curr->next;
	}
}
