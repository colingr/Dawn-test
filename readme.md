# RxQueue implementation

## design thoughts

The most developer efficient way to implement this would be to use something like [boost circular_buffer](https://www.boost.org/doc/libs/1_61_0/doc/html/circular_buffer.html) :) 

But assuming you want me to implement.... 

We want this queue to be as efficient as possible, so minimise unnecessary copying of data,
but it also needs to provide safety.

Because the queue is a fixed length, we want to be able to track the front and rear of the queue, and allow data to overwrite the beginning of the buffer if necessary

on initialisation the queue is empty

```
==========================
|    |    |    |    |    |
==========================

front is -1 to signify empty queue
rear is 0
```

adding an element will put the element at the start of the queue (aka the beginning of the buffer at this point)

```
front = 0
==========================
| e1 |    |    |    |    |
==========================
     rear = 1
```

adding another element will put the element at the back of the queue

```
front = 0
==========================
| e1 | e2 |    |    |    |
==========================
          rear = 2
```

popping an element will take copy the data from the front of the queue and move the front back one element
NB: the data in e1 has not been changed, and the space is available for use later
```
     front = 1
==========================
| e1 | e2 |    |    |    |
==========================
          rear = 2
```

if we reach the end of the buffer, we can reuse the beginning of the buffer if available
```
"full" buffer
     front = 1
==========================
| e1 | e2 | e3 | e4 | e5 |
==========================
                         rear = 5

add another element
     front = 1
==========================
| e6 | e2 | e3 | e4 | e5 |
==========================
     rear = 1
```

The queue is now full and if we try to add another element `push` should fail

if we pop all the elements (e.g. front catches up to rear) reset the indices and start over 

## Testing considerations

To ensure correction of this implementation, I would implement a suite of unit tests. Potentially, a good option would be a compile time switch or friend function to allow the test suite access to the buffer. It would also be possible to "black box" test this class, but given that pop is a stateful function, it might be better to implement a peek() function.

Edge cases include: 
- the queue is empty/full
- reaching the end of the buffer
- checking the length is correct if the rear of the queue is ahead of the front
- resetting the queue allows pushing at the beginning again and the popping returns false.

# Implementing the CAN driver
I am not familiar with the CAN protocol, so this is very much a guess.

I have implemented a simple processing looping that pops frames from the queue and processes them.

# Considerations
RxQueue is not thread safe. 

