/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Check zone
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

sokoban_t check_zone_reset(sokoban_t sokoban)
{
	for (int i = 0; i < sokoban.lines; i++) {
		for (int j = 0; sokoban.map_save[i][j] != '\0'; j++) {
			sokoban = reset_zone(i, j, sokoban);
		}
	}
	return (sokoban);
}

sokoban_t reset_zone(int y, int x, sokoban_t sokoban)
{
	if (sokoban.map_save[y][x] == 'O' && sokoban.map[y][x] == ' ') {
		sokoban.map[y][x] = sokoban.map_save[y][x];
		return(sokoban);
	}
	return (sokoban);
}
