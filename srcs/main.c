/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 23:06:58 by khirsig           #+#    #+#             */
/*   Updated: 2021/12/22 13:51:32 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	ft_bzero(&data, sizeof(t_data));
	printf("PARSER\n");
	parser(&data, argv[1]);
	printf("INITIALIZER\n");
	initializer(&data);
	printf("GAMELOOP\n");
	gameloop(&data);
	CloseWindow();
	return (0);
}