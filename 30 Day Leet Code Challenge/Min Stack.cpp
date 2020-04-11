class MinStack {
public:
    /** initialize your data structure here. */
    stack<pair<int,int>> myStack; 
    MinStack() 
    {}
    void push(int x){
        if(myStack.empty()){
            myStack.push(make_pair(x,x));
        } 
        else{
            int minElement = getMin();
            myStack.push(make_pair(x,min(x,minElement)));
        }
    }
    void pop(){
        if(!myStack.empty())
            myStack.pop();
    }
    int top(){
        if(!myStack.empty()){
            return myStack.top().first; 
        }
        return -1;
    }
    int getMin(){
        if(!myStack.empty()){
            return myStack.top().second;    
        }
        return -1; 
    }
};