/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:31:53 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/22 12:57:52 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
	*lst = NULL;
}

// void del(void *ptr)
// {
// 	free(ptr);
// }

// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1 = (t_list*)malloc(sizeof(t_list));
// 	t_list *node2 = (t_list*)malloc(sizeof(t_list));
// 	t_list *node3 = (t_list*)malloc(sizeof(t_list));
// 	t_list *node4 = (t_list*)malloc(sizeof(t_list));

// 	node1->content = "Node 1";
// 	node1->next = node2;
// 	node2->content = "Node 2";
// 	node2->next = node3;
// 	node3->content = "Node 3";
// 	node3->next = node4;
// 	node4->content = "Node 4";
// 	node4->next = NULL;

// 	head = node1;

// 	while (head)
// 	{
// 		printf("%s\n", head->content);
// 		head = head->next;
// 	}

// 	ft_lstclear(&head, del);

// 	if (head)
// 		printf("Linked list not cleared\n");
// 	else
// 		printf("Linked list cleared\n");

// 	return 0;
// }