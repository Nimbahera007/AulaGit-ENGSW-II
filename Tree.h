/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: IFMG
 *
 * Created on 29 de Outubro de 2017, 09:59
 */

#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "Node.h"

struct Tree{
    Node* root=NULL;
    Node* InserirNovo(Node* novo, Node* atual, int l);
    void Inicializa();
    void Inserir (Node* novo, int l);
    void EmOrdem(Node* elemento);
    void LeArquivo();
    void splitString(string s, int l);
    string padronizar(string s);
};

#endif /* TREE_H */

