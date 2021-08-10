/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 06:02:03 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:13:25 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"

#include "actions.h"

void	rra(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

	if (ps->a->size < 2)
		return ;
	curr = ps->a->top;
	while (curr->prev->prev)
		curr = curr->prev;
	tmp = curr->prev;
	curr->prev = NULL;
	tmp->prev = ps->a->top;
	ps->a->top = tmp;
}

void	print_rra(t_ps *ps)
{
	ft_putstr_fd("rra\n", STDOUT);
	rra(ps);
}

void	push_rra(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("rra");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	ft_lstadd_back(&(ps->out), str);
	rra(ps);
}
