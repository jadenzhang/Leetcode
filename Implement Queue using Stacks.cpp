class Queue {
public:
    stack<int> s1,s2;
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s1.size()==1) {s1.pop();return;}
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int tp;
        if (s1.size()==1) return s1.top();
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        tp = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return tp;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};
