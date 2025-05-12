/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:54:00 by francoismou       #+#    #+#             */
/*   Updated: 2025/05/12 20:39:14 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current_elem;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current_elem = *lst;
	while (current_elem->next != NULL)
	{
		current_elem = current_elem->next;
	}
	current_elem->next = new;
}

// #include <stdio.h>

// int main(void)
// {
//     t_list *maillon1 = ft_lstnew("bonjour");
// 	t_list *maillon2 = ft_lstnew("aurevoir");
// 	t_list *chaine = NULL;

// 	ft_lstadd_back(&chaine, maillon1);
// 	ft_lstadd_back(&chaine, maillon2);

// 	while (chaine != NULL)
// 	{
// 		printf("%s\n", (char *)chaine->content);
// 		chaine = chaine->next;
// 	}
//     return (0);
// }