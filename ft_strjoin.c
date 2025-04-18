/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:55:24 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/18 16:45:03 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l_s1;
	size_t	l_s2;

	if (!s1 || !s2)
		return (NULL);
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = ft_calloc((l_s1 + l_s2 + 1), sizeof(char));
	if (!str)
		return (str);
	ft_strlcat(str, s1, l_s1 + 1);
	ft_strlcat(str, s2, (l_s1 + l_s2) + 1);
	return (str);
}
