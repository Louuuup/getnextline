/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:38:23 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/05 14:25:53 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	has_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		else
			i++;
	}
	return (-1);
}

int	append_to_stash(t_data *data)
{
	data->proxy = data->stash;
	data->stash = ft_calloc(data->stash_size + 1, sizeof(char));
	if (!data->stash)
	{
		free(data->proxy);
		return (ERROR);
	}
	ft_strlcpy(data->stash, data->proxy, data->stash_size + 1);
	ft_strlcat(data->stash, data->buffer[data->fd], data->stash_size + 1);
	free(data->proxy);
	return (NO_ERROR);
}

int	parsing_without_nl(t_data *data)
{
	data->stash_size += ft_strlen(data->buffer[data->fd]);
	if (data->stash)
		data->error += append_to_stash(data);
	else
	{
		data->stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!data->stash)
			return (ERROR);
		ft_strlcpy(data->stash, data->buffer[data->fd], BUFFER_SIZE + 1);
		ft_bzero(data->buffer[data->fd], BUFFER_SIZE);
		data->stash_size = ft_strlen(data->stash);
	}
	return (NO_ERROR);
}

int	parsing_with_nl(t_data *data)
{
	data->stash_size += data->nl_idx;
	if (data->stash)
	{
		if (append_to_stash(data))
			return (ERROR);
	}
	else
	{
		data->stash = ft_calloc(data->nl_idx + 1, sizeof(char));
		if (!data->stash)
			return (ERROR);
		ft_strlcpy(data->stash, data->buffer[data->fd], data->nl_idx + 1);
	}
	ft_strlcpy(data->b_pxy, data->buffer[data->fd], BUFFER_SIZE + 1);
	ft_strlcpy(data->buffer[data->fd], data->b_pxy
		+ data->nl_idx, BUFFER_SIZE - data->nl_idx + 1);
	return (NO_ERROR);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	if (fd < 0)
		return (NULL);
	data.fd = fd;
	data.stash_size = 0;
	data.nl_idx = -1;
	data.rd_out = 1;
	data.stash = NULL;
	while (data.rd_out && data.nl_idx == -1)
	{
		if (data.buffer[data.fd][0] == '\0')
			data.rd_out = read(fd, data.buffer[data.fd], BUFFER_SIZE);
		if (data.rd_out == -1)
			return (free(data.stash), NULL);
		data.nl_idx = has_nl(data.buffer[data.fd]);
		if (data.nl_idx != -1)
			data.error = parsing_with_nl(&data);
		else
			data.error = parsing_without_nl(&data);
	}
	if (data.error || data.stash[0] == '\0')
		return (free(data.stash), NULL);
	return (data.stash);
}
