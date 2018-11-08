//	Dynamic structure to store strings

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//	Structure to keep directories in a list
struct chain{
	char* directory;
	struct chain* next;
};

struct chain *chain_insert(struct chain* head, char* dir, int len);/*{
	struct chain * ptr = (struct chain *)malloc(sizeof(struct chain));
	ptr->directory = dir;
	ptr->next = head;
	return ptr;
}
*/
struct chain *chain_clear(struct chain *head);
/*{
	struct chain* ptr;
	while(head != NULL){
		ptr = head->next;
		free(head);
		head = ptr;
	}
	return ptr;
}*/
void chain_print(struct chain * head);/*
{
	while(head!= NULL){
		printf("Element: %s\n", head->directory);
		head = head->next;
	}
}*/
