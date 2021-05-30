/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 00:47:15 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	sb(t_ps *ps)
{
	void	*tmp1;
	void	*tmp2;

	if (ps->a->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->b);
	tmp2 = ft_stackpop(ps->b);
	ft_stackpush(ps->b, tmp1);
	ft_stackpush(ps->b, tmp2);
}
