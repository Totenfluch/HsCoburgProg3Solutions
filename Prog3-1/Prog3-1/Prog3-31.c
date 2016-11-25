#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define DATLENGTH  11

struct Element {
	char datum[DATLENGTH];
	unsigned tagesproduktion;
	struct Element* next;
};

struct List {
	struct Element*	first;
	struct Element*	last;
};

/* Definition des Funktionszeigers */
typedef int(*ItemFunction) (struct Element*);

/* Header der Funktionen */
void init(struct List *list);
void insert(struct List *list, int val, char* dat);
int removeElements(struct List *list, int val);
int clear(struct List *list);
int forall(struct List *list, ItemFunction exec);
int printItem(struct Element *element);
void print(struct List *list);
int empty(struct List *list);
int compare(struct Element *elem1, struct Element *elem2);
int removeMaximum(struct List *list);

void init(struct List *list) {
	list->first = NULL;
	list->last = NULL;
}

void insert(struct List *list, int val, char* dat) {
	struct Element * e = (struct Element *)malloc(sizeof(struct Element));
	e->tagesproduktion = val;
	strncpy(e->datum, dat, DATLENGTH);


	e->next = list->first;
	list->first = e;

	if (!list->last) {
		list->last = e;
	}

}

int removeElements(struct List *list, int val) {
	if (list->first == NULL)
		return -1; // Leere Liste
	struct Element * e = list->first;
	struct Element * e2 = list->first;
	struct Element * removeable;
	if (!e)
		return -1;

	int removed = 0;
	while (e) {
		if (e->tagesproduktion == val) {
			if (e == list->first) {
				list->first = e->next;
				if (e == list->last)
					list->last = NULL;
			}
			else {
				e2->next = e->next;
				removeable = e;
				e = e->next;
				free(removeable);
				removed++;
			}
		}
		else {
			e2 = e;
			e = e->next;
		}
	}
}

int clear(struct List *list) {
	struct Element * e = list->first;
	if (!e)
		return -1;
	while (e) {
		struct Element* p = e;
		e = e->next;
		free(p);
	}

	init(list);
	return 1;
}

int forall(struct List *list, ItemFunction exec) {
	int foralls = 0;
	struct Element * e = list->first;
	if (!e)
		return 0;

	for (e = list->first; e; e = e->next) {
		exec(e);
		foralls++;
	}
	return foralls;
}

int printItem(struct Element* element) {
	printf("%s: %d\n", element->datum, element->tagesproduktion);
	return 1;
}

void print(struct List *list) {
	forall(list, printItem);
}

int empty(struct List *list) {
	return !list->first;
}

int compare(struct Element *elem1, struct Element *elem2) {
	if (!elem1 || !elem2)
		return -2;
	int t1 = elem1->tagesproduktion;
	int t2 = elem2->tagesproduktion;

	if (t1 == t2)
		return 0;
	else if (t1 < t2)
		return -1;
	else
		return 1;
}

int removeMaximum(struct List *list) {
	struct Element * e = list->first;
	struct Element * max = list->first;
	if (!e)
		return 0;

	for (e = list->first; e; e = e->next) {
		if (compare(e, max) == 1)
			max = e;
	}
	int rValue = max->tagesproduktion;
	removeElements(list, rValue);
	return rValue;
}


int main(int argc, char *argv[])
{
	struct List list;
	init(&list);
	insert(&list, 1, "18.11.11");
	insert(&list, 1, "19.11.11");
	insert(&list, 5, "20.11.11");
	insert(&list, 5, "21.11.11");
	insert(&list, 0, "22.11.11");
	print(&list);
	printf("-------\n");
	removeElements(&list, 1);
	print(&list);
	printf("-------\n");
	removeElements(&list, 0);
	print(&list);
	printf("-------\n");
	removeElements(&list, 5);
	print(&list);
	printf("-------\n");
	insert(&list, 1, "18.11.11");
	insert(&list, 1, "19.11.11");
	insert(&list, 5, "20.11.11");
	insert(&list, 5, "21.11.11");
	insert(&list, 0, "22.11.11");
	printf("Max: %i\n", removeMaximum(&list));
	print(&list);
	printf("-------\n");
	clear(&list);

	_getch();
	return 0;
}