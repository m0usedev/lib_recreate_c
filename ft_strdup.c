/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:16:12 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/17 12:28:32 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	copy = (char *)ft_calloc((len_s + 1), sizeof(char));
	if (copy == NULL)
		return (copy);
	i = 0;
	while (i < len_s)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}
