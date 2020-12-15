/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:59:06 by tsannie           #+#    #+#             */
/*   Updated: 2020/10/20 16:26:26 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cpy;

	if (!del || !lst)
		return ;
	while (*lst)
	{
		cpy = (*lst)->next;
		ft_lstdelone((*lst), del);
		(*lst) = cpy;
	}
}
