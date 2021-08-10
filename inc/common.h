/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 23:50:11 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/08 19:16:42 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "ft_stack.h"
# include "actions.h"

char	issorted(t_stack *s);
t_ps	*parseString(const char *s);
t_ps	*parseArgs(int argc, const char *argv[]);
int		get_median(t_stack *s, int size);
t_ps	*dup_ps(t_ps *ps);
void	destroy_ps(t_ps *ps);
int		sorts(t_ps *ps, t_stack *ops);
int		get_val_at_sorted(t_stack *s, int pos);
int		get_median2(t_stack *s, int size, int big);

#endif
