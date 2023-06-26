/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:27:12 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/03 16:29:22 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_errors(char *str)
{
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checkdbl(long num, char **str, int pos)
{
	pos++;
	while (str[pos])
	{
		if (num == ft_atoi(str[pos]))
			return (1);
		pos++;
	}
	return (0);
}

int	ft_toobig(char *str)
{
	long long	num;

	num = ft_atoll(str);
	if (num >= -2147483648 && num <= 2147483647)
		return (1);
	return (0);
}

void	ft_check_args(int argc, char **av)
{
	int		i;
	long	tmp;
	char	**str;

	i = 0;
	if (argc == 2)
		str = ft_split(av[1], ' ');
	else
	{
		i = 1;
		str = av;
	}
	while (str[i])
	{
		tmp = ft_atoi(str[i]);
		if ((ft_isnum(str[i])) == 0)
			ft_errors("Error\n");
		if (ft_checkdbl(tmp, str, i))
			ft_errors("Error\n");
		if (!ft_toobig(str[i]))
			ft_errors("Error\n");
		i++;
	}	
}
