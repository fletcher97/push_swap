/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:44:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:22:12 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

#include "actions.h"

void	pa(t_ps *ps)
{
	if (ps->b->size < 1)
		return ;
	ft_stackpush(ps->a, ft_stackpop(ps->b));
}

void print_pa(t_ps *ps)
{
	ft_putstr_fd("pa\n", STDOUT);
	pa(ps);
}
