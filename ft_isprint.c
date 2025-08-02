/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:54:39 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/02 14:13:57 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Determina si un caracter es imprimible, que se pueda mostrar como tal en pantalla.
 *
 * @param[in] c: recibimos el codigo decimal del caracter ascii a evaluar.
 *
 * @return 16384 si el caracter es imprimible o 0 si no lo es.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}
