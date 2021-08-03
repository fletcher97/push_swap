/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 07:46:06 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/04 07:51:51 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

char issorted(t_stack *s)
{
	t_content tmp;
	t_stack_elem *curr;

	curr = s->top;
	if (curr)
		tmp = curr->cont;
	while(curr->prev)
	{
		if (tmp.i > curr->prev->cont.i)
			return (0);
		curr = curr->prev;
		tmp = curr->cont;
	}
	return (1);
}
