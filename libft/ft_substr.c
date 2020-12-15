/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:29:25 by tsannie           #+#    #+#             */
/*   Updated: 2020/10/16 15:41:10 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		size_global(char *src, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;

	i = start;
	size = 0;
	while (size < len && src[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*res;
	char	*src;

	src = (char *)s;
	size = size_global(src, start, len);
	i = 0;
	if (!(res = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		res[i] = src[i + start];
		i++;
	}
	res[size] = '\0';
	return (res);
}
