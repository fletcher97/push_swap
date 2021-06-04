/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:44:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:22:17 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

#include "actions.h"

void	pb(t_ps *ps)
{
	if (ps->a->size < 1)
		return ;
	ft_stackpush(ps->b, ft_stackpop(ps->a));
}

void print_pb(t_ps *ps)
{
	ft_putstr_fd("pb\n", STDOUT);
	pb(ps);
}
