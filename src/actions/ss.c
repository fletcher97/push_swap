/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 10:26:08 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

#include "actions.h"

void	ss(t_ps *ps)
{
	sa(ps);
	sb(ps);
}

void print_ss(t_ps *ps)
{
	ft_putstr_fd("ss\n", STDOUT);
	ss(ps);
}
