/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francoismoulin <francoismoulin@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:57:56 by francoismou       #+#    #+#             */
/*   Updated: 2025/05/09 11:50:42 by francoismou      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    while (lst)
    {
        lst = lst->next;
    }
    return (lst);
    // return (lst->content); Segfault pourquoi ?
}

// #include <stdio.h>

// int main(void)
// {
//     t_list  *elem0;
//     t_list  elem1;
//     t_list  elem2;
//     t_list  elem3;
//     char str[6] = "hello";

//     elem3.content = str;
//     printf("%s\n", (char *)ft_lstlast(elem0));
//     return (0);
// }