#include <stdio.h>  /*printf*/
#include <assert.h> /*assert*/
#include <stdlib.h> /*malloc*/

typedef struct node {
  int data;
  struct node *next;
} node;

void add(node *head, int x){
  /*pre: head points to the first, empty element. The last element's next is NULL
    post: a new node containing x is added to the end of the list*/
  assert(head!=NULL); //First element exists (our input pointer points to *something*)
  node *p = head; // Create a copy pointer, p, pointing to the same as head.
  while (p->next!=NULL) { // "scroll through" p until we are at the last element. (It's a precond the last elements's next doesn't point to anything)
    p = p->next;
  } /*p points to the last element*/
  node *element = (node*) malloc(sizeof(node)); //Declare node pointer "element" and allocate memory for it
  element->next = NULL; //Set elements next to NULL (it'll be the last element)
  element->data = x; // Set elements data to the input x data
  p->next = element; // Make element the next for p, which was the last slot in the input head.
}

int size(node *l){
  // Excercise 3b)
  assert(l!=NULL); // Same precond, inputs needs to exist
  node *p = l;
  int count = 0; // Start counter for size at 0
  while(p->next!=NULL){ 
    p = p->next; //Progress through the list
    count++; //while the current node's "next" pointer is defined, count 1 up.
  }
  return count;
}

void printout(node *l) {
  /*Excercise 3d) Implement your changes.. 
    pre: head points to the first, empty element. The last element's next is NULL
    post: the values of the list are printed out*/
    node *p = l->next;
    while (p->next!=NULL){ //Check if we are at the final node
      printf("%d\n, ",p->data);
      p = p->next; //Continue to next node.
    }
}

int largest(node *l){
  /*Excercise 3e) Add your code below.*/
  assert(l!=NULL); //assert l is defined
  if (l->next == NULL) return -1; //Nothing in the input list
  node *p = l->next; //Create local pointer p, that points to the same as l
  int i = 0; //Counter variable
  int *dataElements = malloc(sizeof(int) * size(l)); //Allocate memory for data elements in an array.
  for(int i = 0; i < size(l); i++){
    dataElements[i] = p->data; //Input current data into data array
    if(p->next != NULL) p = p->next; //If not at final node, continue
  }
  int highest = max(dataElements, size(l));
  return highest; 
   /*pre: head points to the first, empty element. The last element's next is NULL. size(l>0)
    post: returns the largest value of the list*/
}

