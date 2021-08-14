/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:07:09 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 16:39:37 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_norm.h"

#include "push_swap.h"
#include "common.h"

static void	pusha(t_ps *ps)
{
	int			size;
	int			count;
	int			med;
	t_content	pushed;

	size = ft_stackpop(ps->bs).i;
	count = -1;
	pushed.i = 0;
	med = get_median(ps->b, size);
	while (++count != ft_abs(size))
	{
		if (size < 0)
			push_rrb(ps);
		if (ft_stackpeek(ps->b).i > med)
			pushed.i++;
		if (ft_stackpeek(ps->b).i > med)
			push_pa(ps);
		else if (size > 0)
			push_rb(ps);
	}
	ft_stackpush(ps->as, pushed);
	pushed.i = count - pushed.i;
	if (size > 0 && pushed.i < (int)ps->b->size)
		pushed.i = pushed.i * -1;
	ft_stackpush(ps->bs, pushed);
}

static void	set_pushed(t_ps *ps, t_fucknorm fn, int size, int flag)
{
	t_content	u;
	t_content	d;
	t_content	left;
	t_stack		*s;

	u.i = fn.u;
	d.i = fn.d * -1;
	left.i = ft_abs(size) - (u.i + d.i);
	if (size > 0 && left.i < (int)ps->a->size)
		left.i = left.i * -1;
	s = ps->as;
	if (flag)
		s = ps->bs;
	if (d.i)
		ft_stackpush(s, d);
	if (u.i)
		ft_stackpush(s, u);
	if (left.i)
		ft_stackpush(s, left);
}

static void	pushb(t_ps *ps, int size, int size2)
{
	int			med;
	int			mm;
	t_fucknorm	fn;

	med = get_median(ps->a, size);
	mm = get_median2(ps->a, size, 0);
	fn.d = 0;
	fn.u = 0;
	while (size)
	{
		if (size < 0)
			push_rra(ps);
		if (ft_stackpeek(ps->a).i <= med && ++fn.u)
		{
			push_pb(ps);
			if (ft_stackpeek(ps->b).i < mm && ++fn.d && (--fn.u || !fn.u))
				push_rb(ps);
		}
		else if (size > 0)
			push_ra(ps);
		if (--size < 0)
			size += 2;
	}
	set_pushed(ps, fn, size2, 1);
}

static void	sort(t_ps *ps)
{
	int	sizea;
	int	sizeb;
	int	size;

	if (ps->as->size > 1)
	{
		size = ft_stackpop(ps->as).i;
		return (pushb(ps, size, size));
	}
	if (ft_stacksize(ps->as) > 0 && ft_abs(ft_stackpeek(ps->as).i) <= 2)
		sizea = ft_stackpop(ps->as).i;
	else
		sizea = 10;
	if (ft_stacksize(ps->bs) > 0 && ft_abs(ft_stackpeek(ps->bs).i) <= 2)
		sizeb = ft_stackpop(ps->bs).i;
	else
		sizeb = 10;
	bring_up(ps, sizea, sizeb);
	sswap(ps, sizea, sizeb);
	if (ft_abs(sizeb) >= 1)
		push_pa(ps);
	if (ft_abs(sizeb) == 2)
		push_pa(ps);
}

void	execute_big(t_ps *ps)
{
	static int	flag = 0;
	int			size;

	if (ps->bs->size == 0 && issorted(ps->a))
		return (optimize(ps));
	if ((ps->as->size && ft_abs(ft_stackpeek(ps->as).i) <= 2)
		|| (ps->bs->size && ft_abs(ft_stackpeek(ps->bs).i) <= 2
			&& (!ps->as->size || ft_abs(ft_stackpeek(ps->as).i) <= 2)))
		sort(ps);
	else if (ft_stacksize(ps->as) > 0)
	{
		size = ft_stackpop(ps->as).i;
		size = ft_ternary32(!flag, ft_abs(size), size);
		pushb(ps, size, size);
	}
	else if (ft_stacksize(ps->bs) > 0)
	{
		flag = 1;
		pusha(ps);
	}
	execute_big(ps);
}
