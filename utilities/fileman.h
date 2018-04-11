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
char **get_directories_from_config();
//	Load configuration file from provided config file
char **get_directories_from_custom_config(char * custom_config);
//	Read and print config file
void printfromfile();
//	Calculate integrity of file in given directory and save to database
int calculate_and_save(char *dir);
//	Calculate integrity of files in given directories and save to database
char** calculate_integrity(char **dirs);
//	Calculate length of string
int stringlen(char* str);
//	First run method, creates log directories and template files
void init_log_directories();