/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:22:51 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/13 16:27:16 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') \
	|| (c >= '0' && c <= '9'))
		return (c);
	return (0);
}
// int main()
// {
// 	printf("%d\n", isalnum(' '));
// 	printf("%d\n", ft_isalnum(' '));
// 	printf("%d\n", isalnum('a'));
// 	printf("%d\n", ft_isalnum('a'));
// 	printf("%d\n", isalnum('Z'));
// 	printf("%d\n", ft_isalnum('Z'));
// 	printf("%d\n", isalnum('9'));
// 	printf("%d\n", ft_isalnum('9'));
// }