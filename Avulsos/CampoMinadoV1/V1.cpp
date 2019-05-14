#include "xpaint.h"
#include "xmat.h"
#include <vector>
#include <iostream>
using namespace std;

struct Pos {
    int l;
    int c;
    Pos(int l, int c){
        this->l = l;
        this->c = c;
    }
};

vector<Pos> get_neibs(int l , int c){
    return vector<Pos> {Pos(l-1,c),Pos(l-1,c+1),Pos(l,c+1),Pos(l+1,c+1),Pos(l+1,c),Pos(l+1,c-1),Pos(l,c-1),Pos(l-1,c-1)};
}

bool isValid(vector<string> &mat, int l, int c){
    if(l < 0 || l >= (int) mat.size() || c < 0 || c >= (int) mat[0].size())
        return false;
    return true;
}


void process(vector<string> &mat, vector<string> & mat_bomba){
    for(int i = 0; i < (int) mat.size();i++){
        for(int j = 0; j < (int) mat[0].size(); j++){
            if(mat_bomba[i][j] != '*'){
                int cont = 0;
                for(auto viz : get_neibs(i,j)){
                    if(isValid(mat,viz.l,viz.c)){
                        if(mat_bomba[viz.l][viz.c] == '*')
                            cont++;
                    }
                    
                }
                if(cont > 0){
                    if(cont == 1)
                        xmat_put_number(i, j, GREEN, cont);
                    else if(cont == 2)
                        xmat_put_number(i, j, BLUE, cont);
                    else
                        xmat_put_number(i, j, RED, cont);   
                }
                    
            }
            else{
                XColor cor = make_xcolor('0','0','0');
                xmat_put_circle(i,j, cor);
            }
        }
    }

    x_save("mat");


}

int main(){
    int nl,nc;
    cout << "Digite o numero de linhas e o numero de colunas" << endl;
    cin >> nl >> nc;
    xmat_init(nl, nc);
    vector<string> mat(nl, string(nc, 'w'));
    vector<string> mat_bomba(nl, string(nc, '-'));
    for(int l = 0; l < (int) mat.size(); l++){
        for(int c = 0; c < (int) mat[0].size(); c++){
            if(xm_rand(0, 100) < 25)
                mat_bomba[l][c] = '*';
        }
    }
    xmat_draw(mat);
    process(mat,mat_bomba);
    x_close();
}

/*
    Implementar :
        -Quando selecionar um espaco sem nenhuma bomba por perto deve-se fazer um floodfill pelos 8 cantos e contornar com area com bomba perto
        -Opcoes para dizer onde q tem bomba ou selecionar um canto livre
        -Ganha quando dizer as bombas nos lugares certos, se n, perde
*/