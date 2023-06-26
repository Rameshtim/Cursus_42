/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:38:50 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/19 16:22:50 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*src;

	i = 0;
	src = s;
	while (n > 0)
	{
		src[i] = '\0';
		i++;
		n--;
	}
}

// int main(void)
// {
//     int n = 0;
//     int m = 0;
//     char myarr[] = "Hello World";
//     char myarr1[] = "Hello World";
//     ft_bzero(myarr, 6);
//     bzero(myarr1, 6);
//     while (n < 11)
//     {
//         printf("%c", myarr[n]);
// 		n++;
// 	}
// 	printf("\n");
// 	while (m < 11)
// 	{
// 		printf("%c", myarr1[m]);
// 		m++;
// 	}
// 	printf("\n");
// }