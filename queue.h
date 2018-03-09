/* queue.h contains the interface for the queue module. It contains prototypes for functions in the public interface */

#include "queuetypes.h"			/* include type definition of Item */
#include <stdbool.h>

void make_empty(void);			/* Initializing the queue */
bool is_empty(void);			/* Checking if the queue is empty */
bool is_full(void);				/* Checking if the queue is full */
void enqueue(Item i);			/* Inserting an item at the end of the queue */
Item dequeue(void);				/* Removing an item from the beginning of the queue */
Item first(void);				/* Returning the first item in the queue (without removing it) */
Item last(void);				/* Returning the last item in the queue (without removing it) */