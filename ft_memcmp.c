/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:33:09 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/15 16:49:29 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*text1;
	unsigned char	*text2;
	size_t			i;

	i = 0;
	text1 = (unsigned char *)s1;
	text2 = (unsigned char *)s2;
	while (i < n)
	{
		if (text1[i] != text2[i])
			return (text1[i] - text2[i]);
		i++;
	}
	return (0);
}
