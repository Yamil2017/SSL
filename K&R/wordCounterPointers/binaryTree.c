#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"binaryTree.h"

NodeTree* addtree(NodeTree* tree, char* word){
    int cond;

    if(tree==NULL){ //non-existing word within tree
        tree=talloc();
        tree->word=ystrdup(word);
        tree->count=1;
        tree->leftNode=tree->rightNode=NULL;
    } else if ((cond=strcmp(word,tree->word))<0) //smaller word
        tree->leftNode=addtree(tree->leftNode,word);
    else if (cond==0) //repeated word
        tree->count++;
    else
        tree->rightNode=addtree(tree->rightNode,word);
    return tree;
}

char* ystrdup(char* word){
    char*duplicate = (char*)malloc(strlen(word)+1); // + 1 for the '\0'
    if(duplicate!=NULL)
        strcpy(duplicate,word);
    return duplicate;
}

NodeTree* talloc(void){
    return (NodeTree*)malloc(sizeof(struct Node));
}

void treeprint(NodeTree* arbol){
    if(arbol!=NULL){
        treeprint(arbol->leftNode);
        printf("palabra: %10s   cantidad: %3d\n",arbol->word,arbol->count);
        treeprint(arbol->rightNode);
    }
}