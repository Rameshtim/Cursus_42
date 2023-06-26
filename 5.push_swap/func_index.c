/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:24:01 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/02 17:45:19 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		flag;

	flag = 0;
	min = NULL;
	head = *stack;
	while (head)
	{
		if ((head->index == -1) && (flag == 0 || head->content < min->content))
		{
			min = head;
			flag = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = find_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = find_next_min(stack);
	}
}
