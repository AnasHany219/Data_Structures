#include <iostream>
using namespace std;
class Node{
public:
    int item;
    Node *next;
    Node *prev;
};
// Creating Linked List
class Doubly_LinkedList{
private:
    Node *First;
    Node *Last;
    int length;
public:
// Default Constructor
    Doubly_LinkedList(){
        First = Last = NULL;
        length = 0;
    }
// Check empty queue
    bool isEmpty(){
        return length == 0;
    }
// Add Element in first
    void push_front(int Element){
        Node *NewPtr = new Node;
        NewPtr->item = Element;
        if(isEmpty()){
            First = Last = NewPtr;
            NewPtr->next = NewPtr->prev = NULL;
        }
        else{
            NewPtr->next = First;
            NewPtr->prev = NULL;
            First->prev = NewPtr;
            First = NewPtr;
        }
        length++;
    }
// Add Element in Last
    void push_back(int Element){
        Node *NewPtr = new Node;
        NewPtr->item = Element;
        if(isEmpty()){
            First = Last = NewPtr;
            NewPtr->next = NewPtr->prev = NULL;
        }
        else{
            NewPtr->next = NULL;
            NewPtr->prev = Last;
            Last->next = NewPtr;
            Last = NewPtr;
        }
        length++;
    }
// Add Element At Position
    void push_at(int pos, int Element){
        if(pos < 0 || pos > length)
            cout << "Out of range.\n";
        else{
            Node *current = First;
            Node *NewPtr = new Node;
            NewPtr->item = Element;
            if(pos == 0)
                push_front(Element);
            else if(pos == length)
                push_back(Element);
            else{
                for(int i = 1; i < pos; i++)
                    current = current->next;
                NewPtr->next = current->next;
                NewPtr->prev = current;
                current->next->prev = NewPtr;
                current->next = NewPtr;
                length++;
            }
        }
    }
// Remove First Element
    void pop_front(){
        if(isEmpty())
            cout << "The Doubly Linked List is empty.\n";
        else if(length == 1)
        {
            delete First;
            First = Last = NULL;
            length--;
        }
        else{
            Node *temp = First;
            First = First->next;
            First->prev = NULL;
            delete temp;
            length--;
        }

    }
// Remove Last Element
    void pop_back(){
        if(isEmpty())
            cout << "The Doubly Linked List is empty.\n";
        else if(length == 1)
        {
            delete Last;
            Last = First = NULL;
            length--;
        }
        else{
            Node *temp = Last;
            Last = Last->prev;
            Last->next = NULL;
            delete temp;
            length--;
        }
    }
// Remove an Element
    void erase(int Element){
        if(isEmpty())
            cout << "The Doubly Linked List is empty.\n";
        if(First->item == Element)
            pop_front();
        else{
            Node *current = First->next;
            while(current != NULL){
                if(current->item == Element)
                    break;
                current = current->next;
            }
            if(current == NULL)
                cout << "Element Not Found.\n";
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                length--;
            }
        }
    }
// Return First ELement
    int front(){
        return First->item;
    }
// Return Last ELement
    int back(){
        return Last->item;
    }
// Return Number of elements
    int size(){
        return length;
    }
// Printing the element from first to last
    void Display(){
        if(isEmpty())
            cout << "The Doubly Linked List is empty.\n";
        else{
            Node *current = First;
            while(current != NULL)
            {
                cout << current->item << " ";
                current = current->next;
            }
            cout << "\n";
        }
    }
// Printing the element from last to first
    void Display_reverse(){
        if(isEmpty())
            cout << "The Doubly Linked List is empty.\n";
        else{
            Node *current = Last;
            while(current != NULL)
            {
                cout << current->item << " ";
                current = current->prev;
            }
            cout << "\n";
        }
    }
// Remove All Elements
    void clear(){
        while(First != NULL)
        {
            Node *current = First;
            First = First->next;
            delete current;
        }
        length = 0;
        Last = NULL;
    }
};
// End Class
int main(){
    Doubly_LinkedList Dl;
    Dl.push_front(20);          // 20
    Dl.push_front(10);          // 10 20
    Dl.push_front(10);          // 10 10 20
    Dl.push_back(40);           // 10 10 20 40
    Dl.push_back(50);           // 10 10 20 40 50
    Dl.push_back(50);           // 10 10 20 40 50 50
    Dl.push_at(3, 30);          // 10 10 20 30 40 50 50
    Dl.push_at(3, 30);          // 10 10 20 30 30 40 50 50
    Dl.Display();               // 10 10 20 30 30 40 50 50
    Dl.pop_front();             // 10 20 30 30 40 50 50
    Dl.pop_back();              // 10 20 30 30 40 50
    Dl.erase(30);               // 10 20 30 40 50
    cout << Dl.size() << "\n";  // 5
    Dl.Display();               // 10 20 30 40 50
    Dl.Display_reverse();       // 50 40 30 20 10
    Dl.clear();                 //
    Dl.Display();               // The Doubly Linked List is empty.
    return 0;
}
// End Main
