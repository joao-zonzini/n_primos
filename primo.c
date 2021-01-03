#include <stdlib.h>
#include <stdio.h>

typedef struct list {
  int data;
  struct list *next;
} list;

int verificar_primo(int n_avaliado);list *add_to_end(int d, list *head); list *create_list(int d); void print_list(list *head, char *title);
void *delete_item(list *head, int excluido);

int main(int argc, char const *argv[]) {

  argc < 3 ? exit(0) : "";

  list *h_primos;
  int n_avaliado = atoi(argv[1]);
  int n_limite = atoi(argv[2]);

  h_primos = create_list(2);

  while (n_avaliado < n_limite) {
    if (verificar_primo(n_avaliado)) {
      h_primos = add_to_end(n_avaliado, h_primos);
    }
    n_avaliado++;
  }

  delete_item(h_primos, 4);
  print_list(h_primos, "Seus numeros primos: ");

  puts("");

  return 0;
}

int verificar_primo(int n_avaliado) {
  for (int divisor = 2; divisor < n_avaliado/2; divisor++) {
    if (n_avaliado % divisor == 0) {
      return 0;
    }
  }
  return 1;
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
