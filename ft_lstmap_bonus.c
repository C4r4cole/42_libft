/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:44:22 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/12 21:11:44 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*f(void *content)
// {
// 	int		i;
// 	char	*str;

// 	str = content;
// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = str[i] + 13;
// 		i++;
// 	}
// 	return (str);
// }

// void	del(void *content)
// {
// 	free(content);
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resulted_list;
	t_list	*new_node;
	char	*str;

	resulted_list = NULL;
	while (lst)
	{
		str = ft_strdup(f(lst->content));
		if (!str)
			return (NULL);
		new_node = ft_lstnew(str);
		if (!new_node)
		{
			free(str);
			ft_lstclear(&resulted_list, (*del));
			return (NULL);
		}
		new_node->content = str;
		ft_lstadd_back(&resulted_list, new_node);
		lst = lst->next;
	}
	return (resulted_list);
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*resulted_list;
// 	t_list	*base;
// 	t_list	first;
// 	t_list	second;
// 	t_list	third;

// 	base = &first;
// 	first.content = ft_strdup("hello");
// 	first.next = &second;
// 	second.content = ft_strdup("world");
// 	second.next = &third;
// 	third.content = ft_strdup("!");
// 	third.next = NULL;

// 	resulted_list = ft_lstmap(base, f, del);
// 	while (resulted_list)
// 	{
// 		printf("%s\n", (char *)resulted_list->content);
// 		resulted_list = resulted_list->next;
// 	}
// 	return (0);
// }