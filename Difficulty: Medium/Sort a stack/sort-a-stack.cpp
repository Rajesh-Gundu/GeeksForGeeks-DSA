/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void insertIntoS(stack<int>& s,int x) {
    if(s.empty() || x >= s.top()) {
        s.push(x);
        return;
    }
    
    int t = s.top();
    s.pop();
    insertIntoS(s,x);
    s.push(t);
}

void SortedStack ::sort() {
    // Your code here
    if(s.empty())   return;
    
    int x = s.top();
    s.pop();
    sort();
    insertIntoS(s,x);
}