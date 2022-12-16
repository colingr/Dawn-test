#include "RxQueue.h"

// initialise the queue indices
RxQueue::RxQueue()
{
    reset();
}

bool RxQueue::push(const CanFrame& frame)
{
    if (rear_ == front_)
    {
        registerOverflow();
        return false; // signify push failed
    }

    if (front_ = -1)
    {
        front_ = 0;
    }

    // insert the frame at the 
    buf_[rear_]= frame;
    rear_++;
    
    if (rear_ > capacity_)
    {
        rear_ = 0;
    }

}

bool RxQueue::pop(CanFrame& frame)
{
    if (front_ == -1)
    {
        return false;   
    }

    frame = buf_[front_];
    front_++; 

    if (front_ == capacity_ )
    {
        front_ = 0;
    }

    if (front_ == rear_)
    {
        reset();
    }

    
    return true;

}

void RxQueue::reset()
{
    // initialise the indices
    // we don't care about the data buffer as we will overwrite it as we go
    front_ = -1;
    rear_ = 0;
}

void RxQueue::registerOverflow()
{
    overflow_cnt_++;
}

uint8_t RxQueue::getLength()
{
    if (front_ == -1)
    {
        return 0;
        
    }
    if (rear_ >= front_)
    {
        return rear_ - front_;
    }
    else 
    {
        return rear_ + capacity_ - front_;
    }    
}