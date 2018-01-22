/*
  listIteratorInt.c : list Iterator ADT implementation
  Written by Anggi Permana Harianja 
  Date: 1/1/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "listIteratorInt.h"

typedef struct Node {

  // implement struct here .. 
  int     val; //node value
  struct  Node *prevNode; //pointer to previous node
  struct  Node *nextNode; //pointer to nextNode
} Node;

typedef struct IteratorIntRep {

  // implement struct here ..
  //pay attention to struct node typedata 
  int   nNodes; //number of nodes
  Node  *firstNode; //first node
  Node  *currentNode; //current node
  Node  *lastNode; //last node 
} IteratorIntRep;


/*

  Your local functions here, if any.... 

 */
void myFunc(int **pointer){
  *pointer = NULL;  
}

int storedValue;
int step;


//if you wanna know why return value is
//IteratorInt take a look at 
//listIteratorint.h
IteratorInt IteratorIntNew(){

  // implement this function
  struct IteratorIntRep *Iterator;
  Iterator = malloc(sizeof(struct IteratorIntRep)); //reserve space for Iterator
  assert(Iterator != NULL);

  Iterator->nNodes      = 0;
  Iterator->firstNode   = NULL;
  Iterator->currentNode = NULL;
  Iterator->lastNode    = NULL; 

  //return pointer *IMPORTANT*
  return Iterator;  // you need to change this...
}

void reset(IteratorInt it){

  //move currentNode to firstNode
  it->currentNode = it->firstNode;
  return;
}


int add(IteratorInt it, int v){
  
  // implement this function
  struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->val = v;


  if(it->firstNode == NULL){
    it->firstNode = newNode;
    return 1;
  }

  if(it->lastNode == NULL){
    it->lastNode = newNode;
    it->firstNode->nextNode = it->lastNode;
    it->lastNode->prevNode = it->firstNode;

  }

  newNode->prevNode = it->lastNode;
  newNode->nextNode = NULL;

  if(it->lastNode != NULL){
    it->lastNode->nextNode = newNode;
  } 

  it->lastNode    = newNode;
  it->currentNode = it->lastNode;

  it->nNodes++;

  if(it->lastNode->val == v){
    storedValue = 0;
    return 1;
  }
  return 0;

}


int hasNext(IteratorInt it){
  
  // implement this function
  if(it->currentNode == it->lastNode){
    return 0;
  }
  if(it->currentNode->nextNode != NULL){
    return 1;
  }
  //mark as invalid move
  storedValue = 0;
  step = 3;
  return 0;  // you need to change this...
}

int hasPrevious(IteratorInt it){
  
  // implement this function
  if(it->currentNode == it->firstNode){
    return 0;
  }
  if(it->currentNode->prevNode != NULL){
    return 1;
  }
  //mark as invalid move
  storedValue = 0;
  step = 3;
  return 0;  // you need to change this...
}


int *next(IteratorInt it){
  
  // implement this function
  int *nextNode = NULL;
  int result;

  //there will be no more node after lastNode
  if(it->currentNode == it->lastNode){
    nextNode = NULL;
    //mark as invalid move
    storedValue = 0;
    step = 3;
    return nextNode;
  }

  if(it->currentNode == it->firstNode){
    result = it->firstNode->val;
  } else {
    result = it->currentNode->nextNode->val;

  }
  it->currentNode->nextNode->prevNode = it->currentNode;
  it->currentNode = it->currentNode->nextNode;
  nextNode        = &result;

  storedValue = result;
  step = 1;

  return nextNode;  // you need to change this...
}

int *previous(IteratorInt it){


  int *previousNode = NULL;
  int result;
  
  if(it->currentNode == it->firstNode){
    previousNode = NULL;
    //mark as invalid move
    storedValue = 0;
    step = 3;
    return previousNode;
  } 
  
  if(it->currentNode == it->lastNode){
    result = it->lastNode->val;
  } else {
    result = it->currentNode->val;

  }
  it->currentNode->prevNode->nextNode = it->currentNode;
  it->currentNode = it->currentNode->prevNode;
  previousNode    = &result;

  storedValue = result;
  step = 0;

  return previousNode;  // you need to change this...

}


