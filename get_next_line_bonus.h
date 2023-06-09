/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:54:16 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/05 13:55:17 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define ERROR -1
# define NO_ERROR 0

// Stash: Only actual line
// Buffer: all infos read for "BUFFER_SIZE" bytes.
// b_proxy: Tmp string for buffer.
// proxy: temp to free old stashs.
// rd_out: number of bytes read with read();
// stash_size: Total lengh of actual stash string.
// nl_byte: position of '\n' in Buffer.
// error: 0 if no error, other if something went wrong
typedef struct data
{
	int		fd;
	char	*stash;
	char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char	b_pxy[BUFFER_SIZE + 1];
	char	*proxy;
	int		rd_out;
	int		nl_idx;
	int		stash_size;
	int		error;
}			t_data;

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
int		ft_strlen(const char *s);
int		append_to_stash(t_data *data);

#endif