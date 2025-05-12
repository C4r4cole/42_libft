/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:14:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/12 21:10:15 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	del(void *content)
// {
// 	free(content);
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if ((*lst)->content)
			del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// #include <stdio.h>

// int main(void)
// {
// 	void (*f)(void *) = &del;
//     t_list *maillon1 = ft_lstnew(ft_strdup("bonjour"));
// 	t_list *maillon2 = ft_lstnew(ft_strdup("aurevoir"));
// 	t_list *chaine = NULL;

// 	ft_lstadd_back(&chaine, maillon1);
// 	ft_lstadd_back(&chaine, maillon2);
// 	ft_lstclear(&chaine, (*f));
//     return (0);
// }