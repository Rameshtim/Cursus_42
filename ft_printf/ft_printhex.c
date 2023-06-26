/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:27:59 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/28 16:27:59 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, c);
		ft_puthex(num % 16, c);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
	{
		if (c == 'x')
			ft_putchar((num - 10) + 'a');
		if (c == 'X')
			ft_putchar((num - 10) + 'A');
	}
}

int	ft_printhex(unsigned int num, const char c)
{
	if (num == 0)
		return (write(1, "0", 1));
	ft_puthex(num, c);
	return (ft_numlen(num, 16));
}

// int main()
// {
// 	long long x = 9223372036854775807;
// 	int y = ft_printhex(x, 'X');
// 	printf("\ntotal printed in hex is %d \n", y);
// }