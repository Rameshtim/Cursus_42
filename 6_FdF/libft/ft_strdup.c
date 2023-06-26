/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:13:39 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/08 10:13:39 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	while (*s)
	{
		dup[i] = *s++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int main() {
//   char *original_string = "Hello, world!";

//   // create a copy of the original string using our custom my_strdup function
//   char *duplicate_string = ft_strdup(original_string);

//   // check if my_strdup failed
//   if (duplicate_string == NULL) {
//     return 1;
//   }

//   // print the original and duplicate strings
//   printf("Original string: %s\n", original_string);
//   printf("Duplicate string: %s\n", duplicate_string);

//   // free the memory allocated for the duplicate string
//   free(duplicate_string);

//   return 0;
// }