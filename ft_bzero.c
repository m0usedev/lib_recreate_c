/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:40:45 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/02 14:22:39 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Rellena n bytes de la memoria s de '\0'.
 *
 * @param[in, out] s: Memoria que sera rellenada n bytes de '\0'.
 *
 * @param[in] n: Numero de bytes que seran rellenados de la memorai s de '\0'.
 *
 * @return void.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*aux;

	aux = (char *)s;
	while (n--)
		*aux++ = '\0';
}
