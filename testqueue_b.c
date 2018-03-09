/* testqueue_b.c has seven functions - make_empty(void), is_empty(void), is_full(void), enqueue(Item i), dequeue(void), first(void), last(void). The main() function, using these aforementioned functions, initializes a queue, enqueues a few given values, dequeues while printing the removed values, enqueues once more, and then dequeues the rest of the numbers on the queue (also printing the removed values) */
/* These functions, respectively, all use an array-based implementation of the queue module to initialize a queue, check if the queue is empty, checks if the queue is full, inserts an item at the end of the queue, removes and returns an item from the beginning of the queue, returns the first item in the queue, and returns the last item in the queue */

#include "queue.h"			/* include interface for the queue module */
#include <stdio.h>

#define MAX_QUEUE_SIZE 100			/* assume MAX_QUEUE_SIZE=100 */

Item queue[MAX_QUEUE_SIZE];			/* declare queue, an array containing Items */

int firstindex;						/* integer storing the position of the next item to be removed */
int lastindex;						/* integer storing the position of the first empty slot in the array */
int size;							/* integer storing the number of items in the queue */

	
void make_empty(void){				/* Initializing the queue */
	firstindex = 0;					/* start at index 0 */
	lastindex = 0;					/* start at index 0 */
	size = 0;						/* no items */
	return;
}


bool is_empty(void){				/* Checking if the queue is empty */
	if (size == 0){					/* if no items */
		return true;				/* the queue is empty */
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
	else{														/* otherwise */
		int nextlastindex = (lastindex + 1) % MAX_QUEUE_SIZE;	/* the next last index is right after the current last index (% MAX_QUEUE_SIZE to allow for wrapping around array)  */
		queue[lastindex] = i;									/* set the value at the last index as the given Item */
		lastindex = nextlastindex;								/* the next last index has now been designated as the last index */
		size += 1;												/* increment size */
	}
	return;
}


Item dequeue(void){															/* Removing an item from the beginning of the queue */
	if(is_empty() == true){													/* if the queue is empty */
    	printf("The queue is already empty. Returning empty Item.\n");		/* report */
	}

	int removed = queue[firstindex];										/* the value at the current first index is the value to be removed */
 	
 	if(size == 1){															/* if we only have one item in the queue */
    	firstindex = 0;														/* start back at index 0 */
    	lastindex = 0;														/* start back at index 0 */
    	size -= 1;															/* decrement size */
    }
  	
  	else{																	/* otherwise (not empty and more than one item present in queue) */
    	int nextfirstindex = (firstindex + 1) % MAX_QUEUE_SIZE;				/* the next first index is right after the current first index (% MAX_QUEUE_SIZE to allow for wrapping around array) */
    	firstindex = nextfirstindex;										/* the next first index has now been designated as the first index */

    	size -= 1;															/* decrement size */
	}

	return removed;															/* return the removed value */
}


Item first(void){													/* Returning the first item in the queue (without removing it) */
	if(is_empty() == true){											/* if the queue is empty */
		printf("The queue is empty. Returning empty Item.\n");		/* report */
	}
	return queue[firstindex];										/* return the first value */
}


Item last(void){													/* Returning the last item in the queue (without removing it) */
	if(is_empty() == true){											/* if the queue is empty */
		printf("The queue is empty. Returning empty Item.\n");		/* report */
	}
	return (queue[(lastindex-1) % MAX_QUEUE_SIZE]);					/* return the last value, which should be right before the lastindex (% for wrapping) */
}		


int main(){					/* function to test array-based implementation of queue */
	
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
	printf("%d\n", dequeue());

	enqueue(42);					/* enqueing 42 */


	printf("\nDequeuing the rest of the queue:\n");		/* now dequeuing six times (removing the rest of the values), printing the removed values */
		
	printf("%d\n", dequeue());							
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n", dequeue());
	printf("%d\n\n", dequeue());

	return 0;
}
