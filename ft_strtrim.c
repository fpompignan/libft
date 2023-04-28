/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:41:32 by fassier-          #+#    #+#             */
/*   Updated: 2021/11/30 13:52:29 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_sep(char const *s1, char const *set)
{
	size_t	count;
	size_t	len;
	int		i;

	count = 0;
	i = 0;
	len = ft_strlen(s1);
	while (ft_char_in_set(s1[i], set) == 1 && s1[i])
	{
		i++;
		count++;
	}
	if (count == len)
		return (len);
	i = 0;
	while (ft_char_in_set(s1[len - 1 - i], set) == 1)
	{
		i++;
		count++;
	}
	return (count);
}

static size_t	find_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_char_in_set(s1[i], set) == 1 && s1[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	size_t	start;
	int		count;
	char	*result;

	count = count_sep(s1, set);
	len = ft_strlen(s1);
	start = find_start(s1, set);
	result = malloc(sizeof(char) * (len - count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len - count)
	{
		result[i] = s1[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
