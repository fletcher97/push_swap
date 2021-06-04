/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:23:31 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

#include "actions.h"

void	sb(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	if (ps->a->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->b);
	tmp2 = ft_stackpop(ps->b);
	ft_stackpush(ps->b, tmp1);
	ft_stackpush(ps->b, tmp2);
}

void print_sb(t_ps *ps)
{
	ft_putstr_fd("sb\n", STDOUT);
	sb(ps);
}
