/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asobrino <asobrino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:21:51 by asobrino          #+#    #+#             */
/*   Updated: 2025/04/27 14:34:57 by asobrino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 1;
	if (!lst)
		return (0);
	if (lst->next)
		len = ft_lstsize(lst->next) + 1;
	return (len);
}
