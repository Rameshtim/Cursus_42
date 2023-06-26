/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:20:51 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/12 15:20:51 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				len;
	char			*str;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char ft_touppercase(unsigned int i, char c)
// {
// 	char s;

// 	s = ft_toupper(c);
// 	//printf("%c\n", s);
// 	return (s);
// }

// int main(void)
// {
// 	char *str = "Hello World!";
// 	char *t = ft_strmapi(str, ft_touppercase);
// 	printf("%s\n", t);
// 	free(t);
// 	return (0);
// }