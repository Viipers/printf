/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuihexm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:17:46 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/17 11:18:39 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuihexm(unsigned int src)
{
	char *res;
	int i;

	i = 0;
	src == 0 ? ft_putchar_fd('0', 1) : 0;
	res = malloc(sizeof(char) * ft_nbcharuihex(src) + 1);
	while (src)
	{
		if (src % 16 < 10)
			res[i] = (src % 16) + 48;
		else
		{
			(src % 16) == 10 ? res[i] = 'A' : 0;
			(src % 16) == 11 ? res[i] = 'B' : 0;
			(src % 16) == 12 ? res[i] = 'C' : 0;
			(src % 16) == 13 ? res[i] = 'D' : 0;
			(src % 16) == 14 ? res[i] = 'E' : 0;
			(src % 16) == 15 ? res[i] = 'F' : 0;
		}
		i++;
		src = src / 16;
	}
	ft_rev_char_tab(res);
	ft_putstr_fd(res ,1);
	free(res);
}

