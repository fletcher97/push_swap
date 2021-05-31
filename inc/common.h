/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 23:50:11 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 01:29:59 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "ft_stack.h"

char	issorted(t_stack *s);
t_ps	*parseString(const char *s);
t_ps	*parseArgs(int argc, const char *argv[]);

#endif
