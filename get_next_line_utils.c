/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:35:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/05/09 15:31:49 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*cp;

	cp = (unsigned char *)s;
	while (n--)
	{
		*cp++ = 0;
	}
	return (s);
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*x;
	unsigned char	*y;

	if (!dst || !src)
		return (dst);
	i = 0;
	x = (unsigned char *)dst;
	y = (unsigned char *)src;
	while (i < n)
	{
		x[i] = y[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_a;
	char	*str_b;
	size_t	size;
	size_t	s1_size;
	size_t	s2_size;

	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	size = s1_size + s2_size + 1;
	if (!s1 || !s2)
		return (0);
	if (size <= 0)
		return (0);
	if (s1_size == 1 && s1[0] == '\0')
		return ((char *)s2);
	str_a = ft_calloc(size + 1, sizeof(char));
	if (!str_a)
		return (NULL);
	str_b = str_a + s1_size;
	ft_memcpy(str_a, s1, s1_size);
	ft_memcpy(str_b, s2, s2_size);
	printf("sa: %s\n", str_a);
	printf("sb: %s\n", str_b);
	// free((void *)s1);
	return (str_a);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
	
// }