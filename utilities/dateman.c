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
	time_t t = time(NULL);
	const struct tm tim = *localtime(&t);
	char *formatted_date = (char*)malloc(sizeof(struct tm) + 1);
	strftime(formatted_date, sizeof(struct tm) + 1, "%F", &tim);
	return formatted_date;
}
char* get_next_date(int year, int month){
	int n_year = (month == 12 ? year+1 : year), 
	n_month = (((month) % 12) + 1);
	char* nextDate = (char*)malloc(sizeof(char)*10);
	sprintf(nextDate, "%d/%d/", n_year, n_month);
	return nextDate;
}
void get_next_date_to_variables(int *year, int *month){
	*year = (*month == 12 ? (*year) +1 : *year), 
	*month = (((*month) % 12) + 1);
}