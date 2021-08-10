/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:49:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:14:34 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	rrr(t_ps *ps)
{
	rra(ps);
	rrb(ps);
}

void	print_rrr(t_ps *ps)
{
	ft_putstr_fd("rrr\n", STDOUT);
	rrr(ps);
}

void	push_rrr(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("rrr");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	ft_lstadd_back(&(ps->out), str);
	rrr(ps);
}
