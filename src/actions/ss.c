/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:14:48 by mgueifao         ###   ########.fr       */
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

void	push_ss(t_ps *ps)
{
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("ss");
	if (!str->content)
	{
		free(str);
		return ;
	}
	ft_lstadd_back(&(ps->out), str);
	ss(ps);
}
