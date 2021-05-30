/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:36:59 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 00:47:10 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	sa(t_ps *ps)
{
	void	*tmp1;
	void	*tmp2;

	if (ps->a->size < 2)
		return ;
	tmp1 = ft_stackpop(ps->a);
	tmp2 = ft_stackpop(ps->a);
	ft_stackpush(ps->a, tmp1);
	ft_stackpush(ps->a, tmp2);
}
