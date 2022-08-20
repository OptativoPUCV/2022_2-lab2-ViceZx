#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *list = (List *) malloc (sizeof(List));
	list->head = NULL;
	list->tail = 0;
	list->current = NULL;
	return list;
}

void * firstList(List * list) {
  if(list -> head && list -> head -> data){
    list -> current = list -> head;
    return list -> head -> data;
  }
  return NULL;
}


void * nextList(List * list) {
  if(list -> current && list -> current -> next){
    list -> current = list -> current -> next;
    return list -> current -> data;
  }
  return NULL;
}

void * lastList(List * list) {
    if(list -> tail && list -> tail -> data){
    list -> current = list -> tail;
    return list -> tail -> data;
  }
  return NULL;
}

void * prevList(List * list) {
  if(list -> current && list -> current -> prev){
    list -> current = list -> current -> prev;
    return list -> current -> data;
  }
  return NULL;
}

void pushFront(List * list, void * data) {
  Node * nodo = createNode(data);
  nodo -> next = list -> head;
  list -> tail = nodo;
  list -> head = nodo;

}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  //Programe la función `void pushCurrent(List * list, void* data)`, la cual agrega un dato a continuación del nodo apuntado por `list->current`.
  Node * nodo = createNode(data);
  nodo -> prev = list -> current;
  list -> head -> next = nodo;
  nodo -> next = list -> current;
  list -> tail = nodo;
  // if(L->tail == NULL || L->tail->data != j){
       // err_msg("tail deberia apuntar al nuevo nodo");
        //return 0;
   // }

    //if(aux->next == NULL || aux->next!=L->tail){
        //err_msg("aux->next deberia apuntar a nuevo tail");
        //return 0;
    //}

    //if(L->tail->prev == NULL || L->tail->prev!=aux){
       // err_msg("tail->prev deberia apuntar a aux");
      //  return 0;
    //}
 
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}