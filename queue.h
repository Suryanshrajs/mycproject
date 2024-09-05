
// Function to initialize the queue
void initQueue(struct Queue* queue);

// Function to check if the queue is full
int isFull(struct Queue* queue);

// Function to check if the queue is empty
int isEmpty(struct Queue* queue);

// Function to enqueue (add) an element to the queue
void enqueue(struct Queue* queue, int value);

// Function to dequeue (remove) an element from the queue
int dequeue(struct Queue* queue) ;

// Function to peek at the front element of the queue
int peek(struct Queue* queue);
