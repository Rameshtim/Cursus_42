/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:58:37 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/22 15:31:25 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// void print_int(void *ptr)
// {
// 	printf("%d ", *(int*)ptr);
// }
// 
// int main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1 = (t_list*)malloc(sizeof(t_list));
// 	t_list *node2 = (t_list*)malloc(sizeof(t_list));
// 	t_list *node3 = (t_list*)malloc(sizeof(t_list));
// 	t_list *node4 = (t_list*)malloc(sizeof(t_list));

// 	int *content1 = (int*)malloc(sizeof(int));
// 	*content1 = 1;
// 	int *content2 = (int*)malloc(sizeof(int));
// 	*content2 = 2;
// 	int *content3 = (int*)malloc(sizeof(int));
// 	*content3 = 3;
// 	int *content4 = (int*)malloc(sizeof(int));
// 	*content4 = 4;

// 	node1->content = content1;
// 	node1->next = node2;
// 	node2->content = content2;
// 	node2->next = node3;
// 	node3->content = content3;
// 	node3->next = node4;
// 	node4->content = content4;
// 	node4->next = NULL;

// 	head = node1;

// 	ft_lstiter(head, print_int);
// 	printf("\n");

// 	return 0;
// }