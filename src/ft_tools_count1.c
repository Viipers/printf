/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_count1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:34:44 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/19 21:38:29 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
