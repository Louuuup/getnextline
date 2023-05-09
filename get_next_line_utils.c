/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:35:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/05/09 16:14:26 by ycyr-roy         ###   ########.fr       */
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

// data.stash = s1
// data.buffer = s2
int	ft_strjoin(t_data *data)
{
	char	*str_a;
	char	*str_b;
	size_t	size[3];

	size[1] = ft_strlen(data->stash);
	size[2] = ft_strlen(data->buffer);
	size[0] = size[1] + size[2] + 1;
	if (size[1] == 1 && data->stash[0] == '\0')
	{
		data->stash = data->buffer;
		return (0);
	}
	str_a = ft_calloc(size[0] + 1, sizeof(char));
	if (!str_a)
		return (-1);
	str_b = str_a + size[1];
	ft_memcpy(str_a, data->stash, size[1]);
	ft_memcpy(str_b, data->buffer, size[2]);
	// printf("sa: %s\n", str_a);
	// printf("sb: %s\n", str_b);
	free((void *)data->stash);
	data->stash = str_a;
	return (0);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
	
// }