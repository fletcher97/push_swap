/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:58:54 by mgueifao          #+#    #+#             */
/*   Updated: 2021/06/06 08:02:36 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sort.h"
#include "ft_stdlib.h"
#include "ft_stack.h"

static int	*stack_to_array_bot(t_stack *s, int size)
{
	int	*ret;
	t_stack_elem *curr;
	int	i;

	ret = ft_malloc(sizeof(int) * size);
	curr = s->top;
	i = 0;
	while (curr)
	{
		ret[i % size] = curr->cont.i;
		curr = curr->prev;
		i++;
	}
	return (ret);
}

static int	*stack_to_array(t_stack *s, int size)
{
	int	*ret;
	t_stack_elem *curr;
	int	i;

	ret = ft_malloc(sizeof(int) * size);
	curr = s->top;
	i = 0;
	while (i < size)
	{
		ret[i++] = curr->cont.i;
		curr = curr->prev;
	}
	return (ret);
}

int	get_median(t_stack *s, int size)
{
	int *arr;
	int ret;

	if (size > 0)
		arr = stack_to_array(s, size);
	else
		arr = stack_to_array_bot(s, size * -1);
	size = ft_abs(size);
	quicksorti(arr, 0, size - 1);
	if (!(size % 2))
		ret = ((arr[(size / 2) - 1] + arr[size / 2]) / 2);
	else
		ret = arr[size / 2];
	ft_free(arr);
	return (ret);
}
