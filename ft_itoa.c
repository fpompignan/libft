/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:48:08 by fassier-          #+#    #+#             */
/*   Updated: 2021/12/02 12:24:15 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

static int	ft_count_nb_element(long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n = -n;
		count = 1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	ft_strrev(char *str)
{
	size_t	length;
	size_t	i;
	char	tmp;

	length = ft_strlen(str);
	i = 0;
	while (i < length / 2)
	{
		tmp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = tmp;
		i++;
	}
	str[length] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		is_neg;
	size_t	length;
	int		size;

	is_neg = (n < 0);
	size = ft_count_nb_element(n);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	length = 0;
	while (n != 0)
	{
		str[length++] = '0' + ft_abs(n % 10);
		n = (n / 10);
	}
	if (is_neg)
		str[length] = '-';
	str[size] = '\0';
	ft_strrev(str);
	return (str);
}
