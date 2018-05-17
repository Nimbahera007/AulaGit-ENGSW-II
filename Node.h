/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: IFMG
 *
 * Created on 29 de Outubro de 2017, 09:58
 */

#ifndef NODE_H
#define NODE_H
#include <string>
#include "Lista.h"
#include "Celula.h"
using namespace std;

struct Node{
    string palavra;
    Lista linhas;
    Node* right;
    Node* left;
};


#endif /* NODE_H */

