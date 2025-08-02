/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:26:09 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/02 14:18:40 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Rellena una la memoria s de c bytes n veces desd el principio.
 *
 * @param[in, out] s: Memoria que sera modificada y devuelta, rellenandose con c bytes desde el principio n veces.
 *
 * @param[in] c: bytes con los que se rellenara la memoria s n veces.
 *
 * @param[in] n: Es el numero de veces que se rellenara la memorai s desde el principio de c bytes.
 *
 * @return Devolvemos la misma memoria s modificada.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*aux;

	aux = (unsigned char *)s;
	while (n--)
		*aux++ = c;
	return (s);
}
