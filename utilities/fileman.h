/*
Manages file related functions such as calculating checksums
and recording them in local database
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define INFO "[INFO]"
#define FAIL "[FAIL]"
#define SUCC "[SUCC]"

//	Load configuration file from default config file
struct list *get_directories_from_config();
//	Load configuration file from provided config file
struct list *get_directories_from_custom_config(char * custom_config);
//	Read and print config file
void printfromfile();
//	Calculate integrity of file in given directory and save to database
int calculate_and_save(char *dir);
//	Calculate integrity of files in given directories and save to database
char calculate_integrity(char **dirs);
//	Calculate length of string
int stringlen(char* str);
//	First run method, creates log directories and template files
int init_log_directories();
//	Returns directory path for current month log file
char* get_current_log_directory();
//	Adds a file to be tracked by the program
int add_file_to_tracked(char* directory);
//	
int save_calculation_for_files(char *output, char *input, int n, int c);
void print_from_pointer(char * ptr);