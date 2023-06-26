/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:46:02 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/02 17:08:24 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **stack_getting, t_list **stack_giving)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_giving) == 0)
		return (-1);
	head_to = *stack_getting;
	head_from = *stack_giving;
	tmp = head_from;
	head_from = head_from->next;
	*stack_giving = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_getting = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_getting = tmp;
	}
	return (0);
}

int	ft_pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_a, stack_b) == -1)
		return (-1);
	write (1, "pa\n", 3);
	return (0);
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_push(stack_b, stack_a) == -1)
		return (-1);
	write (1, "pb\n", 3);
	return (0);
}
