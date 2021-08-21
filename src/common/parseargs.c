/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 01:28:21 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/21 19:10:39 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_string.h"
#include "ft_stdlib.h"
#include "ft_ctype.h"
#include "actions.h"
#include "common.h"

static int	check_int(const char *n)
{
	int	count;

	count = -1;
	if (*n == '-')
		count++;
	while (n[++count])
		if (!ft_isdigit(*(n + count)))
			return (0);
	if (count == 1 && n[0] == '-')
		return (0);
	if (n[0] == '-' && (ft_strlen(n) > 11 || (ft_strlen(n) == 11
				&& ft_memcmp(n, "-2147483648", 11) > 0)))
		return (0);
	if (n[0] != '-' && ((ft_strlen(n) == 10
				&& ft_memcmp(n, "2147483647", 11) > 0) || ft_strlen(n) > 10))
		return (0);
	return (1);
}

static int	check_dups(t_ps *ps)
{
	int	*arr;
	int i;

	arr = stack_to_array(ps->a, ps->a->size);
	quicksorti(arr, 0, ps->a->size - 1);
	i = -1;
	while (++i < (int) ps->a->size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			i = -1;
			break;
		}
	}
	ft_free(arr);
	return (i != -1);
}

t_ps	*parseArgs(int argc, const char *argv[])
{
	t_ps		*ret;
	t_content	tmp;

	ret = ft_malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stacknew();
	ret->b = ft_stacknew();
	ret->bs = NULL;
	ret->as = NULL;
	while (argc--)
	{
		if (!check_int(argv[argc]))
		{
			ft_stackdestroy(ret->b, NULL);
			ft_stackdestroy(ret->a, NULL);
			ft_free(ret);
			return (NULL);
		}
		tmp.i = ft_atoi(argv[argc]);
		ft_stackpush(ret->a, tmp);
	}
	if (!check_dups(ret))
	{
		destroy_ps(ret);
		return (NULL);
	}
	return (ret);
}

t_ps	*parseString(const char *s)
{
	t_ps	*ret;
	char	**nums;
	int		count;

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
