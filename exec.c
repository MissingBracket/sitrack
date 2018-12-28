#define bool int
#define true 1
#define false 0
#define switches_available 16
#define SWITCH_READ 0
#define SWITCH_TRACK 4
#define SWITCH_UNTRACK 8
//	I try hard to make it clean. Don't mind this mess of comments please
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <sys/fcntl.h>
//#include <unistd.h>
//#include "./utilities/dateman.h"
#include "./utilities/integrman.h"
#include "./utilities/fileman.h"
const float program_version = 0.65;
const char* details = "Ready to execute basic tasks. WIP, though.";

const char* script_dir = "./scripts/";
/*
Switches Convention map
0 - R
1 - d
2 - n
3 - c

*/
/*
	Prints help message
*/
void print_help(){
	printf("Overseer program for GNU / Linux System integrity management\n");
	printf("Version: %.3f\t%s\n", program_version, details);
	printf("Usage:\n");
	printf("oversser [Mainparam][params]\n");
	printf("Available parameters:\n");
	printf("\t-R\tRecalculate current integrity\n");
	printf("\t-d [directory]\tcalculate Hashes only in given directory\n");
	printf("\t-n\tDon't save hashes and print them to screen\n");
	printf("\t-c\tRecalculate hashes and compare them with current\n");
	printf("\t-T\tAdd new file to be tracked\n");
	printf("\t-d [directory]\tAdd entire given directory to tracked list\n");
	printf("\t-n\tPrint hashes of added items to screen\n");
	printf("\t-c\tImmediately calculate hashes for added items\n");
	printf("\t-U\tUntrack file\n");
	printf("\t-d [directory]\tUntrack all files in given directory\n");
	printf("\t-n\tPLACEHOLDER\n");
	printf("\t-c\tRecalculate hashes and save them for the last time\n");
}

void calculate_and_print(char *dir){

}

void manage_database(int request){
/*
Data directory:
dir - MONTH1
		|_differential.dfr
dir - MONTH2
		|_differential.dfr
Output Format:
$cat ./MONTH2/differential.dfr
$CALCULATION_DATE
RECORDS[]={MD5Sum	$FILEPATH}

*/
}
//	[To be implemented and moved to integrity manager]
void calculate_ports(){

}
//	[Makeshift, might ditch it along the way]
char* constr(char* a, char* b){
	int total_len = (stringlen(a) + stringlen(b));
	char* result = (char*)malloc(sizeof(char)*total_len);
	for (int i = 0; i < stringlen(a); ++i){
	if(a[i] != '\0')result[i] = a[i];
	}

	int x = 0;
	for (int i = stringlen(a); i < total_len; ++i){
		result[i] = b[x];
		x++;
	}
	return result;
}
/*
	Sets flags for program functionality
*/
int parse_arguments(char *argv[], int argc){
int switches[switches_available] = {0};
char *READvalue = NULL, *TRACKvalue = NULL, *UNTRACKvalue = NULL;
int c;

opterr = 0;
int offset=0;

	while ((c = getopt (argc, argv, "HhRTUncd:")) != -1)
    switch (c)
    	{
    	case 'h':
    	case 'H':
    		print_help();
    		return -1;
		case 'R':
			switches[SWITCH_READ] = 1;
			offset = SWITCH_READ;
		break;
		case 'T':
			switches[SWITCH_TRACK] = 1;
			offset = SWITCH_TRACK;
		break;
		case 'U':
			switches[SWITCH_UNTRACK] = 1;
			offset = SWITCH_UNTRACK;
		break;
		case 'n':
			switches[offset + 1] = 1;
			//offset = 0;
		break;
		case 'c':
			switches[offset + 2] = 1;
			//offset = 0;
		break;
		case 'd':
			switch(offset){
				case SWITCH_READ:
					READvalue = optarg;
					offset = 0;
				break;
				case SWITCH_TRACK:
					TRACKvalue = optarg;
					offset = 0;
				break;
				case SWITCH_UNTRACK:
					UNTRACKvalue = optarg;
					offset = 0;
				break;
        }
        break;

      	default:
      		printf("Don't know what to do with -> %c <-\n", c);
        	abort ();
      }

    if(switches[SWITCH_READ] > 0){
    	if(READvalue != NULL){
    		//print_from_pointer(READvalue);
			//	n
    		if(switches[SWITCH_READ + 1] > 0)
    			get_latest_file_hash(READvalue);
    		else
    			save_calculation_for_files(get_current_log_directory(), READvalue, switches[2], switches[3]);

    	}
    	else
    		save_calculation_for_files(get_current_log_directory(), NULL, switches[2], switches[3]);
    }
    if(switches[SWITCH_TRACK] > 0){
    	if(TRACKvalue == NULL){
    		printf("No file to track was specified.\n");
    		return -1;
    	}
    	add_file_to_tracked(TRACKvalue);
    }
	if(switches[SWITCH_UNTRACK] > 0){

	}
    return 0;
}

// Forwards date of program call to program's log file [might prove obsolete]
void log_date(){
	system("echo \"Overseer ran for $(whoami)@$(hostname) on:\" >> ./Log/Overseer.log");
	system("date >> ./Log/Overseer.log");
}

//	Prints functionalities that need to be implemented [for me, so i can see what needs to be done]
void tasks(){
	printf("%s\n", "********************");
	char* tasks[] = {"Write scripts"};
	int tasknum = 1;
	for(int i =0; i <tasknum; i++){
		printf("%s\n", tasks[i]);
	}
	printf("%s\n", "********************");
}
void alter_int(int *k){
	*k = 15;
}

//	That's where fun begins
int main(int argc, char* argv[]){
	
	/*call_rebuilder_script_forward("a", "b", "c");
	call_rebuilder_script_backward("a", "b", "c");
	return 1;
*/
	if(argc <2){
		print_help();
		return 0;
	}
	
	int logDir = init_log_directories();
	if(logDir < 0){
		return -1;
	}

	log_date();
	
	int result = parse_arguments(argv,argc);
		if(result == -1){
			return -1;
		}	
	return 0;	//Exit Success
}