int deleteElm(IteratorInt it){
  
  // implement this function 
  if(step == 3){
    storedValue = 0;
    step = 3;
    return 0;
  }

  if(step == 2){
    it->currentNode->prevNode->nextNode = it->currentNode->nextNode;
    storedValue = 0;
    step = 3;
    return 1;
  }
  else if(step == 1){
    if(it->currentNode->prevNode == it->firstNode){
      it->firstNode = it->currentNode;
    } else{
      it->currentNode->prevNode = it->currentNode->prevNode->prevNode;
    }
    it->currentNode->prevNode->nextNode = it->currentNode;
    storedValue = 0;
    step = 3;
    return 1;
  }
  else if(step == 0){
    if(it->currentNode->nextNode == it->lastNode){
      it->lastNode = it->currentNode;
    } else {
      it->currentNode->nextNode = it->currentNode->nextNode->nextNode;
    }
    it->currentNode->nextNode->prevNode = it->currentNode;
    storedValue = 0;
    step = 3;
    return 1;
  }  

  //mark as invlid move after that
  storedValue = 0;
  step = 3;
  return 0;  // you need to change this...
}


int set(IteratorInt it, int v){
  
  // implement this function
  if(step == 3){
    storedValue = 0;
    step = 3;
    return 0;
  }

  if(storedValue != 0){
    if(step == 2){
      it->currentNode->val = v;
      storedValue = 0;
      step = 3;
      return 1;
    }
    else if(step == 1){
      it->currentNode->prevNode->val = v;
      storedValue = 0;
      step = 3;
      return 1;
    }
    it->currentNode->nextNode->val = v;
    storedValue = 0;
    step = 3;
    return 1;
  }
  //mark as invalid move after that
  storedValue = 0;
  step = 3;
  return 0; 

}

int *findNext(IteratorInt it, int v){

  // implement this function
  int *findNextNode = NULL;
  int result; 
  int i = 0;
  
  Node *tmpNode;
  tmpNode = it->currentNode;


  if(tmpNode == it->lastNode){
    findNextNode = NULL;
    //mark as invalid move
    storedValue = 0;
    step = 3;
    return findNextNode;
  }

  while(tmpNode->val != v){
    i++;
    tmpNode = tmpNode->nextNode;
    if(tmpNode == it->lastNode){
      findNextNode = NULL;
      //mark as invalid move
      storedValue = 0;
      step = 3;
      return findNextNode;

    }
  }

  //currentNode move to tmpNode
  while(i >= 0){
    it->currentNode = it->currentNode->nextNode;
    i--;
  }
  result = it->currentNode->val;
  findNextNode = &result;

  storedValue = result;
  step = 2;

  return findNextNode; 

}

int *findPrevious(IteratorInt it, int v){
  
  // implement this function
  int *findPreviousNode = NULL;
  int result;
  int i = 0;

  Node *tmpNode;
  tmpNode = it->currentNode;


  if(tmpNode == it->firstNode){
    findPreviousNode = NULL;
    //mark as invalid move
    storedValue = 0;
    step = 3;
    return findPreviousNode;
  }

  while(tmpNode->val != v){
    i++;
    tmpNode = tmpNode->prevNode;
    if(tmpNode == it->firstNode){
      findPreviousNode = NULL;
      //mark as invalid move
      storedValue = 0;
      step = 3;
      return findPreviousNode;
    }
  }

  //currentNode move to tmpNode
  while(i >= 0){
    it->currentNode = it->currentNode->prevNode;
    i--;
  }
  result = it->currentNode->val;
  findPreviousNode = &result;

  storedValue = result;
  step = 2;
  
  return findPreviousNode;
  
}

void freeIt(IteratorInt it){

  // implement this function 
  assert(it != NULL);
  Node *currentNode, *prevNode;
  currentNode = it->firstNode;
  
  while(currentNode != NULL){
    prevNode = currentNode;
    currentNode = currentNode->nextNode;
    free(prevNode);
  } 
  free(it);

  return;

}





