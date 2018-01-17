/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Function that manage key press for sokoban
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

sokoban_t key_check(sokoban_t sokoban, int key)
{
	if (key == KEY_LEFT) {
		sokoban = move_left(sokoban);
	}
	if (key == KEY_RIGHT)
		sokoban = move_right(sokoban);
	if (key == KEY_UP)
		sokoban = move_up(sokoban);
	if (key == KEY_DOWN)
		sokoban = move_down(sokoban);
	if (key == ' ')
		play(sokoban.base_path);
	return (sokoban);
}
