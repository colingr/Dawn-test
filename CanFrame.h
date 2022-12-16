struct CanFrame
{
    static const uint8_t MaxDataLen = 8;

    uint32_t id;
    uint8_t data[MaxDataLen];
    uint8_t dlc;
}

class RxQueue
{
    CanFrame buf_[64];

    const uint8_t capacity_ = 64u;
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