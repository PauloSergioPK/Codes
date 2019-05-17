#ifndef lista_encadeada_h
#define lista_encadeada_h

#include <iostream>
#include <sstream>
using namespace std;

struct Node{ //estrutura no
    int value;
    Node *next;
    Node(int value = 0, Node * next = nullptr){
        this->value = value;
        this->next = next;
    }

};

struct List{ //estrutura lista
    Node * head;

    List(){ //construtor
        this->head = nullptr;
    }

    void insert(int value){ // inserir ordenado
        insert(&this->head,value);
    }

    void insert(Node ** elo, int value){ //inserir ordenado
        Node * node = *elo;
        if(node == nullptr || node->value > value){
            *elo = new Node(value, node);
            return;
        }
        insert(&node->next,value);
    }

    void show(){ //imprime a lista
        cout << "[ ";
        Node *aux = this->head;
        while(aux != nullptr){
            cout << aux->value << " ";
            aux = aux->next;
        }
        cout << "]\n";
    }

    void remove(Node ** no){ //remove um no
        if(*no == nullptr)
            return;
        Node *aux = this->head;
        if(*no == this->head){
            this->head = aux->next;
            delete aux;
            return;
        }
        while(aux->next != *no)
            aux = aux->next;
        Node *aux2 = aux->next;
        aux->next = aux2->next;
        delete aux2;
    }
    Node * find(int value){ //retorna um no caso ele exista
        Node *aux = this->head;
        if(aux == nullptr)
            return nullptr;
        if(aux->value == value)
            return aux;
        while(aux != nullptr && aux->value != value){
            aux = aux->next;
        }
        return aux;
    }

    void insert_at(Node ** elo, int value){ //insere em um determinado ponto
        Node *aux = *elo;
        *elo = new Node(value,aux);
    }

    void pop_front(int value){ //insere na frente
        Node * aux = new Node(value,this->head);
        this->head = aux;
    }

    void pop_back(int value){ //insere nas cuestas
        Node *aux = this->head;
        if(aux == nullptr){
            this->head = new Node(value);
            return;
        }
        while(aux->next != nullptr)
            aux = aux->next;
        aux->next = new Node(value);
    }

    void push_front(){ //retira da frente
        remove(&this->head);
    }
    void push_back(){ //retira das cuestas
        Node *aux = this->head;
        if(aux == nullptr)
            return;
        
        if(!justOne()){ //executa caso possua mais de um elemento
            while(aux->next->next != nullptr)
                aux = aux->next;
            Node *aux2 = aux->next;
            aux->next = aux2->next;
            delete aux2;
            return;
        }        
        remove(&this->head); //executa caso so possua um elemento, ou seja, a cabeca sera removida
    }

    void remove_with_value(int value){ //remove todos com o mesmo valor
        Node * aux = this->head;
        while(aux != nullptr){
            if(aux->value == value){
                Node *aux2 = aux->next;
                remove(&aux);
                aux = aux2;
            }
            else
                aux = aux->next;
        }
    }

    bool justOne(){ //retorna true caso so possua um elemento
        Node *aux = this->head;
        if(aux != nullptr){
            aux = aux->next;
            if(aux != nullptr)
                return false;
            return true;
        }
        return false;
    }

    bool isEmpty(){ //retorna true se estiver vazio
        Node *aux = this->head;
        if(aux != nullptr)
            return false;
        return true;
    }

    ~List(){
        Node * aux = this->head;
        while(aux != nullptr){
            Node *aux2 = aux->next;
            delete aux;
            aux = aux2;
        }
    }
};

#endif