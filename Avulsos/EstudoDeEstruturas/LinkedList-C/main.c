#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
---Lista Encadeada
*/


typedef struct no{
    int value;
    struct no * next;
}Node;

Node * create_node(){ //cria um novo no
    Node * new_node = (Node*) malloc(sizeof(Node));
    return new_node;
}


typedef struct list{
    Node * head;
    int qtd;
}List;

List * create(){   //cria a lista
    List * lista = (List*) malloc(sizeof(List));
    lista->head = NULL;
    lista->qtd = 0;
    return lista;
}

void pop_front(List *list, int value){ //insere na frente
    Node * aux = create_node();
    aux->value = value;
    aux->next = list->head;
    list->head = aux;
    list->qtd = list->qtd + 1;
}

void show(List *lista){ //mostra a lista
    Node * aux = lista->head;
    printf("[ ");
    while(aux != NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("]\n");
}

void pop_back(List *list, int value){ //insere a tras
    if(list->head == NULL){
        pop_front(list,value);
        return;
    }
    Node *aux = list->head;
    while(aux->next != NULL){
        aux = aux->next;
    }
    Node *aux2 = create_node();
    aux2->value = value;
    aux2->next = NULL;
    aux->next = aux2;
    list->qtd = list->qtd +1;
}

void insert_at(List *lista, int value, int pos){ //insere na puta q pariu
    if(pos > lista->qtd)
        return;
    Node *aux = lista->head;
    for(int i = 0; i < pos-1; i++)
        aux = aux->next;
    Node *aux2 = create_node();
    aux2->value = value;
    aux2->next = aux->next;
    aux->next = aux2; 
    lista->qtd ++;
}

int _size(List *lista){ //retorna o tamanho da lista
    return lista->qtd;
}

void push_front(List *list){ //retira da frente
    Node *aux = list->head;
    if(aux == NULL)
        return;
    list->head = aux->next;
    free (aux);
    list->qtd --;
}

void push_back(List *list){ //retira das cuestas
    Node *aux = list->head;
    if(aux == NULL)
        return;
    if(list->qtd == 1){
        free(aux);
        list->head = NULL;
        return;
    }
    for(int i = 0; i < _size(list)-2;i++)
        aux = aux->next;
    free(aux->next);
    aux->next = NULL;
    list->qtd--;
}

void _remove(List *list, int pos){ //retira do teu cu
    Node *aux = list->head;
    if(pos > list->qtd)
        return;
    if(pos == 0){
        push_front(list);
        return;
    }
    for(int i = 0; i < pos-1;i++) //percorre ate o antes da posicao desejada
        aux = aux->next;
    Node *aux2 = aux->next;
    aux->next = aux2->next;
    free(aux2);
    list->qtd--;
}

void _remove_all_with_value(List *list,int value){ //retira todos com o mesmo valor
    Node *aux= list->head;
    int i = 0;
    while(aux!=NULL){ //percorre ate o final, e o I marca a posicao do elemento na lista
        if(aux->value == value){
            Node *aux2 = aux->next;
            _remove(list,i);
            aux = aux2;
            continue;
            i--;
        }
        aux = aux->next;
        i++;
    }
}

bool IsEmpty(List *list){
    return list->qtd > 0 ? false : true;  //retorna falso se ela nao estiver vazia, e true caso esteja
}

void _delete(List *list){ //estalo do thanos
    Node * aux = list->head;
    if(aux != NULL){
        while(aux != NULL){
            Node *aux2 = aux->next;
            free(aux);
            aux = aux2;
        }
    }
    free(list);
}



int main(){
    List *lista = create();
    for(int i = 0; i < 10; i++){
        if(i < 5)
            pop_back(lista,2);
        else
            pop_back(lista,3);
    }
    show(lista);
    _remove_all_with_value(lista,2);
    show(lista);
    _delete(lista);
    printf("Sexo Anal");
}