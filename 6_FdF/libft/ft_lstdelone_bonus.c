/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:39:55 by rtimsina          #+#    #+#             */
/*   Updated: 2022/12/22 12:31:16 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->content);
	free(lst);
}

// void del(void *ptr)
// {
// 	free(ptr);
// }

// int main(void)
// {
//   int *ptr = malloc(sizeof(int));
//   *ptr = 42;
//   t_list *node = malloc(sizeof(t_list));
//   node->content = ptr;
//   node->next = NULL;

//   printf("Value before calling ft_lstdelone: %d\n", *(int*)node->content);
//   ft_lstdelone(node, del);
//   node = NULL;
//   if (*ptr != 42)
//     printf("Value not found\n");
//   return 0;
// }