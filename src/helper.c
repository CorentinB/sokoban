/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Main function for the my_sokoban
*/

#include <unistd.h>
#include "../include/libmy.h"

int helper(void)
{
	my_putstr("USAGE\n");
	my_putstr("	./my_sokoban map\n\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("	map file representing the warehouse map, containing '#'");
	my_putstr(" for walls, 'P' for the player, 'X' for boxes and 'O'");
	my_putstr("for storage locations.\n");
	return (0);
}
