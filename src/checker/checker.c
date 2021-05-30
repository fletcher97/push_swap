/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:16:03 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 00:47:49 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_conv.h"
#include "ft_stdlib.h"
#include "ft_stdio.h"
#include "ft_stack.h"
#include "ft_string.h"
#include "actions.h"
#include "checker.h"

static t_ps	*parseArgs(int argc, const char *argv[])
{
	t_ps	*ret;
	long	tmp;

	ret = ft_malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stacknew();
	ret->b = ft_stacknew();
	while (argc)
	{
		tmp = ft_atoi(argv[--argc]);
		ft_stackpush(ret->a, (void *)tmp);
	}
	return (ret);
}

static t_ps	*parseString(const char *s)
{
	t_ps	*ret;
	char	**nums;
	int		count;

	count = -1;
	while (s[++count])
		if (s[count] != ' ' && (s[count] < '0' || s[count] > '9'))
			return (NULL);
	nums = ft_split(s, ' ');
	count = 0;
	while (nums[count])
		count++;
	ret = parseArgs(count, (const char **)nums);
	count = 0;
	while (nums[count])
		ft_free(nums[count++]);
	ft_free(nums);
	return (ret);
}

int	run(char *op, t_ps *ps)
{
	if (ft_strcmp(op, "sa"))
		sa(ps);
	else if (ft_strcmp(op, "sb"))
		sb(ps);
	else if (ft_strcmp(op, "ss"))
		ss(ps);
	else if (ft_strcmp(op, "pa"))
		pa(ps);
	else if (ft_strcmp(op, "pb"))
		pb(ps);
	else if (ft_strcmp(op, "ra"))
		ra(ps);
	else if (ft_strcmp(op, "rb"))
		rb(ps);
	else if (ft_strcmp(op, "rr"))
		rr(ps);
	else if (ft_strcmp(op, "rra"))
		rra(ps);
	else if (ft_strcmp(op, "rrb"))
		rrb(ps);
	else if (ft_strcmp(op, "rrr"))
		rrr(ps);
	else
		return (1);
	return (0);
}

int	execute(t_ps *ps)
{
	char	*op;
	int		err;

	while (get_next_line(STDIN, &op))
	{
		err = run(op, ps);
		ft_free(op);
		if (err)
			return (1);
	}
	ft_free(op);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_ps	*ps;
	int		err;

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
	err = execute(ps);
	if (err)
		ft_putstr_fd("Error\n", STDERR);
	else if (!ps->b->size && issorted(ps->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_stackprint(ps->a, NULL, "->");
	ft_stackdestroy(ps->a, NULL);
	ft_stackdestroy(ps->b, NULL);
	ft_free(ps);
	return (0);
}
