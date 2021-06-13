/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:16:18 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/25 18:50:28 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	char *dest;
	char *source;

	dest = (char *)dst;
	source = (char *)src;
	if (!source && !dest)
		return (NULL);
	while (size--)
		*dest++ = *source++;
	return (dst);
}
