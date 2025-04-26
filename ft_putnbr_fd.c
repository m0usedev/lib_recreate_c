/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:30:36 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/26 13:22:32 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_put_number(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n / 10 > 0)
		ft_write_put_number(n / 10, fd);
	ft_putchar_fd(((n % 10) + '0'), fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd == -1)
		return ;
	if (n < 0 && n > -2147483648)
		ft_putchar_fd('-', fd);
	ft_write_put_number(n, fd);
}
