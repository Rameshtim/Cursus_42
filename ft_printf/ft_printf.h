/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:53:12 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/29 14:53:12 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_numlen(unsigned long long num, int base);
int		ft_printptr(unsigned long long ptr);
int		ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_printstr(char *s);
int		ft_printunsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_printnbr(int n);
int		ft_printhex(unsigned int num, const char c);
int		ft_printpercent(char c);

#endif
