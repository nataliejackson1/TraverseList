class Node
{
    friend class LinkedList;
private:
    int _value; /* data, can be any data type, but use integer for easiness */
    Node *_pNext; /* pointer to the next node */
    
public:
    /* Constructors with No Arguments */
    Node(void)
    : _pNext(NULL)
    { }
    
    /* Constructors with a given value */
    Node(int val)
    : _value(val), _pNext(NULL)
    { }
    
    /* Constructors with a given value and a link of the next node */
    Node(int val, Node* next)
    : _value(val), _pNext(next)
    {}
    
    /* Getters */
    int getValue(void)
    { return _value; }
    
    Node* getNext(void)
    { return _pNext; }
};

/* definition of the linked list class */
class LinkedList
{
private:
    /* pointer of head node */
    Node *_pHead;
    /* pointer of tail node */
    Node *_pTail;
    
public:
    /* Constructors with a given value of a list node */
    LinkedList(int val);
    /* Destructor */
    ~LinkedList(void);
    
    /* Function to append a node to the end of a linked list */
    void tailAppend(int val);
    
    /* Traversing the list and printing the value of each node */
    void traverse_and_print();
};

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    _pHead = new Node(val);
    _pTail = _pHead;
}

LinkedList::LinkedList(int val)
{
    /* Create a new node, acting as both the head and tail node */
    _pHead = new Node(val);
    _pTail = _pHead;
}

    /*
     * Leave it empty temporarily.
     * It will be described in detail in the example "How to delete a linkedlist".
     */
}

void LinkedList::tailAppend(int val)
{
    /* The list is empty? */
    if (_pHead == NULL) {
        /* the same to create a new list with a given value */
        _pTail = _pHead = new Node(val);
    }
    else
    {
        /* Append the new node to the tail */
        _pTail->_pNext = new Node(val);
        /* Update the tail pointer */
        _pTail = _pTail->_pNext;
    }
}

void LinkedList::traverse_and_print()
{
    Node *p = _pHead;
    
    /* The list is empty? */ if (_pHead == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    
    /* You can traverse a list in a basic way like below 
     *   a) get the first node
     *   b) do your work with this node
     *   c) move to the next node
     *  Repeat b)-c) until you meet the end of the list
     */
    
    cout << "LinkedList: ";
    /* A basic way of traversing a linked list */
    while (p != NULL) { /* while there are some more nodes left */
        /* output the value or do something else you want */
        cout << p->_value << " ";
        /* The pointer moves along to the next one */
        p = p->_pNext;
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    /* Create a list with only one node */
    LinkedList list(1);
    /* Append 3 nodes to the end of the list */
    list.tailAppend(2);
    list.tailAppend(3);
    list.tailAppend(4);   
    cout << "Create a list with 4 nodes, and now output the list." << endl;
    
    /* traverse and output the list */
    list.traverse_and_print();
    
    return 0;
}
