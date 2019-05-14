#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root;
    
    BTree(){
        this->root = nullptr;
    }
    

    Node * rand_insert(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        if(rand() % 2 == 0)
            node->left = rand_insert(node->left, value);
        else
            node->right = rand_insert(node->right, value);
        return node;
    }

    void rand_insert(int value){
        this->root = rand_insert(this->root, value);
    }

    void serialize(stringstream& ss, Node * node){
        if(node == nullptr)
            ss << ". ";
        else{
            ss << node->value << " ";
            serialize(ss, node->left);
            serialize(ss, node->right);
        }
    }

    string serialize(){
        stringstream ss;
        serialize(ss, this->root);
        return ss.str();
    }

    void show(Node * node, int nivel){
        if(node == nullptr){
            cout << string(2 * nivel, ' ')  << ".\n";
            return;
        }
        cout << string(2 * nivel, ' ') << node->value << "\n";
        if(node->left != nullptr || node->right != nullptr){
            show(node->left, nivel + 1);
            show(node->right, nivel + 1);
        }
    }

    void show(){
        show(this->root, 0);
    }

    void destroy(Node * it){
        if(it == nullptr)
            return;
        destroy(it->left);
        destroy(it->right);
        delete it;
    }

    void deserialize(Node ** elo, stringstream &ss){
        string value;
        ss >> value;
        if(value == "#")
            return;
        int num;
        if(stringstream(value) >> num){
            *elo = new Node(num);
            deserialize(&(*elo)->left,ss);
            deserialize(&(*elo)->right,ss);
        }
        
    }

    Node * clone(Node * no, stringstream &ss){
        string value;
        ss >> value;
        if(value == "#")
            return no;
        int num;
        if(stringstream(value) >> num){
            Node *aux = new Node(num);
            aux->left = clone(aux->left,ss);
            aux->right = clone(aux->right,ss);
            return aux;
        }
        return no;
    }

    
    BTree(string serial){
        stringstream ss(serial);
        //deserialize(&root,ss);
        this->root = clone(root,ss);

        /*
            deserialize utiliza elo
            clone utiliza nos
        */
    }
    
    ~BTree(){
        destroy(this->root);
    }

};

int main(){
    
    string line;
    getline(cin,line);
    BTree bt(line);
    bt.show();
    
}

/*
    fazer busca em arvore, mostrando o nivel do no e altura
    fazer a soma dos elementos da arvore
    fazer o minimo da arvore

*/