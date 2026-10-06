class MyHashMap {
private:
    struct ListNode{
        int key;
        int value;
        ListNode* next;

        ListNode(int key = -1 ,int value = -1){
            this->key=key;
            this->value=value;
            this->next=nullptr;
        }
    };

    vector<ListNode*> map;

    int hash(int key){
        return key % map.size();
    }
public:
    MyHashMap() {
        map.resize(1000);
        for(auto& bucket : map){
            bucket=new ListNode(-1);
        }
    }
    
    void put(int key, int value) {
        int index=hash(key);
        ListNode* p=map[index];

        while(p->next){
            if(p->next->key==key){
                p->next->value=value;
                return;
            }
            p=p->next;
        }
        p->next=new ListNode(key,value);
        
    }
    
    int get(int key) {
        int index=hash(key);
        ListNode* p=map[index];

        while(p->next){
            if(p->next->key==key){
                return p->next->value;
            }
            p=p->next;
        }
        return -1;
        
    }
    
    void remove(int key) {
        int index=hash(key);
        ListNode* p=map[index];

        while(p->next){
            if(p->next->key==key){
                break;
            }
            p=p->next;
        }

        if(p->next){
            ListNode* temp=p->next;
            p->next=p->next->next;
            delete temp;
        }
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */