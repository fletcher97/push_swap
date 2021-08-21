/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:06:03 by mgueifao          #+#    #+#             */
/*   Updated: 2021/08/21 21:06:04 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*__asan_default_options(void)
{
	return ("\
		strict_string_checks=1\
		detect_stack_use_after_return=1:\
		check_initialization_order=1:\
		strict_init_order=1:\
		detect_invalid_pointer_pairs=9:\
		halt_on_error=false:\
		detect_leaks=1:\
		use_unaligned=1");
}
