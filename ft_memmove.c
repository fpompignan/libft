/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:57:34 by fassier-          #+#    #+#             */
/*   Updated: 2021/11/25 16:46:18 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;

	dest2 = dest;
	src2 = (char *)src;
	if (src2 < dest2)
	{
		dest2 += n - 1;
		src2 += n - 1;
		while (n--)
		{
			*dest2 = *src2;
			dest2--;
			src2--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
