#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>
#include "trie.h"


int main(int argc, char const *argv[]){

  char get;
  node *root=newNode('\0');
  node *m=root;
  char w[WORD];
  char c;

  while((c=getc(stdin))!=EOF){
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')){
      m=toSet(m,tolower(c));
    }
    else if(c=='\t'||c=='\n'||c== ' '){ 
     ToCount(m);
     m=root;
    } 
  }
  if(argc>1){
    get=*argv[1];
    if(get=='r')
      printR(root,w,0);
  }
  else
    printD(root,w,0); 

  freeOne(root);
}