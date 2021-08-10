/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:49:47 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:13:06 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_stack.h"

#include "actions.h"

void	rb(t_ps *ps)
{
	t_stack_elem	*tmp;
	t_stack_elem	*curr;

	if (ps->b->size < 2)
		return ;
	tmp = ps->b->top;
	ps->b->top = ps->b->top->prev;
	tmp->prev = NULL;
	curr = ps->b->top;
	while (curr->prev)
		curr = curr->prev;
	curr->prev = tmp;
}

void	print_rb(t_ps *ps)
{
	ft_putstr_fd("rb\n", STDOUT);
	rb(ps);
}

void	push_rb(t_ps *ps)
{
	t_list	*str;

	str = ft_malloc(sizeof(t_list));
	if (!str)
		return ;
	str->content = ft_strdup("rb\n");
	if (!str->content)
	{
		ft_free(str);
		return ;
	}
	str->next = NULL;
	ft_lstadd_back(&(ps->out), str);
	rb(ps);
}
