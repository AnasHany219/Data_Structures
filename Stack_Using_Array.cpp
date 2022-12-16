#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
class stack{
private:
    int top;
    int items[MAX_SIZE];
public:
// Default Constructor
    stack(){
        top = -1;
    }
// Check full stack
    bool isFull(){
        return top >= MAX_SIZE;
    }
// Add Element to stack
    void push(int Element){
        if(isFull()){
            cout << "\nThe Stack is full.\n";
        }
        else{
            top++;
            items[top] = Element;
        }
    }
// Check empty stack
    bool isEmpty(){
        return top < 0;
    }
// Remove last element
    void pop(){
        if(isEmpty()){
            cout << "\nThe Stack is empty.\n";
        }
        else{
            top--;
        }
    }
// Get the last element
    int Top(){
        if(isEmpty()){
            cout << "\nThe Stack is empty.\n";
        }
        else{
            return items[top];
        }
    }
// Display All Element
    void Display(){
        cout << "\n";
        for(int i = top; i >= 0; i--)
            cout << items[i] << " ";
        cout << "\n";
    }
};
int main() {
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.push(30);
    st.push(40);
    st.push(50);
    cout << st.Top();   // 50
    st.Display();       // 10 20 30 40 50
    return 0;
}
