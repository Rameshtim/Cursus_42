/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:55:13 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/03 09:55:13 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	size_t		i;

	if (!src && !dst)
		return (NULL);
	s = src;
	d = dst;
	i = 0;
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

// int main()
// {
// 	char my_str[] = "Hello World";
// 	char my_str1[] = "Hello World";
// 	char my_str2[20];
// 	ft_memcpy(my_str + 2, my_str, sizeof(char) * 9);
// 	printf("my_str after memcpy:- %s \n", my_str);
// 	ft_memmove(my_str1 + 2, my_str1, sizeof(char) * 9);
// 	printf("my_str after memmove:- %s \n", my_str1);

// 	memcpy(my_str + 2, my_str, sizeof(char) * 9);
// 	printf("my_str after ORIGINAL memcpy:- %s \n", my_str);
// 	memmove(my_str1 + 2, my_str1, sizeof(char) * 9);
// 	printf("my_str after ORIGINAL memmove:- %s \n", my_str1);
// }