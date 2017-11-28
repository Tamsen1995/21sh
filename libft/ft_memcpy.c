/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:48:35 by tbui              #+#    #+#             */
/*   Updated: 2015/11/24 14:50:47 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destptr;
	char	*srcptr;

	destptr = (char *)dest;
	srcptr = (char *)src;
	if (dest == src || n == 0)
		return (dest);
	while (n--)
	{
		*destptr++ = *srcptr++;
	}
	return (dest);
}
