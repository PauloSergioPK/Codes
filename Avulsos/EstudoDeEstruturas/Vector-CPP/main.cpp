#include  "vetor.hpp"

int main(){
    vetor<int> vetin;
    for(int i = 0; i < 10; i++)
        vetin.pop_back(i+1);
    vetin.show();
    vetin.push_front();
    vetin.push_back();
    vetin.show();
    vetin.insert_at(0,1);
    vetin.show();
    for(int i = 0; i < 5; i++)
        vetin.pop_back(2);
    vetin.show();
    vetin.remove_all_with_value(2);
    vetin.show();
}