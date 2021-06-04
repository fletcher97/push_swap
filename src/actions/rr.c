/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:49:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:25:39 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "actions.h"

void	rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
}

void print_rr(t_ps *ps)
{
	ft_putstr_fd("rr\n", STDOUT);
	rr(ps);
}
