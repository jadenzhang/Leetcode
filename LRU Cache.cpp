class LRUCache{
private:
    struct Node{
        Node* pre;
        Node* next;
        int key;
        int value;
        Node(int k, int v):key(k),value(v){}
    };
    
    int MaxSize;
    unordered_map<int,Node*> KeyToNode;
    Node* head;
    Node* tail;
    
    void MoveToEnd(Node* node){
        if (head == tail) return;
        
        if (node == head){
            head = head->next;
            head -> pre = NULL;
        }
        else if (node == tail) return;
        else{
            node->next->pre = node->pre;
            node->pre ->next = node->next;
        }
        
        tail->next = node;
        node->next = NULL;
        node->pre = tail;
        tail=tail->next;
    }
    
    void AddNode(Node* node){
        if (!head && !tail){
            head = tail = node;
        }
        else{
            tail->next = node;
            node->next = NULL;
            node->pre = tail;
            tail = tail->next;
        }
    }
    
    void DeleteNode(){
        KeyToNode.erase(head->key);
        if (head == tail){
            head = tail = NULL;
        }
        else{
            head = head->next;
            head->pre = NULL;
        }
    }
    
    
public:
    LRUCache(int capacity) {
        MaxSize = capacity;
        head = NULL;
        tail = NULL;
        KeyToNode.clear();
    }
    
    int get(int key) {
        if (KeyToNode.count(key)==0) return -1;
        MoveToEnd(KeyToNode[key]);
        return KeyToNode[key]->value;
    }
    
    void set(int key, int value) {
        if (get(key) != -1){
            KeyToNode[key]->value = value;
            return;
        }
        Node* node = new Node(key,value);
        KeyToNode[key] = node;
        AddNode(node);
        if (KeyToNode.size()>MaxSize) DeleteNode();
    }
};
