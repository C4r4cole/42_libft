/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:10 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/06 14:54:47 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_chr(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static int	count_str(char const *s, char c)
{
	int	i;
	int	nbr_str;
	int	flag;

	i = 0;
	nbr_str = 0;
	flag = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
			{
				flag = 0;
				nbr_str++;
			}
		}
		i++;
	}
	return (nbr_str);
}

static void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**malloc_substr(char const *s, char c, char **tab, int i)
{
	int	flag;
	int	j;

	i = 0;
	while (i < count_str(s, c))
	{
		j = -1;
		flag = 1;
		while (s[j++] != '\0')
		{
			if (s[j] == c)
				flag = 1;
			else if (s[j] != c && flag == 1)
			{
				flag = 0;
				tab[i++] = ft_substr(s, j, nbr_chr(s + j, c));
				j = j + nbr_chr(s + j, c) - 1;
				if (!ft_substr(s, j, nbr_chr(s + j, c)))
					free_split(tab);
			}
		}
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = malloc_substr(s, c, tab, i);
	return (tab);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char const s[33] = "King Gizzard & the Lizard Wizard";
// 	char		c;
// 	char	**tab;
// 	int	i;

// 	c = ' ';
// 	i = 0;
// 	tab = ft_split(s, c);
// 	while (tab[i] != NULL)
// 	{
// 		printf("%s\n", tab[i]);
// 		free(tab[i]);
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }
