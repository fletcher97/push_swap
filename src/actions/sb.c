/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 15:34:22 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	sb(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	if (ps->b->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->b);
	tmp2 = ft_stackpop(ps->b);
	ft_stackpush(ps->b, tmp1);
	ft_stackpush(ps->b, tmp2);
}

void	print_sb(t_ps *ps)
{
	ft_putstr_fd("sb\n", STDOUT);
	sb(ps);
}

void	push_sb(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("sb\n");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	str->next = NULL;
	ft_lstadd_back(&(ps->out), str);
	sb(ps);
}
