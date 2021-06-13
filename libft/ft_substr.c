/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdelport <kdelport@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:16:11 by kdelport          #+#    #+#             */
/*   Updated: 2020/11/30 02:11:16 by kdelport         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_min(char const *s, size_t len)
{
	if (ft_strlen(s) < len)
		return (ft_strlen(s));
	else
		return (len);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	x;
	char	*str;

	i = start;
	x = 0;
	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(*str) * (get_min(s, len) + 1))))
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	while (s[i] && x < len)
		str[x++] = s[i++];
	str[x] = '\0';
	return (str);
}
