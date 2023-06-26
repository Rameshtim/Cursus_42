/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:02:59 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/04 12:02:59 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	n;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len >= size)
		n = size - 1;
	else
		n = src_len;
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (src_len);
}

// int main(void)
// {
//     char src[] = "Hello, world!";
//     char dst[16];
// 	char dest[100];
// 	int i = ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0);
// 	printf("New dst = %s and length is = %d \n", dest, i); 
//     int r = ft_strlcpy(dst, src, 5);
//     printf("New dst = %s and length is = %d \n", dst, r);  

//     return 0;
// }