#include "chain.h"

struct chain *chain_insert(struct chain* head, char* dir, int len){
	printf("Input: %s\n", dir);
	struct chain * ptr = (struct chain *)malloc(sizeof(struct chain));

	ptr->directory = (char*)calloc(len+1, sizeof(char));
	for(int i = 0; i < len ; i++){
		ptr->directory[i] = dir[i];
	}
	ptr->directory[len] = '\0';
	ptr->next = head;
	return ptr;
}

struct chain *chain_clear(struct chain *head){
	struct chain* ptr;
	while(head != NULL){
		ptr = head->next;
		free(head);
		head = ptr;
	}
	return ptr;
}

void chain_print(struct chain * head){
	struct chain* ptr = head;
	while(ptr!= NULL){
		printf("Element:\t");
		printf("%s\n", ptr->directory);
		ptr = ptr->next;
	}
}