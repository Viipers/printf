/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_count2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 21:37:12 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/19 21:37:47 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	put_space(int glob, int a, t_set *param)
{
	int b;

	b = 0;
	while (b < (glob - a))
	{
		if (param->zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		param->n++;
		param->nbchar_output++;
		b++;
	}
}

void	ft_putchar_count(char c, t_set *param)
{
	param->n++;
	param->nbchar_output++;
	ft_putchar_fd(c, 1);
}

void	ft_putnbr_count(int n, t_set *param)
{
	param->n = param->n + ft_nbcharint(n);
	param->nbchar_output = param->nbchar_output + ft_nbcharint(n);
	ft_putnbr_fd(n, 1);
}

void	ft_putstr_null(t_set *param)
{
	param->n = param->n + 6;
	param->nbchar_output = param->nbchar_output + 6;
	ft_putstr_fd("(null)", 1);
}

void	ft_putstr_count(char *s, t_set *param)
{
	if (s == NULL)
		ft_putstr_null(param);
	else
	{
		param->n = param->n + ft_strlen(s);
		param->nbchar_output = param->nbchar_output + ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
}
