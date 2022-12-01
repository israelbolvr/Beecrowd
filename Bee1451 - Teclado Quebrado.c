#include <stdio.h>
#include <stdlib.h>

typedef struct No{
  char frase;
  struct No*next;
}No;

typedef struct{
  No*head;
  No*last;
}Lista;

void add_inicio(Lista*lista, char key, int posicao){
  No *aux, *elemento = (No*)malloc(sizeof(No));
  elemento->frase = key;
  if(lista->head == NULL){
    lista->head = elemento;
    lista->last = elemento;
    elemento->next = NULL;
  }
  else if(posicao == 0){
    elemento->next = lista->head;
    lista->head = elemento;
  }else{
    aux = lista->head;
    for (int c = 1; c < posicao; c++){
      aux = aux -> next;
    }
    elemento->next = aux->next;
    aux->next = elemento;
  }if(elemento->next == NULL){
    lista->last = elemento;
  }
}

void add_final(Lista*lista, char key){
  No *elemento = (No*)malloc(sizeof(No));
  elemento->frase = key;
  elemento->next = NULL;
  if(lista->head == NULL)
    lista->head = elemento;
  else{
    (lista->last)->next = elemento;
  }
  lista->last = elemento;
}

void print(Lista*lista){
  No*elemento = lista->head;
  while(elemento){
    printf("%c", elemento->frase);
    elemento = elemento->next;
  }
  printf("\n");
}
  
int main(void){
  Lista lista;
  char caracter[100001];
  while(scanf("%s", caracter) != EOF){
    lista.head = NULL;
    lista.last = NULL;
    int home = 0,pos =0;
    for (int i = 0; caracter[i] != '\0';i++) {
      if (caracter[i] == '[') {
        home = 1;
        pos = 0;
      }
      else if (caracter[i] == ']') {
        home = 0;
        pos = 0;
      }
      else if (home == 0) {
        add_final(&lista, caracter[i]);
      }
      else {
        add_inicio(&lista, caracter[i],pos);
        pos ++;
      }
    }
    print(&lista);
  }
  return 0;
}