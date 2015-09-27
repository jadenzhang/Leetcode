class MinStack {
    stack<int> s;
    stack<int> Min;
public:
    void push(int x) {
        if (Min.empty() || x<=Min.top()) Min.push(x);
        s.push(x);
    }

    void pop() {
        if (s.empty()) return;
        if (Min.top()==s.top()) Min.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return Min.top();
    }
};
