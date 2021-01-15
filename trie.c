#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define NUM_LETTERS 26


typedef struct node{
char letter;
long unsigned int count;
struct node* children[NUM_LETTERS];

}node;



node* newNode(char letter){
	//here we use a malloc function that reserves a block of mermoy of the specified number of bytes
	//and save it in m
	node* m=(node*)malloc(sizeof(node));
	//here we allow the value held by count to m 
	(*m).count=0;
	// here we allow the value held by letter to m 
	(*m).letter=letter;
	//loop until 26 
	for(int i=0;i<NUM_LETTERS;i++){
		//here we held by the children in index i to m and but it null
		(*m).children[i]=NULL;
	}
	return m;
}

node* toSet(node *m, char c){
	//here we set a char into m 
	//so we check if the value that holds by children to m is null 
	if((*m).children[c-'a'] == NULL){
		//if its so we need to create a newnode using the function below to hold 
	    node *mo = newNode(c);
    	(*m).children[c-'a'] = mo;
    	//we return the new node
    	return (*m).children[c-'a'];
	}
	return (*m).children[c-'a'];
}


int isLeaf(node* m){
	//if its leaf 
	//loop over 26 and check if null that the holded value by childern in index isn't null
	//so we retun 0 !!  
	for(int i=0;i<NUM_LETTERS;i++){
		if((*m).children[i]!=NULL)
 			return 0;
	}
	//else we return 1
	return 1;
}

void freeOne(node* m){
	//we check if the node is null
	if(m==NULL)
		return;
	//we check if its a leaf using the function below
	if(isLeaf(m)){
		//deallocates the memory previously allocted 
  		free(m);
  		//it does not return any value
		return;
	}
	//loop over the num letters (26)
	for(int i=0;i<NUM_LETTERS;i++){
		//recursive over the function.
    	freeOne((*m).children[i]);
	}
	//adeallocates the memory previously allocted
	free(m);
}

void ToCount(node* m){
	//we add 1 to the value that holds by count to m
	m->count++;
}


void printD(node* m,char* c,int i){
	//if node m is a leaf
	if (isLeaf(m)){
		//we check if it at the end (/0)- null
		c[i] = '\0';
		//and print it
		printf("%s\t%ld\n", c, (*m).count);
		return;
	}
	//if its not leaf we check if the value tjat hold by count to m is more than zero
	if ((*m).count > 0){
		//if it so we check if its at the end(/0)
		c[i] = '\0';
		//and print it
		printf("%s\t%ld\n", c, (*m).count);
	}
	int j;
	//loop over the num letters (until 26)
	for (j=0; j<NUM_LETTERS; j++){
		//if the value that holds by the children in index i to m is not null
		if (m->children[j]!=NULL){
			//so the update the char c in index i
			c[i] = m->children[j]->letter;
			// recursive over the function but with i+1             
			printD((*m).children[j], c, i);
		}
	}
}

void printR(node* m,char* c,int i){
	//if node m is a leaf
	if (isLeaf(m)){ 
		//so we update the char c in index i
    	c[i] = '\0';
    	//and print 
    	printf("%s\t%ld\n", c, (*m).count);
		return;
	}
	//if its not leaf we check if the value hat hold by count to m is more than zero
	if (m->count > 0){
		// we update the char c in index i 
		c[i] = '\0';
		printf("%s\t%ld\n", c, (*m).count);
	}
	int j;
	//loop over from num letter to 0
    for (j=NUM_LETTERS-1; j>=0; j--){
    	//if the value that holds by the childreb in index j to m is not null
		if (m->children[j]!=NULL){
			//so we update the char c in index i
			c[i] = m->children[j]->letter;
			printD(m->children[j], c, i);
		}
	}
}

void ToMove(node* m,char i){
	//to move over the node , we update the m 
	m=m->children[i-'a'];
}
