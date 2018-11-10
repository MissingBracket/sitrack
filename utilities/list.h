#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct list{
	char directory[255];
	struct list *next;
};

struct list* list_insert(struct list* head, char dir[255]);

struct list* list_clear(struct list* head);