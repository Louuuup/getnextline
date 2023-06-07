/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:22:12 by ycyr-roy          #+#    #+#             */
/*   Updated: 2023/06/05 14:16:29 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unistd.h>
// #include <fcntl.h>
// #include "getnextline/get_next_line.h"
// #include "getnextline/get_next_line.c"
// #include "getnextline/get_next_line_utils.c"

// int	main(int argc, char **argv)
// {
// 	int		gnl_fd;
// 	char	*gnl_ptr;
// 	int		i;

// 	gnl_fd = 0;
// 	gnl_ptr = NULL;
	// if (argc < 2)
	// {
	// 	printf("\nEntrer des chaines de charactères en argument.\n\n");
	// 	return (-1);
	// }
	// if (argc == 2)
	// {
	// 	gnl_fd = open("../gnl_test.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	// 	if (gnl_fd == -1)
	// 	{
	// 		printf("open() error.");
	// 		return (-1);
	// 	}
	// 	else
	// 		write(gnl_fd, argv[1], strlen(argv[1]));
	// 	gnl_fd = close(gnl_fd);
	// }
	// else
	// {
	// 	printf(">>> Entrer une seule chaine de charactère");
	// 	return (-1);
	// }
// 	argc = (int)argv[1];
// 	i = 0;
// 	gnl_fd = open("../gnl_test.txt", O_RDONLY);
// 	printf("FD: %d", gnl_fd);
// 	if (gnl_fd < 0)
// 		return (-1);
// 	printf("\n===============|| GNL RESULT ||===============\n");
// 	while (i != -1)
// 	{
// 		gnl_ptr = get_next_line(gnl_fd);
// 		if (!gnl_ptr || gnl_ptr[0] == '\0')
// 			i = -1;
// 		else								  //TEMP	
// 			printf("\n gnl:\n%s", gnl_ptr); //TEMP
// 		free(gnl_ptr);
// 		gnl_ptr = NULL;
// 	}
// 	printf("\n===============||   THE END  ||===============\n\n");
// 	gnl_ptr = get_next_line(gnl_fd);
// 	printf("\n gnl:\n%s", gnl_ptr); //TEMP
// 	gnl_fd = close(gnl_fd);
// 	return (0);
// }

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "getnextline/get_next_line_bonus.h" //
#include <stdio.h> //
#include <fcntl.h> //
#include <string.h> //

int	main(int argc, char **argv)
{
	int		gnl_fd1;
	int		gnl_fd2;
	char	*gnl_ptr1;
	char	*gnl_ptr2;
	int		i;

	gnl_fd1 = 0;
	gnl_fd2 = 0;
	gnl_ptr1 = NULL;
	gnl_ptr2 = NULL;
	if (argc < 3)
	{
		printf("\nEntrer des chaines de charactères en argument.\n\n");
		return (-1);
	}
	if (argc == 3)
	{
		gnl_fd1 = open("bonus_1.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
		if (gnl_fd1 == -1)
		{
			printf("open() error.");
			return (-1);
		}
		else
			write(gnl_fd1, argv[1], strlen(argv[1]));
		gnl_fd1 = close(gnl_fd1);
		gnl_fd2 = open("bonus_2.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
		if (gnl_fd2 == -1)
		{
			printf("open() error.");
			return (-1);
		}
		else
			write(gnl_fd2, argv[2], strlen(argv[2]));
		gnl_fd2 = close(gnl_fd2);
	}
	else
	{
		printf(">>> Entrer deux chaines de charactères");
		return (-1);
	}
	i = 0;
	gnl_fd1 = open("bonus_1.txt", O_RDONLY);
	gnl_fd2 = open("bonus_2.txt", O_RDONLY);
	if (gnl_fd1 < 0)
		return (-1);
	printf("\n===============|| BONUS ||===============\n");
	while (i != -1)
	{
		gnl_ptr1 = get_next_line(gnl_fd1);
		printf("fd_1: %s\n", gnl_ptr1);
		gnl_ptr2 = get_next_line(gnl_fd2);
		printf("fd_2: %s\n", gnl_ptr2);
		if (!gnl_ptr1 && !gnl_ptr2)
			i = -1;
		free(gnl_ptr1);
		gnl_ptr1 = NULL;
		free(gnl_ptr2);
		gnl_ptr2 = NULL;
	}
	printf("\n===============||  THE END ||===============\n\n");
	gnl_fd1 = close(gnl_fd1);
	gnl_fd2 = close(gnl_fd2);
	return (0);
}