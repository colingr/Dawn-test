#include "CanFrame.h"

// initialise the queue indices
RxQueue::RxQueue()
: in_(-1)
, out(-1)
, len(0)
{}

void RxQueue::push(const CanFrame& frame)
{

}