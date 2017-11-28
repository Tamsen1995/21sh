/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbui <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:42:09 by tbui              #+#    #+#             */
/*   Updated: 2015/11/24 19:42:35 by tbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && i > 0)
		i--;
	if (i == 0 && str[i] != c)
		return (NULL);
	str = &str[i];
	return ((char *)str);
}
