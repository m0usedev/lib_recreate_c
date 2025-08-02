/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:48 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/02 14:32:38 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copia los n bytes de memoria de src en dest, pero sin evitar solamapiento de memoria.
 *
 * @param solapamiento_de_memoria: Esto sucede cuando cuando una direccion de memoria origen (src) se solapa con la direccion de memoria de la de destino (dest), apuntan a la misma direccion de memoria, estos casos pueden dar por corromper los datos, ya que quizas estan intentando acceder a una direccion en origen que ya has modificado en destino previamente porque comparten direcciones.
 *
 * @param[in, out] dest: Direccion de memoria de destino donde se copiara desde le principio src n bytes.
 *
 * @param[in] src: Direccion de memoria origen desde la cual se copiara en dest n bytes.
 *
 * @param[in] n: Numero de bytes que seran copiados desde src en dest.
 *
 * @return Devolvemos dest con el numero de n bytes cipiados de src.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned const char	*copy_src;
	unsigned char		*copy_dest;

	if (!dest && !src) // primero comprobamos que ninguna de las dos es NULL
		return (NULL);
	copy_dest = (unsigned char *)dest;
	copy_src = (unsigned const char *)src;
	while (n--)
		*copy_dest++ = *copy_src++; //como es directamente una copia directa no agregamos el '\0' por mucho que no llegase a tener.
	return (dest);
}
