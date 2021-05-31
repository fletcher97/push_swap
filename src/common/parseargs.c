/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 01:28:21 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 01:35:40 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_stdlib.h"
#include "actions.h"

t_ps	*parseArgs(int argc, const char *argv[])
{
	t_ps	*ret;
	long	tmp;
	int		count;

	ret = ft_malloc(sizeof(t_ps));
	if (!ret)
		return (NULL);
	ret->a = ft_stacknew();
	ret->b = ft_stacknew();
	while (argc--)
	{
		count = -1;
		while (argv[argc][++count])
			if (argv[argc][count] != ' ' && (argv[argc][count] < '0' ||
				argv[argc][count] > '9'))
				return (NULL);
		tmp = ft_atoi(argv[argc]);
		ft_stackpush(ret->a, (void *)tmp);
	}
	return (ret);
}

t_ps	*parseString(const char *s)
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
