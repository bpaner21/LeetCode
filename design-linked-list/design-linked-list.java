class MyLinkedList {
    
    // singly linked list implementation
    
    private class Node {
        
        int val;
        Node next;
        
        Node(int v) {
            
            this.val = v;
            this.next = null;
        }
    }
    
    private Node head;
    private Node tail;
    private int size;

    public MyLinkedList() {
        
        this.head = null;
        this.tail = null;
        this.size = 0;
    }
    
    public int get(int index) {
        
        if (index < 0 || this.size <= index) { return -1; }
        
        Node temp = head;
        
        for (int i = 0; i < index; ++i) { temp = temp.next; }
        
        return temp.val;
    }
    
    public void addAtHead(int val) {
        
        Node newHead = new Node(val);
        
        newHead.next = head;
        
        head = newHead;
        
        if (tail == null) { tail = newHead; }
        
        ++size;
        
        return;
    }
    
    public void addAtTail(int val) {
        
        Node newTail = new Node(val);
        
        if (tail != null) { tail.next = newTail; }
        
        tail = newTail;
            
        if (head == null) { head = newTail;}
            
        ++size;    
            
        return;
    }
    
    public void addAtIndex(int index, int val) {
        
        if (index < 0 || size < index) { return; }
        
        
        if (index == 0) { addAtHead(val); }
        
        else if (index == size) { addAtTail(val); }
        
        else {
            
            Node temp = head;
            
            for (int i = 1; i < index; ++i) { temp = temp.next; }
            
            Node n = new Node(val);
            
            Node t2 = temp;
            
            temp = temp.next;
            
            t2.next = n;
            
            n.next = temp;
            
            ++size;
        }
        
        return;
    }
    
    public void deleteAtIndex(int index) {
        
        if (size == 0 || index < 0 || size <= index) { return; }
        
        
        // delete at head
        if (index == 0) {
            
            head = head.next;
            
            if (head == null) { tail = null; }
            
            else if (head.next == null) { tail = head; }
        }
        
        // delete at tail or anywhere else
        else {
            
            Node temp = head;
            
            for (int i = 1; i < index; ++i) { temp = temp.next; }
            
            temp.next = temp.next.next;
            
            if (temp.next == null) { tail = temp; }
        }
        
        --size;
        
        return;
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */