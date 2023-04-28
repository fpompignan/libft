/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:46:42 by fassier-          #+#    #+#             */
/*   Updated: 2021/11/30 17:46:14 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count = 1;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	*creation_new_word(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}	

static char	**ft_fill_tab(char const *s, char c, char **tab)
{
	size_t	i;
	int		word;

	i = 0;
	word = 0;
	if (s[0] != c && s[0] != '\0')
	{
		tab[0] = creation_new_word(s, c);
		i = i + ft_strlen((char *)tab[0]);
		word = 1;
	}
	while (s[i])
	{
		if (s[i] == c && !(s[i + 1] == c || s[i + 1] == '\0'))
		{
			tab[word] = creation_new_word(s + i + 1, c);
			i = i + ft_strlen((char *)tab[word]);
			word++;
		}
		else
			i++;
	}
	tab[word] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nb_words;

	nb_words = count_words(s, c);
	result = malloc(sizeof(char *) * (nb_words + 1));
	if (result == NULL)
		return (NULL);
	result = ft_fill_tab(s, c, result);
	return (result);
}
