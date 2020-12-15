/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:02:07 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/15 18:19:53 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	arg_char(va_list ap, t_set *param)
{
	char value;

	value = (char)va_arg(ap, int);
	ft_putchar_count(value , param);
}

void	arg_string(va_list ap, t_set *param)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr_count(str, param);
}
