/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 08:27:51 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/07 17:18:14 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_stdlib.h"
#include "ft_stack.h"
#include "push_swap.h"
#include "common.h"

static void pick(t_ps *ps)
{
	if (ps->a->size <= 5)
		execute_small(ps);
	else if (ps->a->size <= 100)
		execute_med(ps);
	else
		execute_big(ps);
}

int	main(int argc, const char *argv[])
{
	t_ps		*ps;
	t_content	cont;

	if (argc < 2)
		return (0);
	if (argc == 2)
		ps = parseString(argv[1]);
	else
		ps = parseArgs(argc - 1, &(argv[1]));
	if (!ps)
		ft_putstr_fd("Error\n", STDERR);
	if (!ps)
		return (1);
	ps->as = ft_stacknew();
	ps->bs = ft_stacknew();
	cont.i = ps->a->size;
	ft_stackpush(ps->as, cont);
	pick(ps);
	ft_stackdestroy(ps->a, NULL);
	ft_stackdestroy(ps->b, NULL);
	ft_stackdestroy(ps->as, NULL);
	ft_stackdestroy(ps->bs, NULL);
	ft_free(ps);
	return (0);
}
