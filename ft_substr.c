/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 18:06:12 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/06 10:26:10 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	char	*alloc_new_str;
	size_t	i;

	if (start > strlen(s))
		return (ft_strdup(""));
	new_str = &((char *)s)[start];
	i = 0;
	while (new_str[i] != '\0' && i <= len)
	{
		i++;
	}
	alloc_new_str = malloc(sizeof(char) * (i + 1));
	if (!alloc_new_str)
		return (NULL);
	ft_memcpy(alloc_new_str, new_str, len);
	alloc_new_str[i] = '\0';
	return (alloc_new_str);
}

// #include	<stdio.h>

// int	main(void)
// {
// 	char	s[52] = "che meraviglia stare con te in una guerra dei bacci";
// 	unsigned int	start;
// 	char	*new_str;
// 	size_t	len;

// 	start = 15;
// 	len = 5;
// 	new_str = ft_substr(s, start, len);
// 	printf("%s\n", new_str);
// 	return (0);
// }