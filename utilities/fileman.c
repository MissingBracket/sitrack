
#include "./fileman.h"
#include "./integrman.h"
#include <errno.h>


char* config_dir = "./config/dirs";
char* constants_dir = "./config/constants";
const char* logs_dir = "./Log";

//char* currentLogDir;

// Loads standard config file
struct list *get_directories_from_config(){
	struct list *ptr = get_directories_from_custom_config(config_dir);
	return ptr;
}
// Loads User-specified config file
struct list *get_directories_from_custom_config(char * custom_config){
	struct list *directories = NULL;
	FILE* confile = fopen(custom_config, "r");
	if(!confile){
		printf("%s Could not open specified config file: %s\n", FAIL, custom_config);
		return NULL;
	}
	char buffer[256] = {'\0'};
	//char *buffer;
	while(!feof(confile)){
		buffer[255]='\0';
		fscanf(confile, "%s\n" ,buffer);
		directories = list_insert(directories, buffer);
		for(int i =0; i < 255; i++)
			buffer[i] = '\0';
	}

	fclose(confile);
	return directories;
}



void printfromfile(){
	int desc = open(config_dir, O_RDONLY);
	if(desc == -1){
		printf("%s Failed to open file\n", FAIL);
		return;
	}else{
		char buff[50] = {'\0'};
		//int stat = 
		while(read(desc, buff, 10) > 0)
			printf("%s len = %d\n", buff, stringlen(buff));
		int stat = close(desc);
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
char calculate_integrity(char **dirs){
	for(int i=0; dirs[i]; i++){
	
	}
	
	return 'a';
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
	printf("Result of query : %s with length of: %d\n", namebuffer, len);
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

char* get_current_log_file_name(){
	char* namebuffer = (char*)malloc(sizeof(char)*33);
	sprintf(namebuffer, "%s/%d/%d/differential\0", logs_dir, get_year(), get_month());
	return namebuffer;	
}
char* get_program_parameter(char* param){
	FILE* constants = fopen(constants_dir, "r");

	if(constants == NULL){
		fprintf(stderr, "Could not access constants file! This is a critical file.");
		return NULL;
	}
	char *line;
	size_t len=0;
	char *parameter;
	char *prefix;
	int failsafe=0;
	while(getline(&line, &len, constants) != -1){
		prefix = strtok_r(line, "=", &parameter);
		if(compare_checksums(prefix, param) == 1){
			fclose(constants);
			return parameter;		
		}
		failsafe++;
		if(failsafe >= 100)
			break;
	}
	fclose(constants);
	return NULL;
}

char* get_file_hash(char* file){
	char filename[32] = {'\0'};
	char *buffer;
	int read=-1;
	int beg_month = 0, beg_year = 0;
	
	(void)sscanf(get_program_parameter("record_begin"), "%d/%d/", &beg_year, &beg_month);
	
	while(beg_year <= get_year() && beg_month <= get_month()){
		int failsafe = 0;
		printf("Checking for : %d/%d\n", beg_year, beg_month);
		char namebuffer[32] = {'\0'};
		sprintf(namebuffer, "./Log/%d/%d/differential", beg_year, beg_month);
		char *hash, *filename;
		char *line;
		size_t len=0;
		if(access(namebuffer, F_OK) != -1){
			
			FILE* log_file = fopen(namebuffer, "r");
			failsafe ++;
			while(getline(&line, &len, log_file) != -1){
				hash = strtok_r(line, ".", &filename);
				strtok(filename, "\n");
				if(compare_checksums(filename, file) == 1){
					printf("Found: %s\n", hash);
					fclose(log_file);
					return hash;		
				}
				failsafe++;
				if(failsafe >= 1000)
					break;
			}
			fclose(log_file);
		}
		get_next_date_to_variables(&beg_year, &beg_month);
	}
	printf("Failed to find entry for %s\n", file);
	return NULL;
}

int add_file_to_tracked(char* directory){
	int desc, save_result, stat;
	char *buffer_why_not = (char*)malloc(sizeof(char) * (stringlen(directory) + 1)); //	Is it safe?
	sprintf(buffer_why_not, "%s\n", directory);
	desc = open("./config/dirs", O_RDWR|O_APPEND);
	save_result = write(desc, buffer_why_not, strlen(buffer_why_not));
	if(save_result < 0){
		printf("%s Could not save to file\n", FAIL);
		if((stat = close(desc)) < 0){
			printf("Failed to close file.\n");
			return -1;
		}
		return -1;
	}
	if((stat = close(desc)) < 0)
		return -1;
	printf("Successfully appended %s to tracked file list.\n", directory);
	return 0;
}

void print_from_pointer(char * ptr){
	printf("A value is : %s\n", ptr);
}

int save_calculation_for_files(char *output, char* input, int n, int c){
	int changes = 0;
	struct list *head= NULL;
	struct list *ptr= NULL;
	char *config_to_work_on;
	
	if(input != NULL)
		config_to_work_on = input;
	else
		config_to_work_on = config_dir;
	FILE *config_file = fopen(config_to_work_on, "r");
	if(config_file == NULL){
		printf("Configuration file does not exist: %s\n", config_to_work_on);
		return -1;
	}

	while(!feof(config_file)){
		char buffer[256] = {'\0'};
		fscanf(config_file, "%s\n", buffer);
		head = list_insert(head, buffer);
	}
	ptr = head;
	fclose(config_file);
	printf("Output argument: %s\n", output);
	printf("Input argument: %s\n", input);
	while(ptr != NULL){
		changes++;
		printf("Val : %s\n", ptr->directory);
		call_calculate_script(ptr->directory, output, 0, 0, 0);
		ptr = ptr->next;
	}
	head = list_clear(head);
	printf("Finished Calculating for %d entries.\n", changes);
	return changes;
}
