/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:21:52 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/05 10:21:52 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	ch;

	p = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n > 0)
	{
		if (*p == ch)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char str[] = "Hello world";
// 	char *p = ft_memchr(str, 'w', sizeof(str));
// 	if (p != NULL) {
//     printf("Found character 'w' at index %ld\n", p - str);
// 	printf("Found is : %s\n", p);
//   } else {
//     printf("Character 'w' not found in string\n");
//   }

// char str1[] = "Hello world";
// 	char *p1 = memchr(str1, 'w', sizeof(str1));
// 	if (p1 != NULL) {
//     printf("ORIGINAL Found character 'w' at index %ld\n", p1 - str1);
// 	printf("ORIGINAL Found is : %s\n", p1);
//   } else {
//     printf("ORIGINAL Character 'w' not found in string\n");
//   }

//   return 0;
// }