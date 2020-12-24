/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuihexm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:17:46 by tsannie           #+#    #+#             */
/*   Updated: 2020/12/21 10:02:46 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuihexm(unsigned int src)
{
	char out;
	int i;

	i = 0;
	if (src == 0)
		ft_putchar_fd('0', 1);
	else
	{
		if (src)
		{
			if (src % 16 < 10)
				out = (src % 16) + 48;
			else
			{
				(src % 16) == 10 ? out = 'A' : 0;
				(src % 16) == 11 ? out = 'B' : 0;
				(src % 16) == 12 ? out = 'C' : 0;
				(src % 16) == 13 ? out = 'D' : 0;
				(src % 16) == 14 ? out = 'E' : 0;
				(src % 16) == 15 ? out = 'F' : 0;
			}
		i++;
		src = src / 16;
		if (src)
			ft_putuihexm(src);
		ft_putchar_fd(out, 1);
		}
	}
}
