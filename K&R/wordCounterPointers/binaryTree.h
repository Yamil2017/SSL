#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct Node{
    char* word;
    int count;
    struct Node* leftNode;
    struct Node* rightNode;
}NodeTree;

NodeTree* addtree(NodeTree*,char*);

NodeTree* talloc(void);

char* ystrdup(char*); //This function already exists in string.h as strdup

void treeprint(NodeTree*);


#endif