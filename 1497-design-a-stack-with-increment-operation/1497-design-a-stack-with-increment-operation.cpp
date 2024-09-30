class CustomStack {
public:
    CustomStack(int maxSize) : maxSize(maxSize) {}

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
            increments.push_back(0); 
        }
    }

    int pop() {
        if (stack.empty()) return -1;

        int idx = stack.size() - 1;
        int val = stack[idx] + increments[idx]; 
        stack.pop_back();

        if (idx > 0) increments[idx - 1] += increments[idx]; 
        increments.pop_back(); 

        return val;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size()) - 1;
        if (limit >= 0) increments[limit] += val; 
    }

private:
    vector<int> stack;       
    vector<int> increments; 
    int maxSize;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
