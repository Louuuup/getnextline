/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:20:10 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/05/09 16:16:01 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //TO REMOVE

// Returns 1 for YES
// Returns 0 for NO
int	has_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_stash_it(int fd, t_data *data)
{
	int		read_out;
	int		stash_size;

	stash_size = 0;
	read_out = BUFFER_SIZE;
	while (read_out > BUFFER_SIZE - 1 && !has_newline(data->buffer))
	{
		stash_size += BUFFER_SIZE;
		ft_bzero(data->buffer, BUFFER_SIZE);
		read_out = read(fd, data->buffer, BUFFER_SIZE);
		ft_strjoin(data);
		if (!data->stash)
			return (-1);
		// printf("read_out = %d\n", read_out); //TEMP
		// printf("stash = %s\n", stash); //TEMP 
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_data	data;

	data.stash = calloc(1, sizeof(char));
	if (!data.stash)
		return (NULL);
	if (ft_stash_it(fd, &data) == -1)
		return (NULL);
	// if (ft_get_line(&data) == -1)
	// 	return (NULL);
	// printf("\n%s\n", data.stash);
	return (data.stash);
}

//compiler: cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c