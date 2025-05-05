/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:22:30 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/02 12:56:26 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < size)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char s1[] = "hello world";
	char s2[6] = "healo";

	printf("%d\n", ft_strncmp(s1, s2, 3));
	return (0);
}
*/