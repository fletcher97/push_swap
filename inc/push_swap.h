/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:34:15 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 16:43:54 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "actions.h"

# define MED_MARGIN 20

typedef struct s_fucknorm
{
	int	u;
	int	d;
}				t_fucknorm;

void	bring_up(t_ps *ps, int sizea, int sizeb);
void	sswap(t_ps *ps, int sizea, int sizeb);
void	rem_next(t_list *l);
void	replace_content(t_list *l, char *str);
void	print_list(t_list *curr);

void	execute_small(t_ps *ps);
void	execute_med(t_ps *ps);
void	execute_big(t_ps *ps);

void	optimize(t_ps *ps);
int		rem_dups(t_list *l);

#endif
