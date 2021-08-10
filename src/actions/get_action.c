/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:16:44 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/07 17:42:34 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "ft_string.h"

char	*get_action(int i)
{
	static char	*ops[] = A;
	return ft_strdup(ops[i]);
}
