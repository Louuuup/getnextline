/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:20:10 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/05/09 14:48:10 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //TO REMOVE

int	ft_stash_it(int fd, t_data *data)
{
	int		read_out;
	int		stash_size;

	stash_size = 0;
	read_out = BUFFER_SIZE;
	while (read_out > BUFFER_SIZE - 1 &&)
	{
		stash_size += BUFFER_SIZE;
		ft_bzero(data->buffer, BUFFER_SIZE);
		read_out = read(fd, data->buffer, BUFFER_SIZE);
		data->stash = ft_strjoin(data->stash, data->buffer);
		if (!data->stash)
			return (-1);
		// printf("read_out = %d\n", read_out); //TEMP
		// printf("stash = %s\n", stash); //TEMP 
	}
	return (0);
}

int	ft_get_line(t_data *data)
{
	while(data->stash != '\n')
	{
		*data->buffer++;
	}
}

char	*get_next_line(int fd)
{
	static t_data	data;

	data.stash = calloc(1, sizeof(char));
	if (!data.stash)
		return (NULL);
	if (ft_stash_it(fd, &data) == -1)
		return (NULL);
	if (ft_get_line(&data) == -1)
		return (NULL);
	// printf("%s", result);
	return (data.stash);
}

//compiler: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c