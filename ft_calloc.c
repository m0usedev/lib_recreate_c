/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:10:31 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/17 11:53:05 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*malloc_result;
	size_t			malloc_size;
	size_t			i;

	i = 0;
	if (size > 0 && nmemb >= __SIZE_MAX__ / size)
		return (NULL);
	malloc_size = nmemb * size;
	malloc_result = (unsigned char *)malloc(malloc_size);
	if (malloc_result == NULL)
		return ((void *)malloc_result);
	while (i < malloc_size)
		malloc_result[i++] = 0;
	return ((void *)malloc_result);
}
