/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 09:31:10 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/28 09:31:10 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return (11);
		}
		ft_putchar('-');
		len++;
		n *= -1;
	}
	num = ft_uitoa(n);
	len += ft_printstr(num);
	free(num);
	return (len);
}
