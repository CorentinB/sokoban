/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Function that manage the game
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

int play(char const *path)
{
	sokoban_t sokoban = make_map(path, sokoban);
	map_check(sokoban);
	sokoban = find_player(sokoban);
	sokoban.base_path = path;

	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	clear();
	refresh();
	while (1) {
		refresh();
		for (int i = 0; i < sokoban.lines; i++)
			mvprintw(i, 0, sokoban.map[i]);
		move(sokoban.player_y, sokoban.player_x);
		sokoban = game_management(sokoban);
	}
}

sokoban_t game_management(sokoban_t sokoban)
{
	int key_pressed = 0;

	key_pressed = getch();
	sokoban = key_check(sokoban, key_pressed);
	sokoban = check_zone_reset(sokoban);
	loose_check(sokoban);
	win_check(sokoban);
	return (sokoban);
}
