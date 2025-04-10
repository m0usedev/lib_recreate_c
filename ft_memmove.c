/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:20:29 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/10 20:31:22 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*copy_src;
	char		*copy_dest;

	copy_dest = (char *)dest;
	copy_src = (const char *)src;
	if (copy_dest == copy_src || n == 0)
		return (dest);
	if (copy_dest > copy_src && copy_dest < copy_src + n)
	{
		while (n--)
			copy_dest[n] = copy_src[n];
	}
	else
	{
		while (n--)
			*copy_dest++ = *copy_src++;
	}
	return (dest);
}
