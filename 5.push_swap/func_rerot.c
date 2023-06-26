/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rerot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:23:31 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/02 17:08:48 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_revrotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	ft_rra(t_list **stack_a)
{
	if (ft_revrotate(stack_a) == -1)
		return (-1);
	write (1, "rra\n", 4);
	return (0);
}

int	ft_rrb(t_list **stack_b)
{
	if (ft_revrotate(stack_b) == -1)
		return (-1);
	write (1, "rrb\n", 4);
	return (0);
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	write (1, "rrr\n", 4);
	return (0);
}
