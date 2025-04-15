/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:40:27 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/15 12:54:49 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*text1;
	unsigned char	*text2;
	size_t			i;

	i = 0;
	text1 = (unsigned char *)s1;
	text2 = (unsigned char *)s2;
	while (i < n && (text1[i] || text2[i]))
	{
		if (text1[i] != text2[i])
			return (text1[i] - text2[i]);
		i++;
	}
	return (0);
}
