/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:32:40 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/28 13:32:40 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(unsigned long long num, int base)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}
