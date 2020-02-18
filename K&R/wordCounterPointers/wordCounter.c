#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"binaryTree.h"
#include"getword.h"

#define MAXWORD 100

int main(){

NodeTree* root;
root=NULL;
char word[MAXWORD];

/* Defino primer nodo del arbol, incializacion del primer nodo con addtree() no funciona 
char* palabra="hola";
root=talloc();
root->count=1;
root->word=ystrdup(palabra);
root->leftNode=root->rightNode=NULL;
*/

while(getword(word,MAXWORD)!=EOF)
    if(isalpha(word[0]))
        addtree(root,word);


treeprint(root);
return 0;
}