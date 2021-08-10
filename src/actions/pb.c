/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:44:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:13:08 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	pb(t_ps *ps)
{
	if (ps->a->size < 1)
		return ;
	ft_stackpush(ps->b, ft_stackpop(ps->a));
}

void	print_pb(t_ps *ps)
{
	ft_putstr_fd("pb\n", STDOUT);
	pb(ps);
}

void	push_pb(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("pb\n");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	str->next = NULL;
	ft_lstadd_back(&(ps->out), str);
	pb(ps);
}
