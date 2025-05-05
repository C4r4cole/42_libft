/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:58:21 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/02 19:01:53 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_reverse_firstdif(const char *s1, const char *s2, size_t size_i, int flag)
{
	size_t	size_j;

	size_i--;
	while (size_i > 0)
	{
		size_j = 0;
		while (s2[size_j] != '\0')
		{
			if (s1[size_i] == s2[size_j])
			{
				flag = 1;
				break ;
			}
			size_j++;
		}
		if (flag == 1)
		{
			size_i--;
			flag = 0;
		}
		else
			return (size_i);
	}
	return (size_i);
}

int	ft_firstdif(const char *s1, const char *s2, size_t size, int flag)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i] != '\0' && i < size)
	{
		j = 0;
		while (s2[j] != '\0' && j < size)
		{
			if (s1[i] == s2[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 1)
		{
			i++;
			flag = 0;
		}
		else
			return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		true_end;
	int		flag;
	char	*result;

	flag = 0;
	end = ft_reverse_firstdif(s1, set, ft_strlen(s1), flag);
	start = ft_firstdif(s1, set, ft_strlen(s1), flag);
	true_end = (end - start) + 1;
	result = ft_substr(s1, start, true_end);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 		char	s1[16] = "-*-+*hello*-2+*";
// 		char	set[4] = "*-*";

// 		printf("%s\n", ft_strtrim(s1, set));
// 		return (0);
// 	}
