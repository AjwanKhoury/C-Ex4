#ifndef _TRIE_H_
#define _TRIE_H_
#define NUM_LETTERS 26
#define WORD 26

typedef struct node node;
node* newNode(char);
node* toSet(node*, char);
int isLeaf(node*);
void freeOne(node*);
void ToCount(node*);
void printD(node*,char*,int);
void printR(node*,char*,int);
void ToMove(node*,char);

#endif