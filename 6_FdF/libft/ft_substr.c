/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 11:07:12 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/08 11:07:12 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*new_substr;
	unsigned int	src_len;
	size_t			j;

	src_len = ft_strlen(s);
	i = 0;
	j = 0;
	if (len > src_len)
		len = src_len;
	new_substr = (char *)malloc((len + 1) * sizeof(*s));
	if (!new_substr)
		return (NULL);
	while (s[i])
	{
		if (j < len && start <= i)
		{
			new_substr[j] = s[i];
			j++;
		}
		i++;
	}
	new_substr[j] = '\0';
	return (new_substr);
}

// int main() {
//   char *s = "Hello, world!";
//   unsigned int start = 200;
//   size_t len = 5;

//   char *substring = ft_substr(s, start, len);

//   if (substring == NULL) {
//     printf("Error: ft_substr failed to allocate memory.\n");
//     return 1;
//   }

//   printf("Substring: %s\n", substring);

//   free(substring);

//   return 0;
// }