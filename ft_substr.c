/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:43:26 by fassier-          #+#    #+#             */
/*   Updated: 2021/11/30 13:53:38 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*empty_str(void)
{
	char	*result;

	result = malloc(sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	size_t			size;
	size_t			space_malloc;
	unsigned int	i;

	size = ft_strlen(s);
	if (start >= size)
		return (empty_str());
	space_malloc = len + 1;
	if (len + start > size)
		space_malloc = size - start + 1;
	result = malloc(sizeof(char) * space_malloc);
	if (!result)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
