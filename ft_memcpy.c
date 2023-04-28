/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:54:14 by fassier-          #+#    #+#             */
/*   Updated: 2021/11/25 15:45:12 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	size_t	i;

	i = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return ((void *)dest);
}
/*
//----------------------------------------------------------------
#include <stdio.h>
#include <string.h>

int main()
{
	char 	src[] = "";
	char	dest[] = "hello toi";
	int		i = 0;
	
	memcpy(dest, src, 3);

	while (i < 3)
	{
		printf("%c\n",dest[i]);
		i++;
	}
	return 0;
}*/
