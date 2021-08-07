/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:06:55 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/07 16:53:15 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_stack.h"
#include "push_swap.h"
#include "common.h"

static int	get_ops(t_ps *ps, int i, t_stack *out)
{
	int ac;
	t_content aux;

	if (i == 0 && ps->b->size == 0 && sorts(ps, out))
		return (1);
	else if (i == 0)
		return (0);
	ac = -1;
	while (++ac < 9)
	{
		aux.str = get_action(ac);
		ft_stackpush(out, aux);
		if (get_ops(ps, i - 1, out))
			return (1);
		aux = ft_stackpop(out);
		free(aux.str);
	}
	return (0);
}

char	*to_str(t_content cont)
{
	return (cont.str);
}

void	free_cont(t_content cont)
{
	free(cont.str);
}

void execute_small(t_ps *ps)
{
	int found;
	t_stack *out;
	int i;

	if (issorted(ps->a))
		return ;
	found = 0;
	i = -1;
	out = ft_stacknew();
	while (!found)
	{
		i++;
		found = get_ops(ps, i, out);
	}
	ft_stackprint(out, to_str, "\n");
	ft_stackdestroy(out, free_cont);
}
