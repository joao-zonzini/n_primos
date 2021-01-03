//referencia de como fazer uma lista linkada
#include <stdlib.h>
#include <stdio.h>

typedef struct list {
  int data;
  struct list *next;
} list;

list *add_to_end(int d, list *head); list *create_list(int d); void print_list(list *head, char *title);
void *delete_item(list *head, int excluido);

int main(void) {
	list *head = NULL;

 	head = create_list(40);
	head = add_to_end(41, head);
	head = add_to_end(42, head);
	print_list(head, "numeros");
  delete_item(head, 41);
  print_list(head, "\nnumeros");

 	printf("\n");
	return 0;
}

void print_list(list *head, char *title) {
	printf("%s\n", title);
	while( head != NULL ){
		printf("%d\t", head->data);
		head = head->next;
	}
}

list *create_list(int d) {
	list *head = malloc(sizeof(list));
	head->data = d;
	head->next = NULL;
	return head;
}

list *add_to_end(int d, list *head){
  list *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  list *add = create_list(d);
  temp->next = add;
  return head;
}

void *delete_item(list *head, int excluido) {
  if (head->data == excluido) {
    head = head->next;
    return;
  }

  list *temp;
  while (head->next != NULL) {
    temp = head;
    head = head->next;
    if (head->data == excluido) {
      temp->next = head->next;
      return;
    }
  }
}
