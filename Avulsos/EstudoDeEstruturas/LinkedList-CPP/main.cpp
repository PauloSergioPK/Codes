#include "lista_encadeada.hpp"
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    List lista;
    for(int i = 0; i < 1;i++)
        lista.insert(2);
    
    lista.show();
    lista.push_back();
    lista.show();
    lista.remove_with_value(2);
    lista.pop_back(5);
    lista.show();
    
    
    //int x = rand()%101;
    //cout << x << endl;
    //auto it = lista.find(x);
    //lista.remove(&it);
    //lista.show();


    
}