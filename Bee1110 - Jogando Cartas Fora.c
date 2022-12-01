#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No*next;
}No;

typedef struct{
    No*head;
    No*last;
}Fila;


void add(Fila*fila, int valor){
    No*elemento = malloc(sizeof(No));
    elemento->num = valor;
    elemento->next = NULL;
    if(fila->last == NULL){
        fila->last = elemento;
        fila->head = elemento;
    }else{
        (fila->last)-> next = elemento;
    }
    fila->last = elemento;
}

void remover(Fila*fila, int quant){
  if(quant>1){
    printf("Discarded cards:");
  }
  while(quant>1){
    No*elemento = fila->head;
    fila->head = (fila->head)->next;
    if(quant>2){
      printf(" %d,", elemento->num);
    }else{
      printf(" %d\n", elemento->num);
    }
    free(elemento);
    (fila->last)->next = fila->head;
    fila->last = fila->head;
    fila->head = (fila->last)->next;
    (fila->last)->next = NULL;
    quant--;
  }
}

int main(void){
    Fila fila;
    int num_carta;
    while(scanf("%d", &num_carta) != EOF){
      fila.head = NULL;
      fila.last = NULL;
      if(num_carta != 0){
        for(int i = 1; i <= num_carta; i++){
            add(&fila, i);
          }
        remover(&fila, num_carta); 
        printf("Remaining card: %d\n", (fila.last)->num);
        }
    
    }
  return 0;
}