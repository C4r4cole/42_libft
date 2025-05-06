/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoulin <fmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:26:24 by fmoulin           #+#    #+#             */
/*   Updated: 2025/05/06 12:19:19 by fmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	to_positive(int n)
{
	if (n == FT_INT_MIN)
	{
		return (n = (unsigned int)(- (n + 1) + 1));
	}
	else
	{
		return (n = (unsigned int)(-n));
	}
}

int	count_nbr(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = 0;
	if (n == 0)
		count = 1;
	else if (n < 0)
	{
		nb = to_positive(n);
		count = 1;
	}
	else
		nb = (unsigned int) n;
	while (nb > 0)
	{
		nb = nb / 10;
		count ++;
	}
	return (count);
}

char	*fill_tab(char *tab, int n, int count, size_t i)
{
	i = 0;
	while ((int)i < count)
	{
		if (n == 0)
		{
			tab[i++] = '0';
			tab[i] = '\0';
			return (tab);
		}
		if (n < 0)
		{
			n = to_positive(n);
			tab[i++] = '-';
		}
		else
			i++;
		while ((unsigned int)n > 9)
		{
			tab[count - i++] = ((unsigned int)n % 10) + 48;
			n = (unsigned int)n / 10;
		}
		tab[count - i++] = ((unsigned int)n % 10) + 48;
		tab[i] = '\0';
	}
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		count;
	int		i;

	i = 0;
	count = count_nbr(n);
	tab = malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, n, count, i));
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	n;

// 	n = FT_INT_MIN;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }