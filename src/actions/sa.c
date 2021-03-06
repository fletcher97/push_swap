/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:14:14 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	sa(t_ps *ps)
{
	t_content	tmp1;
	t_content	tmp2;

	if (ps->a->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->a);
	tmp2 = ft_stackpop(ps->a);
	ft_stackpush(ps->a, tmp1);
	ft_stackpush(ps->a, tmp2);
}

void	print_sa(t_ps *ps)
{
	ft_putstr_fd("sa\n", STDOUT);
	sa(ps);
}

void	push_sa(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("sa\n");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	str->next = NULL;
	ft_lstadd_back(&(ps->out), str);
	sa(ps);
}
