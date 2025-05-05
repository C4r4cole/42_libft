/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:37:10 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/04 15:24:03 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_chr(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);	
}

int	count_str(char const *s, char c)
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

void	free_split(char **tab)
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nbr_str;
	int		i;
	
	nbr_str = count_str(s, c);
	tab = malloc(sizeof(char *) * (nbr_str + 1));
	if (!tab)
	return (NULL);
	i = 0;
	while (i < nbr_str)
	{
		char	*tab_str;
		int	j;
		int	flag;

		j = 0;
		flag = 1;
		while (s[j] != '\0')
		{
			if (s[j] == c)
				flag = 1;
			else
			{
				if (flag == 1)
				{
					flag = 0;
					tab_str = ft_substr(s, j, nbr_chr(s + j, c));
					tab[i] = tab_str;
					i++;
					j += nbr_chr(s + j, c) - 1;
					if (!tab_str)
					{
						free_split(tab);
					}
				}
			}
			j++;
		}
	}
	tab[i] = 0;
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
