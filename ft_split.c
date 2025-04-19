/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:53:55 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/19 14:03:47 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_substr
static size_t	ft_num_subs(char const *s, char c)
{
	size_t	num_subs;

	num_subs = 0;
	if (!*s)
		return (num_subs);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			num_subs++;
		while (*s != c && *s)
			s++;
	}
	return (num_subs);
}

static char	**ft_free_split(char **split, size_t num_subs)
{
	if (!split)
		return (NULL);
	while (num_subs > 0)
		free(split[num_subs--]);
	free(split[0]);
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len_sub;
	size_t	i;

	split = (char **)ft_calloc(ft_num_subs(s, c) + 1, sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len_sub = ft_strlen(s);
			else
				len_sub = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, len_sub);
			if (!split[i - 1])
				return (ft_free_split(split, i - 2));
			s += len_sub;
		}
	}
	return (split);
}
