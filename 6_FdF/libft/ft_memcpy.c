/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:44:15 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/19 14:09:57 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*my_dest;
	const char	*my_src;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	my_dest = dest;
	my_src = src;
	while (i < n)
	{
		my_dest[i] = my_src[i];
		i++;
	}
	return (my_dest);
}

// int main()
// {
// 	char src[] = "This is me.";
// 	char dest[11] = "Hello";
// 	char src1[] = "This is me.";
// 	char dest1[11] = "Hello";
// 	int i = 0;

// 	ft_memcpy(dest+2, dest, 8);
// 	printf("%s\n", src);
// 	printf("%s\n", dest);

// 	printf("pointer %p\n", src);
// 	printf("  dest %p\n", dest);

// 	memcpy(dest1+2, dest1, 8);
// 	printf("%s\n", src1);
// 	printf("%s\n", dest1);

// 	printf("pointer %p\n", src1);
// 	printf("  dest %p\n", dest1);
// }