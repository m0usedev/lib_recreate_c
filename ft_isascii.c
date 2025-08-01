/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-linux <alvaro-linux@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:54:23 by asobrino          #+#    #+#             */
/*   Updated: 2025/08/01 19:01:36 by alvaro-linu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Determina si un caracter es ascii. Esto se hace porque los codigo decimales de ascii van del 0 al 127.
 *
 * @param[in] c: Es el codigo decimal del caracter ascii.
 *
 * @return 1 en caso de ser ascii y 0 en caso contrario.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
