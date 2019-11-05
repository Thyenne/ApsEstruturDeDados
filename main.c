#include <stdio.h>
#include <string.h>
#include "TADs_lineares_aloc_enc.h"


TipoItem p1,p2; int k, op1, op2, res;



void main(void )
{

char exp[30], aux[30];
int T,op;


printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
printf("Ethyenne Lins Salles Alexandrino  ");
printf("2017101195  \n");
printf("Estrutura de dados      -       ");
printf("Professor Eugênio da Silva \n");
printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");




//cria pilha dimanica. 

	TipoPilha *pilha = (TipoPilha *)malloc(sizeof(TipoPilha));
  
  CriaPilhaVazia(pilha);

// testa se a pilha é vazia;
    printf("\n");
    if (TestaPilhaVazia(pilha) == 1) 
    printf("Pilha criada. :) \n");
    else printf("Deu erro amigo, tente novamente :( \n");

    
//insere a expressão pós-fixa
printf("\n");
printf("Este algoritmo aceita as operações de +, -, *, /: \n");
printf("Digite a expressao em notação pós fixa: ");
scanf("%s",exp);
printf("\n");

// contando quantos operadores, quantos operandos existem na expressão.
T = strlen(exp);

// inserindo a expressão no vetor auxiliar 
for (int i=0; i<T; i++){
aux[i] = exp[i];
}

// verificando se é operador ou operando
for(int i=0; i<T; i++){
 
  if(operador(exp[i]) == '1'){
   

   switch(exp[i]){
      case '*':
      
        RemovePilha(pilha, &p1);
        op1 = p1.chave;
        RemovePilha(pilha, &p1);
        op2 = p1.chave;
        p1.chave = op2 * op1;
        InserePilha(pilha, p1);
      break;

      case '+':

        RemovePilha(pilha, &p1);
        op1 = p1.chave;
        RemovePilha(pilha, &p1);
        op2 = p1.chave;
        p1.chave = op2 + op1;
        InserePilha(pilha, p1);

      break;

      case '-':
        RemovePilha(pilha, &p1);
        op1 = p1.chave;
        RemovePilha(pilha, &p1);
        op2 = p1.chave;
        p1.chave = op2 - op1;
        InserePilha(pilha, p1);

      break;

      case '/':
        RemovePilha(pilha, &p1);
        op1 = p1.chave;
        RemovePilha(pilha, &p1);
        op2 = p1.chave;
        p1.chave = op2 / op1;
        InserePilha(pilha, p1);
      break;


}
  } if(operador(exp[i]) == '0') {
    

    printf("Qual o valor de %c: ", aux[i]);
    scanf("%d",&k);
    
    p1.chave = k; 
    InserePilha(pilha, p1);
    

  
}

}

printf("O valor da final da expressão é de: "); 
ImprimePilha(pilha);


}

int operador(op){
switch(op){
case '*':
 return '1';
 break;

case '+':
  return '1';
  break;

case '-':
  return '1';
  break;

case '/':
  return '1';
  break;

default:
  return '0';

}
}