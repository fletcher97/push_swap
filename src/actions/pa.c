/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:44:28 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:13:09 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	pa(t_ps *ps)
{
	if (ps->b->size < 1)
		return ;
	ft_stackpush(ps->a, ft_stackpop(ps->b));
}

void	print_pa(t_ps *ps)
{
	ft_putstr_fd("pa\n", STDOUT);
	pa(ps);
}

void	push_pa(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("pa");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	ft_lstadd_back(&(ps->out), str);
	pa(ps);
}
