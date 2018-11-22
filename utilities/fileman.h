/*
Manages file related functions such as calculating checksums
and recording them in local database
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "./dateman.h"

#define INFO "[INFO]"
#define FAIL "[FAIL]"
#define SUCC "[SUCC]"

//	Load configuration file from default config file
struct list *get_directories_from_config();
//	Load configuration file from provided config file
struct list *get_directories_from_custom_config(char * custom_config);
//	Read and print config file
void printfromfile();
//	Obsolete []
void print_from_pointer(char * ptr);
//	Calculate integrity of file in given directory and save to database
int calculate_and_save(char *dir);
//	Calculate length of string
int stringlen(char* str);
//	First run method, creates log directories and template files
int init_log_directories();
//	Adds a file to be tracked by the program
int add_file_to_tracked(char* directory);
//	
int save_calculation_for_files(char *output, char *input, int n, int c);
//	Calculate integrity of files in given directories and save to database
char calculate_integrity(char **dirs);
//	Returns directory path for current month log file
char* get_current_log_directory();
//	Returns filename for current log file
char* get_current_log_file_name();
//	Returns hash for given filename
char* get_file_hash(char* file);
//	Fetch constant parameter by name
char* get_program_parameter(char* param);
