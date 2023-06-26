/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:59:10 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/04 18:59:10 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

// int main(void) {
//   char *str = "hello, world";
//   char *ptr = ft_strchr(str, '\0');
//   if (ptr) {
//     printf("Found character 'w' at index %ld\n", ptr - str);
//     printf("%s\n", ptr);
//   } else {
//     printf("Character 'w' not found in string\n");
//   }
//   return 0;
// }