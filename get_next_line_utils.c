/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:35:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/05/26 18:14:20 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	
	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	if (s[0] == '\0')
		return (0);
	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		ft_bzero(dst, dstsize);
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slength;
	size_t	dlength;

	dlength = 0;
	i = 0;
	j = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	while (dst[j])
		j++;
	dlength = j;
	slength = ft_strlen(src);
	if (dstsize == 0 || dstsize < dlength)
		return (slength + dstsize);
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	if (src[i] == '\0')	//TEST
		ft_bzero(src, slength);
	return (dlength + slength);
}
