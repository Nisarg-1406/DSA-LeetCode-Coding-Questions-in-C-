    vector<int> q;
    int front, rear, N;
    bool empty;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        front = 0; 
        rear = 0;
        N = k;
        q = vector<int> (k);
        empty = true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        empty = false;
        q[rear] = value;
        rear = (rear + 1) % N;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        q[front] = 0;
        front = (front + 1) % N;
        if (front == rear) empty = true;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return q[(rear - 1 + N) % N];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return empty;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (empty) ? false : front == rear;
    }
