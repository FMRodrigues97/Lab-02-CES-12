#ifndef CES12_ALUNOINDEXPOINTS_H
#define CES12_ALUNOINDEXPOINTS_H

#include <vector>
#include <map>
#include <IndexPointsAbstract.h>

class noh{

public:

    noh(long idx, float key, noh* pai, noh* esquerda, noh* direita){
        
        this->key = key;
        this->idx = idx;
        this->vermelho = true;
        this->pai = pai;
        this->esquerda = esquerda;
        this->direita = direita;
    }

    long idx;
    float key;
    bool vermelho;
    noh* pai;
    noh* esquerda;
    noh* direita;
};

class IndexPointsAluno : public IndexPointsAbstract {

public:

    IndexPointsAluno(){

        contador = 0;
        nil = new noh(0, 0, nullptr, nullptr, nullptr);
        nil->vermelho = false;
        raiz = nil;
        raiz->esquerda = nil;
        raiz->direita = nil;
        raiz->pai = nil;

    }

    long size();
    void add (float key, long idx);
    void find(std::vector<long> &res, float first, float last); //look for a range of values

    void rotacao_esquerda(noh* raiz_anterior);
    void rotacao_direita(noh* raiz_anterior);
    
    void RB_insert_fixup(noh* novo_noh);
    void buscar(std::vector<long> &res, float first, float last, noh* raiz);

private: 
    // ALUNO DEVE IMPLEMENTAR ALGO COM O MESMO COMPORTAMENTO DE MULTIMAP std::multimap<float, long> _map;

    long contador;
    noh* raiz;
    noh* nil;

};//class

#endif
