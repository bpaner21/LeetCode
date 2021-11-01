class MyLinkedList {

// singly linked list
    
private:    
    
    struct Node {

        int val;
        Node* next;

        Node(int v) {

            val = v;
            next = nullptr;
        }
    };
    
    
    Node* head;
    Node* tail;
    
    int size;
    
    
public:
    MyLinkedList() {
        
        head = nullptr;
        tail = nullptr;
        
        size = 0;
    }
    
    int get(int index) {
        
        if (index < 0 || size <= index) { return -1; }
        
        
        Node* temp = head;
        
        for (int i = 0; i < index; ++i) { temp = temp->next; }
        
        return temp->val;
    }
    
    void addAtHead(int val) {
        
        Node* newHead = new Node(val);
        
        newHead->next = head;
        
        head = newHead;
        
        if (tail == nullptr) { tail = newHead; }
        
        newHead = nullptr;
        
        ++size;
        
        return;
    }
    
    void addAtTail(int val) {
        
        Node* newTail = new Node(val);
        
        if (tail != nullptr) { tail->next = newTail; }
        
        tail = newTail;
            
        if (head == nullptr) { head = newTail;}
        
        newTail = nullptr;
            
        ++size;    
            
        return;
    }
    
    void addAtIndex(int index, int val) {
        
        if (index < 0 || size < index) { return; }
        
        
        if (index == 0) { addAtHead(val); }
        
        else if (index == size) { addAtTail(val); }
        
        else {
            
            Node* temp = head;
            
            for (int i = 1; i < index; ++i) { temp = temp->next; }
            
            Node* n = new Node(val);
            
            n->next = temp->next;
            
            temp->next = n;
            
            n = nullptr;
            
            temp = nullptr;
            
            ++size;
        }
        
        return;
    }
    
    void deleteAtIndex(int index) {
        
        if (size == 0 || index < 0 || size <= index) { return; }
        
        Node* temp = head;
        
        // delete at head
        if (index == 0) {
            
            head = head->next;
            
            if (head == nullptr) { tail = nullptr; }
            
            else if (head->next == nullptr) { tail = head; }
        }
        
        // delete at tail or anywhere else
        else {
            
            for (int i = 1; i < index; ++i) { temp = temp->next; }
            
            temp->next = temp->next->next;
            
            if (temp->next == nullptr) { tail = temp; }
        }
        
        temp = nullptr;
        
        --size;
        
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */