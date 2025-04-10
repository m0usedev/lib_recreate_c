/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:48 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/10 20:31:33 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*copy_src;
	char		*copy_dest;

	copy_dest = (char *)dest;
	copy_src = (const char *)src;
	while (n--)
		*copy_dest++ = *copy_src++;
	return (dest);
}
