/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:34:44 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/17 17:15:19 by tsannie          ###   ########.fr       */
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

void	ft_putstrn_count(char *s, t_set *param, int glob)
{
	param->n = param->n + glob;
	param->nbchar_output = param->nbchar_output + glob;
	ft_putstrn_fd(s, glob, 1);
}

void	ft_putultoh_count(unsigned long a, t_set *param)
{
		param->n = param->n + ft_nbcharhex(a);
		param->nbchar_output = param->nbchar_output + ft_nbcharhex(a);
		if (param->without_pre == 1)
			ft_putstr_count("0x", param);
		ft_putultoh(a);
}

void	ft_putunbr_count(unsigned int a, t_set *param)
{
	param->n = param->n + ft_nbcharuint(a);
	param->nbchar_output = param->nbchar_output + ft_nbcharuint(a);
	ft_putunbr_fd(a, 1);
}

void	ft_putuihex_count(unsigned int a, t_set *param)
{
	param->n = param->n + ft_nbcharuihex(a);
	param->nbchar_output = param->nbchar_output + ft_nbcharuihex(a);
	ft_putuihex(a);
}

void	ft_putuihexm_count(unsigned int a, t_set *param)
{
	param->n = param->n + ft_nbcharuihex(a);
	param->nbchar_output = param->nbchar_output + ft_nbcharuihex(a);
	ft_putuihexm(a);
}
