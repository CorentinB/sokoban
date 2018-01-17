/*
** EPITECH PROJECT, 2017
** bsq.h
** File description:
** Contain all the prototypes needed for BSQ
*/

#ifndef BSQ_H
#define BSQ_H
	typedef struct sokoban {
		char *buffer;
		char **map;
		char **map_save;
		int lines;
		int player_x;
		int player_y;
		char const *base_path;
		int win;
		int storage_number;
		int storage_won;
		int case_number;
	} sokoban_t;
	int helper(void);
	char *read_map(int reading);
	char *open_map(char const *path);
	sokoban_t make_map(char const *path, sokoban_t sokoban);
	int play(char const *path);
	sokoban_t count_lines(sokoban_t sokoban);
	int count_columns(sokoban_t sokoban, int position);
	sokoban_t check_if_player(sokoban_t sokoban, int y, int x);
	sokoban_t find_player(sokoban_t sokoban);
	sokoban_t key_check(sokoban_t sokoban, int key);
	sokoban_t move_right(sokoban_t sokoban);
	sokoban_t move_left(sokoban_t sokoban);
	sokoban_t move_up(sokoban_t sokoban);
	sokoban_t move_down(sokoban_t sokoban);
	sokoban_t move_box_left(sokoban_t sokoban);
	sokoban_t move_box_right(sokoban_t sokoban);
	sokoban_t move_box_up(sokoban_t sokoban);
	sokoban_t move_box_down(sokoban_t sokoban);
	void win_check(sokoban_t sokoban);
	int count_storage_zone(int y, int x, sokoban_t sokoban);
	int count_storage_won(int y, int x, sokoban_t sokoban);
	sokoban_t check_zone_reset(sokoban_t sokoban);
	sokoban_t reset_zone(int y, int x, sokoban_t sokoban);
	void loose_check(sokoban_t sokoban);
	void storage_loose_check(int y, int x, sokoban_t sokoban);
	void map_check(sokoban_t sokoban);
	int count_case_number(int y, int x, sokoban_t sokoban);
	int count_player(int y, int x, sokoban_t sokoban);
	sokoban_t game_management(sokoban_t sokoban);
	int check_tile(int y, int x, sokoban_t sokoban);
#endif
