/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Function for finding the player on the map
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

sokoban_t find_player(sokoban_t sokoban)
{
	sokoban.player_x = 0;
	sokoban.player_y = 0;
	for (int i = 0; i < sokoban.lines; i++) {
		for (int j = 0; sokoban.map[i][j] != '\0'; j++) {
			sokoban = check_if_player(sokoban, i, j);
		}
	}
	return (sokoban);
}

sokoban_t check_if_player(sokoban_t sokoban, int y, int x)
{
	if (sokoban.map[y][x] == 'P') {
		sokoban.player_x = x;
		sokoban.player_y = y;
	}
	return (sokoban);
}
