#include <iostream>
#include <cstdlib>
using namespace std;

template<class type>
struct vetor{
    type *data;
    int size;
    int capacity;

    vetor(){ //construtor
         this->capacity = 1;
         this->size = 0;
         this->data = new type[capacity];
    }

    ~vetor(){ //destrutor
        delete [] this->data;
    }

    void resize(int new_capacity){ //aloca mais memoria ao vetor
        this->data = (type*) realloc(this->data,sizeof(type)*new_capacity);
        this->capacity = new_capacity;
        if(this->size > new_capacity)
            this->size = new_capacity;
    }

    void show(){ //imprime os dados
        cout << "[ ";
        for(int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << "]" << endl;
    }

    bool isEmpty(){ //retorna true se estiver vazio e false caso contrario
        return size > 0 ? false : true;
    }

    void pop_front(type value){ //insere na frente
        if(size + 1 > capacity)
            resize(capacity * 2);
        for(int i = size; i > 0; i--)
            this->data[i] = data[i-1];
        this->data[0] = value;
        this->size++;
    }

    void push_front(){ //remove na frente
        if(this->size == 0)
            return;
        for(int i = 0; i < size; i++)
            this->data[i] = data[i+1];
        this->size--;
    }

    void pop_back(type value){ //insere nas cuestas
        if(this->size + 1 > capacity)
            resize(capacity * 2);
        this->data[size] = value;
        this->size++;
    }

    void push_back(){ //remove nas cuestas
        if(this->size == 0)
            return;
        this->size--;
    }

    void insert_at(int index, type value){
        if(index < 0 || index > this->size)
            return;
        if(this->size + 1 > capacity)
            resize(this->capacity * 2);
        for(int i = size; i > index; i--)
            this->data[i] = data[i-1];
        this->data[index] = value;
        this->size++;
    }

    void remove_at(int index){
       if(index < 0 || index > this->size)
            return;
        for(int i = index; i < size; i++)
            this->data[i] = data[i+1];
        this->size--; 
    }

    void remove_all_with_value(type value){
        for(int i = size-1; i >= 0; i--){
            if(this->data[i] == value)
                remove_at(i);
        }
    }

};