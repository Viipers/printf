/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:00:18 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/15 15:01:24 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	print_content(char *str, va_list ap)
{
	t_set *param;

	if (!(param = malloc(sizeof(t_set))))
		return (0);
	param->i = 0;
	param->n = 0;
	param->nbchar_output = 0;
	param->zero = 0;
	param->af_point = -1;
	while (str[param->i])
	{
		if (str[param->i] == '%')
		{
			trim_param(str, param, ap);
		}
		else
		{
			ft_putchar_count(str[param->i], param);
		}
		param->i++;
	}
	return (param->n);
}

int ft_printf(const char *content, ...)
{
	char *str;
	int nb_char;

	if (content == NULL)
		return (0);
	str = ft_strdup(content);
	va_list ap;

	va_start(ap, content);

	nb_char = print_content(str, ap);

	free(str);
	va_end(ap);
	return (nb_char);
}

