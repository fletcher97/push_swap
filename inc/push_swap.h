/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:34:15 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/06 10:55:24 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "actions.h"

void bring_up(t_ps *ps, int sizea, int sizeb);
void sswap(t_ps *ps, int sizea, int sizeb);

void execute_small(t_ps *ps);
void execute_med(t_ps *ps);
void execute_big(t_ps *ps);

#endif
