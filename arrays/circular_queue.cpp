class MyCircularQueue {
public:
    int mxSize=0,head=0,tail=-1;
    vector<int> arr;
    
    MyCircularQueue(int k) {
        arr.resize(k);
        mxSize = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        tail = (tail+1)%mxSize;
        arr[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(head==tail) head =0, tail=-1;
        else{
            head = (head+1)%mxSize;
        }
        return true;
    }
    
    int Front() {
         return isEmpty() ? -1 : arr[head];
    }
    
    int Rear() {
        return isEmpty() ? -1 : arr[tail];
    }
    
    bool isEmpty() {
        return tail==-1;
    }
    
    bool isFull() {
        return !isEmpty() && (tail+1)%mxSize == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
