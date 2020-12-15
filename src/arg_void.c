/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_void.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:51:17 by tsannie           #+#    #+#             */
/*   Updated: 2020/11/30 18:35:10 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_percent(t_set *param)
{
	ft_putchar_count('%', param);
}

void	arg_void(va_list ap, t_set *param)
{
	unsigned long value;

	value = (unsigned long)va_arg(ap, void *);
	ft_putultoh_count(value, param);
}
