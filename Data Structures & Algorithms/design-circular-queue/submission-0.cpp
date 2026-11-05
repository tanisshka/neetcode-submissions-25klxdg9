class MyCircularQueue {
private:
    vector<int> queue;
    int capacity;
    int front;
    int rear;

public:
    MyCircularQueue(int k) {
        capacity=k;
        queue.resize(k);
        front=-1;
        rear=-1;  
    }
    
    bool enQueue(int value) {
        if(front==-1){
            front=0;
            rear=0;
            queue[rear]=value;
            return true;
        }else if((rear+1)%capacity == front){
            return false;
        }else{
            rear=(rear+1)%capacity;
            queue[rear]=value;
            return true;
        }
        
    }
    
    bool deQueue() {
        if(front==-1){
            return false;
        }
        else if(front==rear){
            front=-1;
            rear=-1;
            return true;
        }else{
            front=(front+1)%capacity;
            return true;
        }
    }
    
    int Front() {
        if(front==-1){
            return -1;
        }
        return queue[front];
    }
    
    int Rear() {
        if(rear==-1){
            return -1;
        }
        return queue[rear];
        
    }
    
    bool isEmpty() {
        return front==-1;
        
    }
    
    bool isFull() {
        return (rear+1)%capacity==front;
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