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

while(getword(word,MAXWORD)!=EOF)
    if(isalpha(word[0]))
        addtree(root,word);


treeprint(root);
return 0;
}