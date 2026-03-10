#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void dll_insert_head(), dll_insert_tail_head(), dll_insert();
void dll_update(), dll_delete();
void dll_print(), dll_rev_print();

struct NODE {
	struct NODE* prev;
	int ID;
	int value;
	struct NODE* next;
};

struct NODE* head;
struct NODE* tail;
struct NODE* ptr;

int main() {
	head = NULL;
	int index, flag = 0;

	while (flag == 0) {
		printf("Enter [(1) Insert (2) Update (3) Delete (4) Print (5) Exit]:\t");
		scanf("%d", &index);

		if (index == 1) {
			printf("Enter [(1) insert-head (2) insert-tail (3) insert-middle]:\t");
			scanf("%d", &index);
			if (index == 1) { dll_insert_head(); }
			else if (index == 2) { dll_insert_tail_head(); }
			else if (index == 3) { dll_insert(); }
			else { printf("enter again (1~3)"); }
		}
		else if (index == 2) { dll_update(); }
		else if (index == 3) { dll_delete(); }
		else if(index == 4){
			printf("Enter [(1) print-forward (2) print-reverse]:\t");
			scanf("%d", &index);
			if (index == 1) { dll_print(); }
			else if (index == 2) { dll_rev_print(); }
			else{ printf("enter again (1~2)"); }
		}
		else if (index == 5) { printf("Exit\n"); flag = 1; }
		else { printf("enter again (1~5)"); }
	}
	return 0;
}

void dll_insert_head()
{
	int insert_ID, insert_value;
	printf("ID, value: ");
	scanf("%d %d", &insert_ID, &insert_value);
	ptr = (struct NODE*)malloc(sizeof(struct NODE));
	ptr->ID = insert_ID;
	ptr->value = insert_value;
	ptr->prev = NULL;
	ptr->next = NULL;

	if (head == NULL) { tail = ptr; }
	else { ptr->next = head; head->prev = ptr; }
	head = ptr;

	while (ptr->next != NULL) {
		ptr = ptr->next;
		ptr->ID = ptr->ID + 1;
	}

}

void dll_insert_tail_head()
{
	int insert_ID, insert_value;
	printf("ID, value: ");
	scanf("%d %d", &insert_ID, &insert_value);
	ptr = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == NULL) { head = ptr; }
	else { tail->next = ptr; ptr->prev = tail; }

	ptr->ID = insert_ID;
	ptr->value = insert_value;
	ptr->next = NULL;
	ptr->prev = tail;
	tail = ptr;
}

void dll_insert()
{
	int insert_ID, insert_value;
	printf("ID, value: ");
	scanf("%d %d", &insert_ID, &insert_value);
	ptr = (struct NODE*)malloc(sizeof(struct NODE));
	ptr->ID = insert_ID;
	ptr->value = insert_value;
	ptr->prev = NULL;
	ptr->next = NULL;

	struct NODE* tmp;
	tmp = head;

	while (tmp != NULL) {
		if (tmp->ID == insert_ID) {
			if (head == NULL) { tail = ptr; }
			else { ptr->next = head; head->prev = ptr; }
			head = ptr;

			while (ptr->next != NULL) {
				ptr = ptr->next;
				ptr->ID = ptr->ID + 1;
			}
			return;
		}
		else if (tmp->ID == insert_ID - 1) {
			ptr->next = tmp->next;
			ptr->prev = tmp;

			if (tmp->next != NULL) { tmp->next->prev = ptr; }
			else { tail = ptr; }

			tmp->next = ptr;
			while (ptr->next != NULL) {
				ptr = ptr->next;
				ptr->ID = ptr->ID + 1;
			}
			return;
		}

		tmp = tmp->next;
	}
}

void dll_update()
{
	int update_ID, update_value;
	printf("ID for update: ");
	scanf("%d", &update_ID);
	ptr = head;

	while (ptr != NULL) {
		if (ptr->ID == update_ID) {
			printf("Enter the value: ");
			scanf("%d", &update_value);
			ptr->value = update_value;
			return;
		}
		ptr = ptr->next;
	}
}

void dll_delete()
{
	int delete_ID;
	printf("ID for delete: ");
	scanf("%d", &delete_ID);
	ptr = head;

	if (ptr->ID == delete_ID) {
		head = ptr->next;
		head->prev = NULL; 
		head->ID -= 1;
		free(ptr);

		ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
			ptr->ID = ptr->ID - 1;
		}
		return;
	}

	while (ptr != NULL) {
		tail = ptr;
		ptr = ptr->next;
		if (ptr->ID == delete_ID) {
			tail->next = ptr->next;

			if (ptr->next != NULL) { ptr->next->prev = ptr->prev; }
			free(ptr);

			while (tail->next != NULL) {
				tail = tail->next;
				tail->ID  = tail->ID - 1;
			}
			return;
		}
	}
}

void dll_print()
{
	ptr = head;
	printf("(ID, value): ");
	while (ptr != NULL) {
		printf("(%d, %d)", ptr->ID, ptr->value);
		ptr = ptr->next;
	}
	printf("\n");
	return;
}

void dll_rev_print()
{
	ptr = tail;
	printf("(ID, value): ");
	while (ptr != NULL) {
		printf("(%d, %d)", ptr->ID, ptr->value);
		ptr = ptr->prev;
	}
	printf("\n");
	return;
}