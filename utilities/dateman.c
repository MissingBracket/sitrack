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
//	Added comment
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
	strftime(formatted_date, sizeof(struct tm) + 1, "%F-%s", &tim);
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
time_t convert_date_to_seconds(int y, int mo, int d, int h, int mi, int s){
	struct tm given = { s, mi, h, d, mo-1, y-1900 };
	time_t seconds = mktime(&given);
	return seconds;
}
char* get_timestamp_as_string(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char *formatted_date = (char*)malloc(sizeof(char) * 128);
	sprintf(formatted_date, "%d", mktime(&tm));
	return formatted_date;
}
time_t convert_date_string_to_seconds(char* string){
	int param_beg_month = 0, 
		param_beg_year = 0, 
		param_beg_day = 0, 
		param_beg_hour = 0, 
		param_beg_minute = 0,
		param_beg_second;
		(void)sscanf(string, "%d-%d-%d-%d-%d-%d", &param_beg_year, &param_beg_month, &param_beg_day, &param_beg_hour, &param_beg_minute, &param_beg_second);
	return convert_date_to_seconds(param_beg_year, param_beg_month, param_beg_day, param_beg_hour, param_beg_minute, param_beg_second);
}