/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linehelper_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:16:55 by rtimsina          #+#    #+#             */
/*   Updated: 2023/06/05 17:19:01 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lh_init(t_linehelper *lh, t_coord *c0, t_coord *c1)
{
	lh->dx = abs(c1->x - c0->x);
	if (c0->x < c1->x)
		lh->sx = 1;
	else
		lh->sx = -1;
	lh->dy = -abs(c1->y - c0->y);
	if (c0->y < c1->y)
		lh->sy = 1;
	else
		lh->sy = -1;
	lh->err = lh->dx + lh->dy;
	lh->x = c0->x;
	lh->y = c0->y;
}

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

static int	base_value(int c, int base)
{
	char	*small_base;
	char	*big_base;
	int		i;

	small_base = "0123456789abcdefghijklmnopqrstuvwxyz";
	big_base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	while (i < base)
	{
		if (c == small_base[i] || c == big_base[i])
			return (i);
		i++;
	}
	return (-1);
}

uint32_t	ft_atoi_base(const char *nptr, int base)
{
	uint32_t	value;
	int			minus;
	int			i;

	value = 0;
	minus = 1;
	i = 0;
	while (is_whitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (base_value(nptr[i], base) != -1)
	{
		value = (value * base) + base_value(nptr[i], base);
		i++;
	}
	return (value * minus);
}
