/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:52:53 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/05/17 14:32:02 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "getnextline/get_next_line.h"

int main(int argc, char **argv)
{
    char    *line;
    int     fd1;
    printf("BUFFER_SIZE : %d\n", BUFFER_SIZE);
    if (argc != 2)
        return (0);
    fd1 = open(argv[1], O_RDONLY);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);
    close(fd1);
    return (NO_ERROR);
}

	// if (!(count >= SIZE_MAX || size >= SIZE_MAX))
