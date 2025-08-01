/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:42:23 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/01 18:56:59 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Determina si un numero es un caracter alfabetico y o numerico.
 *
 * @param[in] c: Es el numero decimal del codigo ascii a evaluar.
 *
 * @return 8 en caso de ser alfabetico o numerico o 0 en caso contrario.
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (8);
	return (0);
}
