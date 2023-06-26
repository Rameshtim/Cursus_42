/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:57:01 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/02 17:44:08 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*head;
	t_list	*next_head;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next_head = head->next;
	if (!head || !next_head)
		ft_perror("Error while swapping!");
	tmp_val = head->content;
	tmp_index = head->index;
	head->content = next_head->content;
	head->index = next_head->index;
	next_head->content = tmp_val;
	next_head->index = tmp_index;
	return (0);
}

int	ft_sa(t_list **stack_a)
{
	if (ft_swap(stack_a) == -1)
		return (-1);
	write (1, "sa\n", 3);
	return (0);
}

int	ft_sb(t_list **stack_b)
{
	if (ft_swap(stack_b) == -1)
		return (-1);
	write (1, "sb\n", 3);
	return (0);
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	write (1, "ss\n", 3);
	return (0);
}
