/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:23:05 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/17 14:40:06 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s >= start && (len_s - start) <= len)
		len = len_s - start;
	i = 0;
	sub_s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!sub_s)
		return (sub_s);
	while (i < len && s[start + i])
	{
		sub_s[i] = s[start + i];
		i++;
	}
	return (sub_s);
}
