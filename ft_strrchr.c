/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:42:18 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/15 11:51:01 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c_2;

	i = ft_strlen(s);
	c_2 = (unsigned char)c;
	if (c_2 == '\0')
		return ((char *)s + i);
	i--;
	while (i >= 0)
	{
		if (s[i] == c_2)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
