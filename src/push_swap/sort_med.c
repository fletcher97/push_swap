/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_med.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:07:05 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/08 18:34:00 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "actions.h"
#include "common.h"
#include "push_swap.h"

static void pushb(t_ps *ps, int sorting, int flag)
{
	int med;
	int split;

	if (!flag)
	{
		split = get_val_at_sorted(ps->a, ps->a->size / 4 + ps->a->size / 2);
		while (sorting--)
		{
			print_pb(ps);
			if (ft_stackpeek(ps->b).i <= split)
				print_rb(ps);
		}
	}
	else
	{
		split = get_val_at_sorted(ps->a, ps->a->size / 4);
		med = get_median(ps->a, ps->a->size);
		while (sorting)
		{
			if (ft_stackpeek(ps->a).i <= med)
			{
				sorting--;
				print_pb(ps);
				if (ft_stackpeek(ps->b).i >= split)
					print_rb(ps);
			}
			else
				print_ra(ps);
		}
	}
}

typedef struct s_fucknorm
{
	int min;
	int max;
	int min_pos;
	int max_pos;
}				t_fucknorm;

static int	best_move2(t_fucknorm fn, int size)
{
	int min_c;
	int max_c;
	int c;

	if (size == 1)
		return (0);
	min_c = fn.min_pos;
	if (fn.min_pos > ft_abs(fn.min_pos - size))
		max_c = fn.min_pos - size;
	max_c = fn.max_pos;
	if (fn.min_pos > ft_abs(fn.max_pos - size))
		min_c = fn.max_pos - size;
	c = min_c;
	if (ft_abs(min_c) > ft_abs(max_c))
		c = max_c;
	return (c);
}

static int	best_move(t_ps *ps)
{
	t_stack_elem *curr;
	t_fucknorm fn;
	int curr_pos;

	fn.min_pos = 0;
	fn.max_pos = 0;
	curr = ps->b->top;
	fn.max = curr->cont.i;
	fn.min = fn.max;
	curr = curr->prev;
	curr_pos = 1;
	while (curr)
	{
		if (curr->cont.i > fn.max)
			fn.max_pos = curr_pos;
		if (curr->cont.i > fn.max)
			fn.max = curr->cont.i;
		if (curr->cont.i < fn.min)
			fn.min_pos = curr_pos;
		if (curr->cont.i < fn.min)
			fn.min = curr->cont.i;
		curr = curr->prev;
		curr_pos++;
	}
	return (best_move2(fn, curr_pos));
}

static void	pusha(t_ps *ps, int left)
{
	int mov;

	if (ps->b->size == 0)
		while (left--)
			print_ra(ps);
	if (ps->b->size == 0)
		return ;
	mov = best_move(ps);
	if (mov < 0)
		while (mov++)
			print_rrb(ps);
	else
		while (mov--)
			print_rb(ps);
	print_pa(ps);
	if (ps->b->size && ps->a->top->cont.i > ps->b->top->cont.i)
		return pusha(ps, left + 1);
	print_ra(ps);
	pusha(ps, left);
}

void execute_med(t_ps *ps)
{
	// while (left)
	// {
	// 	sorting = ft_min(left, MED_MARGIN);
	// 	left -= sorting;
	// 	// pushb(ps, sorting);
	// }
	pushb(ps, ps->a->size / 2, 1);
	pusha(ps, 0);
	pushb(ps, ps->a->size - ps->a->size / 2, 0);
	pusha(ps, 0);
}
