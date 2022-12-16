#include <iostream>
using namespace std;
// creating a linked list;
class Node{
public:
    int item;
    Node *next;
};
class stack{
private:
    Node *top;
    Node *current;
public:
// Default Constructor
    stack(){
        top = NULL;
    }
// Add Element in top
    void push(int element){
        Node *NewElement = new Node;
    // Check full memory
        if(NewElement == NULL)
            cout << "Your Memory is Full\n";
        else{
            NewElement->item = element;
            NewElement->next = top;
            top = NewElement;
        }
    }
// Check empty stack
    bool isEmpty(){
        return top == NULL;
    }
    void pop(){
        if(isEmpty()){
            cout << "The Stack is Empty\n";
        }
        else{
            /*Node *temp = new Node;
            temp = top;*/
            Node *temp = top;
            top = top->next;
            temp->next = NULL;
            delete temp;
        }
    }
// Return Top item
    int Top(){
        return top->item;
    }
// Display the elements
    void Display(){
        current = top;
        cout << "\n";
        while(current != NULL)
        {
            cout << current->item << " ";
            current = current->next;
        }
        cout << "\n";
    }
};
int main() {
    stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.pop();
    st.pop();
    st.pop();                   // The Stack is Empty
    st.push(30);
    cout << st.Top() << "\n";   // 30
    st.push(40);
    st.push(50);
    st.Display();               // 50 30 40
    return 0;
}
