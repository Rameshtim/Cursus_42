/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:15:40 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/21 19:36:13 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main()
// {
// 	t_list	*head;
// 	t_list	*node1 = ft_lstnew("Node 1");
// 	t_list	*node2 = ft_lstnew("Node 2");
// 	t_list	*node3 = ft_lstnew("Node 3");

// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node3);

// 	int	size = ft_lstsize(head);
// 	printf("%d\n", size);
// 	return (0);
// }