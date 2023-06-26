/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:14:05 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/04 15:14:05 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	slen;
	size_t	dlen;

	i = 0;
	j = 0;
	j = ft_strlen(dst);
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && (i < (size - dlen -1)))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + slen);
}

// int main(void)
// {
//     char src[100] = "Hello, world!";
//     char dst[16] = "Hello, ";

//     int r = ft_strlcat(dst, src, 2);
//     printf("New dst = %s and length is = %d \n", dst, r);
// Output: "Hello, Hello, world!"

//     char src1[100] = "Hello, world!";
//     char dst1[16] = "Hello, ";

//     size_t r1 = strlcat(dst1, src1, 2);
//     printf("New dst = %s and length is = %d \n", dst1, r);
// Output: "Hello, Hello, world!"

//     return 0;
// }