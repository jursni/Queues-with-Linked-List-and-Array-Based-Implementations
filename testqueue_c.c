/* testqueue_c.c has seven functions - make_empty(void), is_empty(void), is_full(void), enqueue(Item i), dequeue(void), first(void), last(void). The main() function, using these aforementioned functions, initializes a queue, enqueues a few given values, dequeues while printing the removed values, enqueues once more, and then dequeues the rest of the numbers on the queue (also printing the removed values) */
/* These functions, respectively, all use a link-list implementation of the queue module to initialize a queue, check if the queue is empty, checks if the queue is full, inserts an item at the end of the queue, removes and returns an item from the beginning of the queue, returns the first item in the queue, and returns the last item in the queue */

#include "queue.h"		/* include interface for the queue module */
#include <stdio.h>		
#include <stdlib.h>		/* include for use of malloc and free functions */

#define MAX_QUEUE_SIZE 100		/* assume MAX_QUEUE_SIZE=100 */

struct queue {					/* queue structure */
	Item idata;					/* idata represents Item data stored in current node of linked list */
	struct queue *next;			/* *next is pointer to the next node of linked list */
};
struct queue *firstpointer = NULL; 	/* initialize pointer to first node in linked list */
struct queue *lastpointer = NULL;	/* initialize pointer to final node in linked list */

int size;	/* size of linked list */


void make_empty(void){				/* Initializing the queue */
	
	struct queue *new_queue;		/* variable to point to the new node */
		
		
	new_queue = malloc(sizeof(struct queue));	/* allocate memory for the new node */

	firstpointer = new_queue;		/* new_queue, the new node, is now first node - firstpointer points to the new node */	
	lastpointer = new_queue;		/* new_queue, the new node, is also now the final node - lastpointer points to the new node */
	size = 0;						/* still no data/items in the linked list */
	return;
}


bool is_empty(void){				/* Checking if the queue is empty */
	if (size == 0){					/* if no items */
		return true;				/* then the queue is empty */
	}
	else{							/* otherwise */
		return false;				/* the queue is not empty */
	}
}


bool is_full(void){					/* Checking if the queue is full */
	if (size == MAX_QUEUE_SIZE){	/* if there are as many items as the queue size */
		return true;				/* then the queue is full */
	}
	else{							/* otherwise */
		return false;				/* then the queue is not full */
	}
}


void enqueue(Item i){								/* Inserting an item at the end of the queue */
	if (is_full() == true){							/* if the queue is full */
		printf("The queue is already full\n");		/* report */
	}
	if (is_empty() == true) {								/* if the queue is empty */				
		lastpointer = firstpointer;							/* the last pointer will be the same first pointer - they point to the same node. the first node is now also the final node */
		(firstpointer -> idata) = i;						/* set the idata Item value associated with this new first node/final node to be given Item i */
		(firstpointer -> next) = NULL;						/* set the pointer to the next node after this current first node/final node to be NULL */
		size += 1;											/* increment size */
	}
	else{														/* otherwise */
		(lastpointer -> next) = (struct queue*) malloc(sizeof(struct queue));	/* create a new node for the next node after the current final node */
		lastpointer = (lastpointer -> next);					/* set the lastpointer to now point at the newly created next node after the current final node */
		(lastpointer -> idata) = i;								/* set the idata Item value associated with the node now pointed to by last pointer (the new final node) to be given Item i */
		(lastpointer -> next) = NULL;							/* set the pointer to the new next node to point to NULL */
		size += 1;												/* increment size */
	}
	return;
}


Item dequeue(void){														/* Removing an item from the beginning of the queue */
	Item removed = 0;													/* initialize removed item */
	if (is_empty() == true){											/* if the queue is empty */
		printf("The queue is already empty. Returning empty Item.\n");	/* report */
	}
	else{																/* otherwise */
		removed = firstpointer -> idata;								/* the Item idata value associated with the first node is to be removed */
		firstpointer = firstpointer -> next;							/* set the first pointer to now point to the next node after the initial first node (the one to be removed)*/
		size -= 1;														/* decrement size */		
	}
	return removed;														/* return removed item */
}


Item first(){					/* Returning the first item in the queue (without removing it) */
	if(is_empty() == true){											/* if the queue is empty */
		printf("The queue is empty. Returning empty Item.\n");		/* report */
	}
	return firstpointer -> idata;	/* returns the idata Item value associated with the node pointed to by firstpointer (first node)*/
}


Item last(void){				/* Returning the last item in the queue (without removing it) */
	if(is_empty() == true){												/* if the queue is empty */
		printf("The queue is empty. Returning empty Item.\n");			/* report */
	}
	return lastpointer -> idata; /* returns the idata Item value associated with the node pointed to by lastpointer (final node)*/
}		


int main(){					/* function to test link-list implementation of queue */
	
	make_empty();			/* intializing a queue */
	
	enqueue(45);			/* enqueuing the following numbers */
	enqueue(67);
	enqueue(78);
	enqueue(34);
	enqueue(675);
	enqueue(23);
	enqueue(756);

	printf("\nDequeuing twice:\n");	/* now dequeuing twice, printing the removed values */
	
	
	printf("%d\n", dequeue());
	printf("%d\n\n", dequeue());

	enqueue(42);					/* enqueing 42 */


	printf("Dequeuing the rest of the queue:\n");		/* now dequeuing six times (removing the rest of the values), printing the removed values */
	
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n\n", dequeue());

	return 0;
}


