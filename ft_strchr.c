/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:43:08 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/15 11:36:50 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	c_2;

	i = 0;
	c_2 = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == c_2)
			return ((char *)s + i);
		i++;
	}
	if (c_2 == '\0')
		return ((char *)s + i);
	return (NULL);
}
