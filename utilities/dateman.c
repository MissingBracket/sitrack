#include "./dateman.h"

void print_current_date(){
time_t t = time(NULL);
struct tm tm = *localtime(&t);
printf("%d-%d-%d %d:%d:%d\n", 
	tm.tm_year + 1900, 
	tm.tm_mon + 1, 
	tm.tm_mday, 
	tm.tm_hour, 
	tm.tm_min, 
	tm.tm_sec);
}
int get_day(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return (int)tm.tm_mday;
}

int get_month(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return (int)(tm.tm_mon+1);
}

int get_year(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	return (int)(tm.tm_year + 1900);
}
char* get_date_as_string(){
return "asd";
}