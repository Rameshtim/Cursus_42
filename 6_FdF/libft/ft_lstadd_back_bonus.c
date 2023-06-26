/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:27:26 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/22 11:39:34 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	if (lst && new)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1 = ft_lstnew("Node 1");
// 	t_list *node2 = ft_lstnew("Node 2");
// 	t_list *node3 = ft_lstnew("Node 3");
// 	t_list *node4 = ft_lstnew("Node 4");

// 	ft_lstadd_back(&head, node1);
// 	ft_lstadd_back(&head, node2);
// 	ft_lstadd_back(&head, node3);
// 	ft_lstadd_back(&head, node4);

// 	while (head)
// 	{
// 		printf("%s\n", head->content);
// 		head = head->next;
// 	}

// 	return 0;
// }