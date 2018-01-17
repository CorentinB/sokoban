/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** Main function for the my_sokoban
*/

#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/libmy.h"
#include "../include/sokoban.h"

char *open_map(char const *path)
{
	int reading;
	char *buffer;

	reading = open(path, O_RDONLY);
	if (reading == -1) {
		write(2, "No such file or directory\n", 26);
		exit (84);
	}
	buffer = read_map(reading);
	close(reading);
	return (buffer);
}

char *read_map(int reading)
{
	char *buffer = malloc(sizeof(char) * 10000);
	int size = 32;

	size = read(reading, buffer, 10000);
	if (size == -1)
		exit(84);
	return (buffer);
}

int count_columns(sokoban_t sokoban, int position)
{
	int columns = 0;

	for (; sokoban.buffer[position] != '\n'; position++) {
		columns++;
	}
	return (columns);
}

sokoban_t count_lines(sokoban_t sokoban)
{
	sokoban.lines = 0;

	for (int i = 0; sokoban.buffer[i] != '\0'; i++) {
		if (sokoban.buffer[i] == '\n' || sokoban.buffer[i] == '\0')
			sokoban.lines++;
	}
	return (sokoban);
}

sokoban_t make_map(char const *path, sokoban_t sokoban)
{
	sokoban.buffer = open_map(path);
	sokoban = count_lines(sokoban);
	int k = 0;
	int columns = 0;

	sokoban.map = malloc(sizeof (char *) * sokoban.lines);
	sokoban.map_save = malloc(sizeof (char *) * sokoban.lines);
	for (int j = 0; j < sokoban.lines; j++) {
		columns = count_columns(sokoban, k);
		sokoban.map[j] = malloc(sizeof(char) * columns + 1);
		sokoban.map_save[j] = malloc(sizeof(char) * columns + 1);
		for (int i = 0; i < columns; i++) {
			sokoban.map[j][i] = sokoban.buffer[k];
			sokoban.map_save[j][i] = sokoban.buffer[k];
			sokoban.map[j][i+1] = '\0';
			sokoban.map_save[j][i+1] = '\0';
			k++;
		}
		k++;
	}
	return (sokoban);
}
