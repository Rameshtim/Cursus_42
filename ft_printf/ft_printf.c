/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 10:43:02 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/29 10:43:02 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char c)
{
	int	print_len;

	print_len = 0;
	if (c == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		print_len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		print_len += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		print_len += ft_printnbr(va_arg(args, int));
	else if (c == 'u')
		print_len += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print_len += ft_printhex(va_arg(args, unsigned int), c);
	else if (c == '%')
		print_len += ft_putchar(c);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}

// int main()
// {
// 	ft_printf(" NULL %s NULL ", NULL);
// }
// int main()
// {
// 	// int x = -10;
// 	char str[] = "";
// 	int printed;
// 	printed = 0;
//  	printed += ft_printf("and a string :- %s\n", str);
// 	printed += ft_printf("NULL %s NULL \n", NULL);
// 	//printed += ft_printf("This is a int x :- %d \n", x);
// 	printf("total printed = %d\n", printed);
// 	printf("This is me.%s\n", str);
// 	return (0);
// }
