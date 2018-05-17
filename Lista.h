/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lista.h
 * Author: IFMG
 *
 * Created on 25 de Agosto de 2017, 09:53
 */

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Celula.h"
#include <iostream>
struct Lista{
    Celula* first=NULL;
    bool listaVazia();
    void inicializar();
    void insereFinal(Celula* c);
    void insereInicio(Celula* c);
    Celula* pesquisar(int x);
    bool removeInicio();
    bool removeFim();
    void imprimeLista();
    void insereOrdenado(Celula* c);
    void insereIndex(Lista listx, Celula* c, int index);
    int getElementos(Lista listx);
    bool removeValor(int value);
    bool removeIndex(int index, Lista listx);
};

#endif // LISTA_H_INCLUDED

