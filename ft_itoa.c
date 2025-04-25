/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvaro-pc <alvaro-pc@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:16:02 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/25 23:16:23 by alvaro-pc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len_num(int n)
{
	size_t	len;
	int		is_neg;

	if (n == -2147483648)
		return (11);
	is_neg = 0;
	len = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	if (n / 10 > 0)
		len = ft_len_num(n / 10);
	if (n == 0)
		return (1);
	if (is_neg)
		len += 1;
	return (len + 1);
}

static void	ft_put_number(int n, char *str, size_t len)
{
	int	is_neg;

	if (n == -2147483648)
	{
		ft_memcpy(str, "-2147483648", 11);
		return ;
	}
	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n *= -1;
	}
	if (n / 10 > 0)
		ft_put_number(n / 10, str, len - 1);
	if (n == 0)
		str[0] = '0';
	if (is_neg)
		str[0] = '-';
	str[len - 1] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len_num;

	len_num = ft_len_num(n);
	num = (char *)ft_calloc((len_num + 1), sizeof(char));
	if (!num)
		return (num);
	ft_put_number (n, num, len_num);
	return (num);
}
