/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 05:32:17 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/14 16:43:32 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "ft_stack.h"
# include "ft_list.h"

typedef struct s_ps
{
	t_stack	*as;
	t_stack	*bs;
	t_stack	*a;
	t_stack	*b;
	t_list	*out;
}	t_ps;

void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);

void	print_pa(t_ps *ps);
void	print_pb(t_ps *ps);
void	print_ra(t_ps *ps);
void	print_rb(t_ps *ps);
void	print_rr(t_ps *ps);
void	print_rra(t_ps *ps);
void	print_rrb(t_ps *ps);
void	print_rrr(t_ps *ps);
void	print_sa(t_ps *ps);
void	print_sb(t_ps *ps);
void	print_ss(t_ps *ps);

void	push_pa(t_ps *ps);
void	push_pb(t_ps *ps);
void	push_ra(t_ps *ps);
void	push_rb(t_ps *ps);
void	push_rr(t_ps *ps);
void	push_rra(t_ps *ps);
void	push_rrb(t_ps *ps);
void	push_rrr(t_ps *ps);
void	push_sa(t_ps *ps);
void	push_sb(t_ps *ps);
void	push_ss(t_ps *ps);

char	*get_action(int i);

#endif
