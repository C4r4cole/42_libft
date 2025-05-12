/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:37:43 by francoismou       #+#    #+#             */
/*   Updated: 2025/05/12 14:36:21 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// #include <stdio.h>

// int main(void)
// {
// 	t_list *lst;
// 	lst = malloc(sizeof(t_list));
// 	if (lst == NULL)
// 		return (0);
// 	lst->content = ft_strdup("hello world");
// 	lst->next = NULL;

// 	printf("%s\n", (char *)lst->content);
// 	ft_lstdelone(lst, del);
// 	printf("%s\n", (char *)lst->content); /*segfault*/
// 	return (0);
// }