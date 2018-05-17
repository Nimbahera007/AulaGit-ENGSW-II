/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Lista.cpp
 * Author: IFMG
 *
 * Created on 25 de Agosto de 2017, 09:53
 */

#include "Lista.h"
#include "Celula.h"
#include <iostream>

using namespace std;

void Lista::inicializar(){
    first=NULL;
}

bool Lista::listaVazia(){
    return (first==NULL);
}

void Lista::insereFinal(Celula* c){

    if(Lista::listaVazia())
        first=c;
    else{
        Celula* aux=first;
            while(aux->next!=NULL){
                aux=aux->next;
            }
        aux->next=c;
        }
}

void Lista::insereInicio(Celula* c){

    c->next=first;
    first=c;
}

Celula* Lista::pesquisar(int x){
    if(Lista::listaVazia())
        return NULL;
    else{
        Celula* aux=first;
        while((aux!=NULL) and (aux->Valor!=x)){
            aux=aux->next;
        }
        return aux;
    }
}

bool Lista::removeInicio(){
    if(Lista::listaVazia())
        return false;
    else{
        Celula* aux=first;
        first=aux->next;
        delete aux;
    }

    return true;
}

bool Lista::removeFim(){
    if(Lista::listaVazia())
        return false;
    else{
        Celula* ant=first;
        Celula* atual=first->next;
        if(atual==NULL){
            atual=first;
            first==NULL;
        }
        else{
            while(atual->next!=NULL){
                ant=atual;
                atual=atual->next;
            }
            ant->next=NULL;
        }
        delete atual;
    }

    return true;
}

void Lista::imprimeLista(){
    Celula* aux=first;
    while(aux!=NULL){
        cout <<aux->Valor <<',';
        aux=aux->next;
    }
}

void Lista::insereOrdenado(Celula* c){
    if(first==NULL)
        first=c;
    else{

        Celula* ant=first;
        Celula* atual=first->next;
        bool flag=0;
        if(c->Valor<ant->Valor){///COBRE SE C FOR MENOR QUE O PRIMEIRO DA LISTA
            c->next=ant;
            first=c;
        }
        else{
            if(atual==NULL){///COBRE SE  A LISTA TEM APENAS 1 ELEMENTO
                c->next=NULL;
                ant->next=c;
            }
            else{///COBRE O RESTANTE DE POSSIBILIDADES
                while((c->Valor>ant->Valor) and (flag==0)){
                    if(atual==NULL){
                        c->next=NULL;
                        ant->next=c;
                        flag=1;
                    }
                    else if(c->Valor<atual->Valor){
                        c->next=atual;
                        ant->next=c;
                        flag=1;
                    }
                    else{
                        ant=atual;
                        atual=atual->next;
                    }
                }
            }
        }
        delete atual;
    }
}

void Lista::insereIndex(Lista listx,Celula* c, int index){
    if(index<1){// VALIDAÇÃO
        cout <<"Index Inválido!";
    }
    else if(Lista::listaVazia()){
        cout<<"\nLista vazia, a célula fornecida será a primeira da lista!";
        Lista::insereInicio(c);
    }
    else{
        if(index>Lista::getElementos(listx)){
            cout<<"\nA lista contém menos elementos do que o índice fornecido, a célula será inserida no final!";
            Lista::insereFinal(c);
        }
        else{
            if(index==1){
                c->next=first;
                first=c;
            }
            else{
                Celula* atual=first->next;
                Celula* ant=first;
                for(int i=0;i<(index-2);i++){
                    ant=atual;
                    atual=atual->next;
                }
                c->next=atual;
                ant->next=c;
                delete atual;
            }
        }
    }
}

int Lista::getElementos(Lista listx){
    int counter=0;
    Celula* aux=first;
    while(aux!=NULL){
        counter++;
        aux=aux->next;
    }
    return counter;
}

bool Lista::removeValor(int value){
    if(Lista::listaVazia()){
        return false;
    }
    else{
        Celula* ant=first;
        Celula* atual=ant->next;
        if(ant->Valor==value){
            first=ant->next;
            delete ant;
            return true;
        }
        else {
            while(atual->Valor!=value){
                ant=atual;
                atual=atual->next;
            }
            ant->next=atual->next;
            delete atual;
            return true;
        }
    }

}

bool Lista::removeIndex(int index, Lista listx){
    if(index<1){// VALIDAÇÃO
        cout <<"Index Inválido!";
        return false;
    }
    else if(Lista::listaVazia()){// VERIFICA LISTA VAZIA
        return false;
    }
    else if(index>Lista::getElementos(listx)){// VERIFICA SE INDEX É VALIDO
        cout <<"\nO índice informado é maior que a lista";
        return false;
    }
    else if(index==1){// COBRE CASO INDEX SEJA O 1º
        Celula* aux=first;
        first=aux->next;
        aux->next=NULL;
        delete aux;
        return true;
    }
    else{// COBRE AS OUTRAS POSSIBILIDADES
        Celula* atual=first->next;
        Celula* ant=first;
        for(int i=0;i<(index-2);i++){
        ant=atual;
        atual=atual->next;
        }
        ant->next=atual->next;
        atual->next=NULL;
        delete atual;
        return true;
    }
}





