/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Functions used to check if the game is loosed
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

void loose_check(sokoban_t sokoban)
{
	for (int i = 0; i < sokoban.lines; i++) {
		for (int j = 0; sokoban.map_save[i][j] != '\0'; j++) {
			storage_loose_check(i, j, sokoban);
		}
	}
}

void storage_loose_check(int y, int x, sokoban_t sokoban)
{
	if (sokoban.map[y][x] == 'X') {
		if (((sokoban.map[y][x+1] == '#' && sokoban.map[y+1][x] == '#') ||
		(sokoban.map[y+1][x] == '#' && sokoban.map[y][x-1] == '#') ||
		(sokoban.map[y][x-1] == '#' && sokoban.map[y-1][x] == '#') ||
		(sokoban.map[y-1][x] == '#' && sokoban.map[y][x+1] == '#')) &&
		sokoban.map_save[y][x] != 'O') {
			endwin();
			exit (1);
		}
	}
}
