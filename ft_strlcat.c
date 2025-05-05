/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:10:55 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/05 16:00:40 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char *)src);
	i = 0;
	j = 0;
	while (i < size && dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		if ((j < size - i - 1) && dest[i] != '\0')
		{
			dest[i] = src[j];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dest[100] = "hello world";
// 	char	src[7] = "coucou";
// 	int		result;

// 	result = ft_strlcat(dest, src, sizeof(dest));
// 	printf("%d\n", result);
// }