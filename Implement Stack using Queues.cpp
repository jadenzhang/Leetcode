class Stack {
public:
    queue<int> q1;
    int t;
    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
        t=x;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.size()==1) q1.pop();
        else{
            for(int i=0;i<=q1.size()-2;i++){
                q1.push(q1.front());
                q1.pop();
            }
            q1.pop();
            t=q1.back();
        }
    }

    // Get the top element.
    int top() {
        return t;
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};
