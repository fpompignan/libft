/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:44:12 by fassier-          #+#    #+#             */
/*   Updated: 2021/12/02 11:03:57 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
/*
char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		count;

	count = 0;
	ptr = (char *)s;
	while (*ptr)
	{
		count++;
		ptr++;
	}
	while (*ptr != c && count >= 0)
	{
		count--;
		ptr--;
	}
	if (count == -1)
		return (NULL);
	return (ptr);
}*/
