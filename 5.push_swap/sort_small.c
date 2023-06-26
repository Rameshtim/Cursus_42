/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:53:18 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/22 15:18:10 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_big_num(t_list *stack)
{
	int	bignum;

	bignum = stack->content;
	stack = stack->next;
	while (stack)
	{
		if (stack->content > bignum)
			bignum = stack->content;
		stack = stack->next;
	}
	return (bignum);
}

int	find_smallno(t_list *stack_a)
{
	int	min;

	min = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < min)
			min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (min);
}

int	find_nextmin(t_list *stack_a)
{
	int	min;
	int	next_min;

	min = find_smallno(stack_a);
	if (stack_a->content == min)
		stack_a = stack_a->next;
	next_min = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content < next_min && stack_a->content != min)
			next_min = stack_a->content;
		stack_a = stack_a->next;
	}
	return (next_min);
}

void	sort_three(t_list **stack_a)
{
	if (find_big_num(*stack_a) == (*stack_a)->content)
		ft_ra(stack_a);
	else if (find_big_num(*stack_a) == (*stack_a)->next->content)
		ft_rra(stack_a);
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void	sort_4_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	next_min;

	min = find_smallno(*stack_a);
	if (ft_lstsize(*stack_a) == 5)
		next_min = find_nextmin(*stack_a);
	else
		next_min = min;
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->content == min || (*stack_a)->content == next_min)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	sort_three(stack_a);
	if ((*stack_b)->next && (*stack_b)->content < (*stack_b)->next->content)
		ft_sb(stack_b);
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}
