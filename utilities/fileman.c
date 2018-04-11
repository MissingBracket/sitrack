#include "./dateman.h"
#include "./fileman.h"

const char* config_dir = "./config/dirs";
const char* logs_dir = "./Log";

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
void init_log_directories(){
	print_current_date();
	struct stat st = {0};
	char namebuffer[50] = {'\0'};
	int len = sprintf(namebuffer, "%s/%d/%d", logs_dir, get_year(), get_month());
	printf("Result of query : %s\n", namebuffer);
	if (stat("./Log/2018/3", &st) == -1) {
	    printf("No such directory\n");
	   int createstatus = mkdir("./Log/2018/3", 0700); // Cannot create directory
	   printf("created?L %d\n", createstatus);
	}
}