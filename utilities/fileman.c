#include "./dateman.h"
#include "./fileman.h"
#include <errno.h>

const char* config_dir = "./config/dirs";
const char* logs_dir = "./Log";

//char* currentLogDir;

// Loads standard config file
char **get_directories_from_config(){
	FILE* confile = fopen(config_dir, "r");
	if(!confile){
		printf("%s Could not open config file\n", FAIL);
		return NULL;
	}
	int lines;
	fscanf(confile, "%d\n", &lines);
	char **dirs = (char**)malloc(sizeof(char*) * lines);
	
	int current=0;
	char buffer[50];
	while(!feof(confile)){
		fscanf(confile, "%s\n" ,&buffer);
		dirs[current] = buffer;
		current++;
		printf("%s\n", buffer);
	}
	fclose(confile);
}
// Loads User-specified config file
char **get_directories_from_custom_config(char * custom_config){
	FILE* confile = fopen(custom_config, "r");
	if(!confile){
		printf("%s Could not open specified config file\n", FAIL);
		return NULL;
	}
	char buffer[50];
	while(!feof(confile)){
		fscanf(confile, "%s\n" ,&buffer);
		printf("%s\n", buffer);
	}
	fclose(confile);

	return NULL;
}

void printfromfile(){
	int desc = open(config_dir, O_RDONLY);
	if(desc == -1){
		printf("%s Failed to open file\n", FAIL);
		return;
	}else{
		char buff[50] = {'\0'};
		int stat = read(desc, buff, 50);
		printf("%s len = %d\n", buff, stringlen(buff));
		stat = close(desc);
		if(stat ==-1){
			printf("%s Failed to close file\n", FAIL);
		}
	}
}

int calculate_and_save(char *dir){
	char * message = "Test Message\n";
	int changes = 0;
	int desc, save_result;
	desc = open("testfile", O_RDWR|O_APPEND);
	save_result = write(desc, message, stringlen(message));
	if(save_result < 0){
		printf("%s Could not save to file\n", FAIL);
	}
	else{
		printf("%s saved to file successfully\n", SUCC);
	}
	int stat = close(desc);
	switch(stat){
		case 0:
		printf("%s File closed Successfuly\n", SUCC);
		break;
		case -1:
		printf("%s File failed to close\n", FAIL);
		break;
	}	
	return changes;
}
// Returns all calculated hashes
char** calculate_integrity(char **dirs){
	for(int i=0; dirs[i]; i++){
	
	}

}

int stringlen(char* str){
	int count = 0;
	for (int i = 0; str[i]; ++i)
	{
		count++;
	}
	return count;
}

int init_log_directories(){
	print_current_date();
	struct stat st = {0};
	int umaskResult = umask(0);
	char namebuffer[50] = {'\0'};
	printf("%s%o\n","Umask has been set: ", umaskResult);
	int len = sprintf(namebuffer, "%s/%d/%d", logs_dir, get_year(), get_month());
	printf("Result of query : %s\n", namebuffer);
	// Log/Month
	sprintf(namebuffer, "%s/%d", logs_dir, get_year());

	// if year doesn't exists neither does month
	if(stat(namebuffer, &st) < 0){
		int createstatus = mkdir(namebuffer, 0700);
		if(createstatus != -1)	{
			for(int i =0; i < 50; i++)
	   			namebuffer[i] = '\0';
	   		sprintf(namebuffer, "%s/%d/%d", logs_dir, get_year(), get_month());
	   		//printf("Creating new month directory\n");
	   		createstatus = mkdir(namebuffer, 0700);
	   		if(createstatus != -1){
	   			printf("%s\n", "Created both year and month directories");
	   			return 0;
	   		}
		}
	}else{
		//	Year exists - check and maybe create month
		for(int i =0; i < 50; i++)
	   		namebuffer[i] = '\0';
	   	sprintf(namebuffer, "%s/%d/%d", logs_dir, get_year(), get_month());
	   	//	if month doesn't exist create it
	   	if(stat(namebuffer, &st) < 0){
			int createstatus = mkdir(namebuffer, 0700);	   		
			if (createstatus != -1)
			{
				printf("%s\n", "Created only month directory");
				return 0;
			}
	   	}
	   	else{
	   		printf("%s\n", "No need to create anything.");
	   		return 0;
	   	}
	}
	fprintf(stderr, "%s%s Code :%d\n", "Failed whlie creating Log directories: ", strerror(errno), errno);
	return -1;
}

char *get_current_log_directory(){
	char* namebuffer = (char*)malloc(sizeof(char)*20);
	sprintf(namebuffer, "%s/%d/%d", logs_dir, get_year(), get_month());
	return namebuffer;
}

int add_file_to_tracked(char* directory){
	int desc, save_result;
	char *buffer_why_not = (char*)malloc(sizeof(char) * (stringlen(directory) + 1)); //	Is it safe?
	sprintf(buffer_why_not, "%s\n", directory);
	desc = open("./config/tracked", O_RDWR|O_APPEND);
	save_result = write(desc, buffer_why_not, stringlen(buffer_why_not));
	if(save_result < 0){
		printf("%s Could not save to file\n", FAIL);
		int stat = close(desc);
		return -1;
	}
	int stat = close(desc);
	
	return 0;
}