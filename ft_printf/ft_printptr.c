/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:56:56 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/28 13:56:56 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else if (num <= 9)
		ft_putchar(num + '0');
	else
		ft_putchar((num - 10) + 'a');
}

int	ft_printptr(unsigned long long ptr)
{
	int	print_len;

	if (ptr == 0)
	{
		print_len = 5;
		ft_printstr("(nil)");
	}
	else
	{
		write(1, "0x", 2);
		print_len = 2;
		ft_putptr(ptr);
		print_len += ft_numlen(ptr, 16);
	}
	return (print_len);
}

// int main()
// {
// 	int x = 5745241;
// 	int j = ft_printptr(x);
// 	printf("\n%d total printed\n", j);
// }
