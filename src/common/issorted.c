/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 07:46:06 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/30 09:34:29 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

char issorted(t_stack *s)
{
	long tmp;
	t_stack_elem *curr;

	curr = s->top;
	if (curr)
		tmp = (long)curr->content;
	while(curr->prev)
	{
		if (tmp > (long)curr->prev->content)
			return (0);
		curr = curr->prev;
		tmp = (long)curr->content;
	}
	return (1);
}
