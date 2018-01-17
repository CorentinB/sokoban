/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Function that manage moving box
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

sokoban_t move_box_left(sokoban_t sokoban)
{
	if (sokoban.map[sokoban.player_y][sokoban.player_x-2] == 'X') {
		return (sokoban);
	} else if (sokoban.map[sokoban.player_y][sokoban.player_x-2] == '#') {
		return (sokoban);
	} else {
		sokoban.map[sokoban.player_y][sokoban.player_x-1] = 'P';
		sokoban.map[sokoban.player_y][sokoban.player_x-2] = 'X';
		sokoban.map[sokoban.player_y][sokoban.player_x] = ' ';
		sokoban.player_x--;
	}
	return (sokoban);
}

sokoban_t move_box_right(sokoban_t sokoban)
{
	if (sokoban.map[sokoban.player_y][sokoban.player_x+2] == 'X') {
		return (sokoban);
	} else if (sokoban.map[sokoban.player_y][sokoban.player_x+2] == '#') {
		return (sokoban);
	} else {
		sokoban.map[sokoban.player_y][sokoban.player_x+1] = 'P';
		sokoban.map[sokoban.player_y][sokoban.player_x+2] = 'X';
		sokoban.map[sokoban.player_y][sokoban.player_x] = ' ';
		sokoban.player_x++;
	}
	return (sokoban);
}

sokoban_t move_box_up(sokoban_t sokoban)
{
	if (sokoban.map[sokoban.player_y-2][sokoban.player_x] == 'X') {
		return (sokoban);
	} else if (sokoban.map[sokoban.player_y-2][sokoban.player_x] == '#') {
		return (sokoban);
	} else {
		sokoban.map[sokoban.player_y-1][sokoban.player_x] = 'P';
		sokoban.map[sokoban.player_y-2][sokoban.player_x] = 'X';
		sokoban.map[sokoban.player_y][sokoban.player_x] = ' ';
		sokoban.player_y--;
	}
	return (sokoban);
}

sokoban_t move_box_down(sokoban_t sokoban)
{
	if (sokoban.map[sokoban.player_y+2][sokoban.player_x] == 'X') {
		return (sokoban);
	} else if (sokoban.map[sokoban.player_y+2][sokoban.player_x] == '#') {
		return (sokoban);
	} else {
		sokoban.map[sokoban.player_y+1][sokoban.player_x] = 'P';
		sokoban.map[sokoban.player_y+2][sokoban.player_x] = 'X';
		sokoban.map[sokoban.player_y][sokoban.player_x] = ' ';
		sokoban.player_y++;
	}
	return (sokoban);
}
