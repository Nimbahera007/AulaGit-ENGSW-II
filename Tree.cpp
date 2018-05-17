#include "Tree.h"
#include "Node.h"
#include <fstream>
#include <iostream>
using namespace std;

void Tree::Inserir(Node* novo, int l){
    root=InserirNovo(novo,root, l);
}
void Tree::Inicializa(){
    root=NULL;
}

/**
 * Função que insere os nodes na árvore binária e insere o número da linha
 * correspondente à palavra lida.
 * @param novo: node à ser inserido na árvore
 * @param atual: node de controle da recursão
 * @param l: inteiro correspondente à linha da leitura
 * @return encadeamento do node inserido ou incrementado caso já exista
 */
Node* Tree::InserirNovo(Node* novo, Node* atual, int l){
    
    if(atual == NULL){
        novo->linhas.inicializar();
        Celula* c = new Celula();
        c->Valor=l;
        novo->linhas.insereFinal(c);
        return novo; 
    }
    if(atual->palavra > novo->palavra){
        atual->left = InserirNovo(novo, atual->left, l);
    }
    else if(atual->palavra < novo->palavra){
        atual->right = InserirNovo(novo,  atual->right, l);
    }
    else{
        
        Celula* c = new Celula();
        c->Valor=l;
        atual->linhas.insereFinal(c);
         
    }
    return atual;
    
}
/**
 * Imprime no console as palavras em ordem alfabética e suas ocorrências de linha
 * @param elemento: Node inicial de impressão, recomendado utilizar a raiz da àrvore
 */
void Tree::EmOrdem(Node* elemento){
    if(elemento!=NULL){
        Tree::EmOrdem(elemento->left);
        cout <<elemento->palavra;
        for(int i=0;i<(25-elemento->palavra.size());i++){
            cout<<' ';
        }
        elemento->linhas.imprimeLista();        
        cout<<'\n';
        Tree::EmOrdem(elemento->right);
        
    }
}

/**
 * Função que lê arquivo texto linha a linha, e as envia para tratamento.
 */
void Tree::LeArquivo(){
    string linha;
    ifstream leitor;
    leitor.open("faroeste.txt");//INSIRA AQUI O ARQUIVO TEXTO A SER LIDO
    if(!leitor)
        cout<<"\n\tERRO AO LER ARQUIVO!";
    else{
        int l=1;
        while(!leitor.eof()){            
            getline(leitor, linha);
            if(linha.empty()){
                
            }
            else{
                splitString(linha,l);
            }
            l++;
        }
    }
}

/**
 * Função que divide uma string recebida por parâmetro.
 * Delmitadores considerados são caracteres especiais, pontuação e espaço.
 * @param s: string para ser dividida
 */
void Tree::splitString(string s, int l){
    string atual="";
    for (int i=0; i<s.size(); i++)
    {
        if((s.at(i)!='"') and (s.at(i)!=' ') and !ispunct(s.at(i)))
            atual=atual+s.at(i);
        else{
            if(atual.empty() or atual.size()<3){
                atual="";
            }
            else{
                atual=padronizar(atual);
                Node* n = new Node();
                n->palavra=atual;
                Inserir(n,l);
                atual="";
            }
        }
    }
    if(atual.empty()){
        
    }
    else{
        atual=padronizar(atual);
        Node* n = new Node();
        n->palavra=atual;
        Inserir(n,l);
    }
}

/**
 * Função que padroniza uma string recebida por parâmetro, convertendo todos seus caracteres
 * em minúsculo.
 * @param s: string que será convertida para lowerCase
 * @return string resultante da conversão
 */
string Tree::padronizar(string s){

    int i=0;
    while(s[i]){
        s[i]=tolower(s[i]);
        i++;
    }
    return s;
}

// bool ispunct(char c) função que indica se o char c é pontuação
// bool tolower(char c) converte pra minusculo o char c
// bool isupper(char c) indica se char é maiusculo
// bool islower(char c) indica se char é minusculo