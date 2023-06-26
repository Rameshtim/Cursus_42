/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akakinad <akakinad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:33:54 by akakinad          #+#    #+#             */
/*   Updated: 2023/02/27 14:34:01 by akakinad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (0);
	if (d < s)
	{
		while (len--)
		{
			*d++ = *s++;
		}
		return (dst);
	}
	else
	{
		s += len - 1;
		d += len - 1;
		while (len--)
		{
			*d-- = *s--;
		}
	}
	return (dst);
}
