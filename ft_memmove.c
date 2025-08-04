/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:20:29 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/04 18:52:46 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copia la direccion de memoria de src en dest, n bytes desd el principio. Evitando el solapamiento de memoria.
 *
 * solapamiento de memoria: Esto sucede cuando una direccion de memoria origen (src) se solapa con la direccion de memoria de la de destino (dest), apuntan a la misma direccion de memoria, estos casos pueden dar por corromper los datos, ya que quizas estan intentando acceder a una direccion en origen que ya has modificado en destino previamente porque comparten direcciones.
 *
 * Para evitarlo lo que hace es primero comprobar si la posicion de memoria actual de dest y src son iguales, por tanto comparten y por tanto no hay que hacer nada, devolvemos dest. O, si n es 0, por lo que no hay nada que copiar y devolvemos dest.
 *
 * Lo segundo que hace es que en caso de que la direccion de memoria actual de dest sea mayor que la actual de src y esta sea menor que la de s + n bytes a copiar indicaria que habria solapamiento, porqe comparten direcciones de memoria.
 *
 * Esto puedes verlo como:
 *
 * dest [10, 11, 12]
 *
 * src [9, 10, 11, 12]
 *
 * n = 3
 *
 * La posicición actual de dest es 10 y esta es mayo que la actual de src 9 y mas n 3 = 12, por lo que comparten direcciones de memoria.
 *
 * La manera de poder hacer la copia evitando este problema es en copiar de atras hacida delante. Si copiamos de izquierda a derecha lo que pasara es que con la 9 de src modificaremos su 10 a traves de dest y cuando quiera acceder a su 10 dara error porque ha sido modificado ya, es como que se pierde, pero de atras hacia delante estamos copiando con una posicion de retraso. De la 11 a la 12, de la 10 a la 11, de la 9 a la 10. Hemos evitado modificar una posicion antes de accer a ella.
 *
 * @param[in, out] dest: Direccion de memoria donde copiaremos src n bytes.
 * @param[in] src: Direccion de memoria que copiaremos en dest n bytes.
 * @param[in] n: Numero de bytes que copiaremos de src en dest.
 *
 * @return Devlemos dest siempre.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d > s && d < s + n)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
