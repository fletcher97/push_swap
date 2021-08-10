/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:07:09 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:03:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_norm.h"

#include "push_swap.h"
#include "common.h"

static void pusha(t_ps *ps)
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

// static void pushb(t_ps *ps, int size)
// {
// 	int			count;
// 	int			med;
// 	t_content	pushed;
// 	// t_content	pusheddown;

// 	count = -1;
// 	pushed.i = 0;
// 	med = get_median(ps->a, size);
// 	while (++count != ft_abs(size))
// 	{
// 		if (size < 0)
// 			push_rra(ps);
// 		if (ft_stackpeek(ps->a).i <= med)
// 			pushed.i++;
// 		if (ft_stackpeek(ps->a).i <= med)
// 			push_pb(ps);
// 		else if (size > 0)
// 			push_ra(ps);
// 	}
// 	ft_stackpush(ps->bs, pushed);
// 	pushed.i = count - pushed.i;
// 	if (size > 0 && pushed.i < (int)ps->a->size)
// 		pushed.i = pushed.i * -1;
// 	ft_stackpush(ps->as, pushed);
// }

static void	set_pushed(t_ps *ps, int up, int down, int size, int flag)
{
	t_content	u;
	t_content	d;
	t_content	left;

	u.i = up;
	d.i = down * -1;
	left.i = ft_abs(size) - (up + down);
	if (size > 0 && left.i < (int)ps->a->size)
		left.i = left.i * -1;
	if (flag)
	{
		if (d.i)
			ft_stackpush(ps->bs, d);
		if (u.i)
			ft_stackpush(ps->bs, u);
		if (left.i)
			ft_stackpush(ps->as, left);
		return ;
	}
	if (d.i)
		ft_stackpush(ps->as, d);
	if (u.i)
		ft_stackpush(ps->as, u);
	if (left.i)
		ft_stackpush(ps->bs, left);

}

// static void	pusha(t_ps *ps, int size, int size2)
// {
// 	int med;
// 	int mm;
// 	int up;
// 	int down;

// 	med = get_median(ps->b, size);
// 	mm = get_median2(ps->b, size, 1);
// 	down = 0;
// 	up = 0;
// 	while (size)
// 	{
// 		if (size < 0)
// 			push_rrb(ps);
// 		if (ft_stackpeek(ps->b).i > med)
// 		{
// 			push_pa(ps);
// 			if (ft_stackpeek(ps->a).i >= mm && ++down)
// 				push_ra(ps);
// 			else
// 				up++;
// 		}
// 		else if (size > 0)
// 			push_rb(ps);
// 		size--;
// 		if (size < 0)
// 			size += 2;
// 	}
// 	set_pushed(ps, up, down, size2, 0);
// }

static void	pushb(t_ps *ps, int size, int size2)
{
	int med;
	int mm;
	int up;
	int down;

	med = get_median(ps->a, size);
	mm = get_median2(ps->a, size, 0);
	down = 0;
	up = 0;
	while (size)
	{
		if (size < 0)
			push_rra(ps);
		if (ft_stackpeek(ps->a).i <= med)
		{
			push_pb(ps);
			if (ft_stackpeek(ps->b).i < mm && ++down)
				push_rb(ps);
			else
				up++;
		}
		else if (size > 0)
			push_ra(ps);
		size--;
		if (size < 0)
			size += 2;
	}
	set_pushed(ps, up, down, size2, 1);
}

static void    sort(t_ps *ps)
{
	int	sizea;
	int	sizeb;
	int size;

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
	// can be optimized by checking >= 1 first
	if (ft_abs(sizeb) == 2)
		push_pa(ps);
	if (ft_abs(sizeb) == 2)
		push_pa(ps);
	if (ft_abs(sizeb) == 1)
		push_pa(ps);
}

// void sp(t_stack *s)
// {
// 	t_stack_elem	*ele;

// 	if (!s || !s->top)
// 		return ;
// 	ele = s->top;
// 	ft_putnbr_fd(ele->cont.i, 1);
// 	while (ele->prev)
// 	{
// 		ele = ele->prev;
// 		ft_putstr_fd("->", 1);
// 		ft_putnbr_fd(ele->cont.i, 1);
// 	}
// 	ft_putstr_fd("\n\n", 1);
// }

#include "unistd.h"
void	execute_big(t_ps *ps)
{
	static int	flag = 0;
	int			size;

	// char buff[5];
	// read(0, &buff, 1);
	if (ps->bs->size == 0 && issorted(ps->a))
		return (optimize(ps));
	if ((ps->as->size && ft_abs(ft_stackpeek(ps->as).i) <= 2)
		|| (ps->bs->size && ft_abs(ft_stackpeek(ps->bs).i) <= 2 && (!ps->as->size || ft_abs(ft_stackpeek(ps->as).i) <= 2)))
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
	// ft_putstr_fd("a:\n", 1);
	// sp(ps->a);
	// ft_putstr_fd("as:\n", 1);
	// sp(ps->as);
	// ft_putstr_fd("b:\n", 1);
	// sp(ps->b);
	// ft_putstr_fd("bs:\n", 1);
	// sp(ps->bs);
	execute_big(ps);
}
