/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:01 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/13 16:29:37 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

// int main()
// {
// 	printf("%d\n", isprint('A'));
// 	printf("%d\n", ft_isprint('A'));
// }