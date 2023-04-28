/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:56:34 by fassier-          #+#    #+#             */
/*   Updated: 2021/11/24 13:42:24 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
//-----------------------------
#include <stdio.h>
#include <string.h>

int main()
{
	const char *str = NULL;

	printf("%lu\n",ft_strlen(str));
	return (0);
}*/
