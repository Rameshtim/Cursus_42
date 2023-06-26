/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:15:05 by rtimsina          #+#    #+#             */
/*   Updated: 2023/05/02 17:42:55 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

t_list	*ft_lstnew_new(int value);
void	ft_check_args(int argc, char **av);
int		ft_pa(t_list **stack_a, t_list **stack_b);
int		ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);
void	ft_free(char **str);
void	index_stack(t_list **stack);
t_list	*find_next_min(t_list **stack);
void	ft_free_stack(t_list **stack);
int		ft_check_sorted(t_list **stack);
void	ft_perror(char *str);
void	sort_three(t_list **stack_a);
void	sort_4_five(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
int		main(int argc, char *argv[]);
#endif
