/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:47:44 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/15 16:00:23 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*text;
	unsigned char		c_2;
	size_t				i;

	i = 0;
	c_2 = (unsigned char)c;
	text = (unsigned char *)s;
	while (i < n)
	{
		if (text[i] == c_2)
			return ((char *)text + i);
		i++;
	}
	return (NULL);
}
