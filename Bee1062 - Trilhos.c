#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No*next;
}No;

typedef struct{
    No*head;
}Pilha;

void add(Pilha*pilha, int valor){
   No* elemento = malloc(sizeof(No));
   elemento->num = valor;
   elemento->next = pilha->head;
   pilha->head = elemento;
}

void remover(Pilha*pilha){
 No* aux = (pilha->head)->next;
 free(pilha->head);
 pilha->head = aux;
}

int main(void){
  Pilha pilha;
  int vagao[1001];
  int i, num_vagao, tam;
  inicio:
  while(scanf("%d", &tam)!= EOF){
    pilha.head = NULL;
    if(tam == 0){
      break;
    }
    while(1){
      int verify = 0;
      for(i=0, num_vagao = 1; i < tam; i++){
        scanf("%d", &vagao[i]);
        if(vagao[0] == 0){
          printf("\n");
          goto inicio;
        } 
        while(1){ 
          if(num_vagao == vagao[i]){    
            add(&pilha,num_vagao);
            num_vagao++;                           
          }else{
            if(vagao[i] > num_vagao){                      
              add(&pilha,num_vagao);
              num_vagao++;
            }else{
              if(vagao[i] == (pilha.head)->num)
                remover(&pilha);
              else{
                verify = 1;
              }
              break;
            }
          }
        }
      }
    if(!verify){
      printf("Yes\n");}
    else{
      printf("No\n");}
    }
  }

  return 0;
}