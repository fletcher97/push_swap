/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 00:04:11 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/09 00:17:00 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	optimize(t_ps *ps)
{
	t_list	*curr;

	curr = ps->out;
	while (curr)
	{
		if (curr->content == "pa")
			check_pa(curr, ps);
	}
}
