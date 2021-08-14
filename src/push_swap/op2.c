/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 02:06:19 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 15:55:11 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include "push_swap.h"

static int	check_rev(char *a, char *b)
{
	return ((ft_strcmp(a, "ra\n") && ft_strcmp(b, "rra\n"))
		|| (ft_strcmp(a, "rra\n") && ft_strcmp(b, "ra\n"))
		|| (ft_strcmp(a, "rb\n") && ft_strcmp(b, "rrb\n"))
		|| (ft_strcmp(a, "rrb\n") && ft_strcmp(b, "rb\n"))
		|| (ft_strcmp(a, "rr\n") && ft_strcmp(b, "rrr\n"))
		|| (ft_strcmp(a, "rrr\n") && ft_strcmp(b, "rr\n"))
		|| (ft_strcmp(a, "pa\n") && ft_strcmp(b, "pb\n"))
		|| (ft_strcmp(a, "pb\n") && ft_strcmp(b, "pa\n")));
}

int	rem_dups(t_list *l)
{
	t_list	*curr;
	t_list	*tmp;
	int		ret;

	ret = 0;
	curr = l;
	while (curr && curr->next)
	{
		if (((char *)curr->next->content)[0] != 's')
		{
			tmp = curr->next;
			while (tmp->next
				&& ft_strcmp(tmp->next->content, curr->next->content))
				tmp = tmp->next;
			if (tmp->next && check_rev(curr->next->content, tmp->next->content))
			{
				ret = 1;
				rem_next(tmp);
				rem_next(curr);
			}
		}
		curr = curr->next;
	}
	return (ret);
}
