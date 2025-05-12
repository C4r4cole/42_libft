/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:57:56 by francoismou       #+#    #+#             */
/*   Updated: 2025/05/12 19:47:11 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

// #include <stdio.h>

// int main(void)
// {
//     t_list  *elem0;
//     t_list  elem1;
//     t_list  elem2;
//     t_list  elem3;
//     char str[6] = "hello";
// 	t_list *result;

// 	elem0 = &elem1;
// 	elem1.next = &elem2;
// 	elem2.next = &elem3;
// 	elem3.next = NULL;
//     elem3.content = str;
// 	result = ft_lstlast(elem0->content);
//     printf("%s\n", (char *)result->content);
//     return (0);
// }