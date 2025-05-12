/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:14:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/12 14:40:25 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_elem;

	current_elem = *lst;
	if (!current_elem || !del)
		return (NULL);
	while (current_elem)
	{
		del(current_elem->content);
		current_elem = current_elem->next;
	}
	free(current_elem);
}

// #include <stdio.h>

// int	main(void)
// {

// 	return (0);
// }