/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:26:11 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/04 19:26:11 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s + ft_strlen(s);
	while (p >= s)
	{
		if (*p == (char)c)
			return ((char *)p);
		p--;
	}
	return (NULL);
}

// int main(void) {
//   char *str = "hello, world";
//   char *ptr = ft_strrchr(str, 'y');
//   if (ptr) {
//     printf("Found character 'l' at index %ld\n", ptr - str);
//   } else {
//     printf("Character 'l' not found in string\n");
//   }

//   char *str1 = "hello, world";
//   char *ptr1 = strrchr(str1, 'y');
//   if (ptr) {
//     printf("Found character 'l' at index %ld\n", ptr1 - str1);
//   } else {
//     printf("Character 'l' not found in string\n");
//   }
//   return 0;
// }