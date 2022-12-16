#pragma once

#include <stdint.h>

struct CanFrame
{
    static const uint8_t MaxDataLen = 8;

    uint32_t id;
    uint8_t data[MaxDataLen];
    uint8_t dlc;
};

class RxQueue
{
    static const uint8_t capacity_ = 64u;
    
    CanFrame buf_[capacity_];

    uint8_t in_;
    uint8_t out_;
    uint8_t len_;
    uint32_t overflow_cnt_;

    void registerOverflow();

public: 

    RxQueue() {}

    void push(CanFrame frame);
    void pop(CanFrame outFrame);

    void reset();

    unsigned getLength();
    
};