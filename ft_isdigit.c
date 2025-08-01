/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:16:54 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/01 18:52:02 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


/**
 * @brief Determina si es un numero en codigo ascii.
 *
 * @param[in] c: Recibe el codigo decimal del caracter que quieres evaluar si es un numero.
 *
 * @return 2048 en caso de ser codigo de un numero ascii o 0 en caso contrario.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}
