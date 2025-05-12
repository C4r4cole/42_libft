/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoismoulin <francoismoulin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:54:00 by francoismou       #+#    #+#             */
/*   Updated: 2025/05/09 14:36:07 by francoismou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *current_elem;
    
    if (!lst || !new)
        return;
    if (!*lst)
    {
        *lst = new;
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
//     t_list **elem0;
//     t_list *elem0;
//     t_list elem1;
//     t_list elem2;
//     t_list elem3;
    
//     *elem0 = &elem0;
//     elem0 = &elem1;
//     elem1.next = &elem2;
//     elem2.next = &elem3;
//     elem3.next = NULL;
    
    
//     return (0);
// }