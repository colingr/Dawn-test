
// this is a standard singly linked list that uses dynamic memory
// the complexity of this solution is o(n).
// deleting the node will only use stack memory for this method


class List
{
public:
    struct Node
    {
        char data;
        Node* next;
    };

    Node* head_;
    
// push, etc omitted

    bool deleteNode(const Node& node) 
    {
        if (head_ == nullptr)
        {
            // empty list;
            return false;
        }

        Node* temp = head_;

        Node* prev;
        while (temp.data != node.data)
        {
            prev = temp;
            temp = temp->next
            if (temp == nullptr)
                return false;
        }

        if (prev != nullptr)
        {
            prev->next = temp;
        }
        delete temp;
         
        return true;

    }
        
};