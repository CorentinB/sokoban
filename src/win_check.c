/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Function that check if the game is won
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

void win_check(sokoban_t sokoban)
{
	int storage_number = 0;
	int storage_won = 0;

	for (int i = 0; i < sokoban.lines; i++) {
		for (int j = 0; sokoban.map_save[i][j] != '\0'; j++) {
			storage_number += count_storage_zone(i, j, sokoban);
		}
	}
	for (int i = 0; i < sokoban.lines; i++) {
		for (int j = 0; sokoban.map_save[i][j] != '\0'; j++) {
			storage_won += count_storage_won(i, j, sokoban);
		}
	}
	if (storage_won == storage_number) {
		endwin();
		exit (0);
	}
}

int count_storage_zone(int y, int x, sokoban_t sokoban)
{
	int i = 0;

	if (sokoban.map_save[y][x] == 'O') {
		i++;
	}
	return (i);
}

int count_storage_won(int y, int x, sokoban_t sokoban)
{
	int i = 0;

	if (sokoban.map_save[y][x] == 'O' && sokoban.map[y][x] == 'X') {
		i++;
	}
	return (i);
}
