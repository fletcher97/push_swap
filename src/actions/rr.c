/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:49:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:13:04 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
}

void	print_rr(t_ps *ps)
{
	ft_putstr_fd("rr\n", STDOUT);
	rr(ps);
}

void	push_rr(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("rr");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	ft_lstadd_back(&(ps->out), str);
	rr(ps);
}
