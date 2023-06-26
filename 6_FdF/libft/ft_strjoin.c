/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:03:27 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/08 12:03:27 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*str;

	i = 0;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j++ < s2_len)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
// 	char *str1 = "Hello ";
// 	char *str2 = "world.";
// 	char *str3;

// 	str3 = ft_strjoin(str1, str2);
// 	printf("I want to say %s\n", str3);
// 	free(str3);
// 	return 0;

// }