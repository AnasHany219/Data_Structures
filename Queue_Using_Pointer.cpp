#include <iostream>
using namespace std;
class Node{
public:
    int item;
    Node *next;
};
// Creating Circular Queue "FIFO"
class Queue{
private:
    Node *front;
    Node *back;
    Node *current;
    int length;
public:
// Default Constructor
    Queue(){
        front = back = NULL;
        length = 0;
    }
// Check empty queue
    bool isEmpty(){
        return length == 0;
    }
// Add Elements
    void push(int Element)
    {
        if(isEmpty()){
            front = new Node;
            if(front == NULL)
                cout << "Your Memory is Full\n";
            front->item = Element;
            front->next = NULL;
            back = front;
            length++;
        }
        else{
            Node *newptr = new Node;
            if(newptr == NULL)
                cout << "Your Memory is Full\n";
            newptr->item = Element;
            newptr->next = NULL;
            back->next = newptr;
            back = newptr;
            length++;
        }
    }
// Remove First Element
    void pop_front(){
        if(isEmpty())
            cout << "The Queue is Empty\n";
        else{
            Node *temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
            length--;
        }
    }
// Return First ELement
    int Front(){
        if(isEmpty())
            cout << "The Queue is Empty\n";
        else
            return front->item;
    }
// Return Last ELement
    int Back(){
        if(isEmpty())
            cout << "The Queue is Empty\n";
        else
            return back->item;
    }
// Return Number of elements
    int size(){
        return length;
    }
// Printing the element from first
    void Display(){
        if(isEmpty())
            cout << "The Queue is Empty\n";
        else{
            current = front;
            while(current != NULL)
            {
                cout << current->item << " ";
                current = current->next;
            }
            cout << "\n";
        }
    }
// Remove All Elements
    void clear(){
        while(front != NULL)
        {
            current = front;
            front = front->next;
            delete current;
            length--;
        }
        back = NULL;
    }
};
// End Class
int main(){
    Queue Qu;
    Qu.push(0);
    Qu.pop_front();
    Qu.pop_front();                 // The Queue is Empty
    Qu.push(10);
    Qu.push(20);
    Qu.push(30);
    Qu.push(40);
    Qu.Display();                   // 10 20 30 40
    cout << Qu.Front() << "\n";     // 10
    cout << Qu.Back() << "\n";      // 40
    cout << Qu.size() << "\n";      // 4
    Qu.clear();
    Qu.Display();                   // The Queue is Empty
    return 0;
}
// End Main
