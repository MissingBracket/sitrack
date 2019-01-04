/*
Date manager for managing log functionality
*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

//	I think below functions are self explanatory
void print_current_date();

int get_day();

int get_month();

int get_year();

char* get_date_as_string();

char* get_timestamp_as_string();

char* get_next_date(int year, int month);

void get_next_date_to_variables(int *year, int *month);

time_t convert_date_to_seconds(int y, int mo, int d, int h, int mi);

int compare_timestamps(char* stamp1, char* stamp2);