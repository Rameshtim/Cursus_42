/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:08:43 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/22 18:48:53 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	if (!*little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			while (little[j] != '\0' && (i + j) < len && \
					(big[i + j] == little[j]))
				j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	const char *largestring = "Foo Bad Bar Baz";
// 	const char *smallstring = "Bar";
// 	char *ptr;
// 	ptr = ft_strnstr(largestring, smallstring, 20);
// 	printf("%s \n", ptr);
// }