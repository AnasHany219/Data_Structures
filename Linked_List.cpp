#include <iostream>
using namespace std;
class Node{
public:
    int item;
    Node *next;
};
// Creating Linked List
class LinkedList{
private:
    Node *First;
    Node *Last;
    int length;
public:
// Default Constructor
    LinkedList(){
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
        if(isEmpty())
        {
            First = NewPtr;
            NewPtr->next = NULL;
            Last = NewPtr;
        }
        else{
            NewPtr->next = First;
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
            NewPtr->next = NULL;
        }
        else{
            Last->next = NewPtr;
            NewPtr->next = NULL;
            Last = NewPtr;
        }
        length++;
    }
// Add Element At Position
    void push_at(int pos, int Element){
        if(pos < 0 || pos > length)
            cout << "The Position Out of range.\n";
        else{
            Node *NewPtr = new Node;
            NewPtr->item = Element;
            if(isEmpty()){
                push_front(Element);
            }
            else if(pos == length){
                push_back(Element);
            }
            else{
                Node *current = First;
                for(int i = 0; i < pos; i++)
                    current = current->next;
                NewPtr->next = current->next;
                current->next = NewPtr;
                length++;
            }
        }
    }
// Remove First Element
    void pop_front(){
        if(isEmpty())
            cout << "The Linked List is Empty.\n";
        else if(length == 1){
            delete First;
            Last = First = NULL;
            length--;
        }
        else{
            Node *temp = First;
            First = First->next;
            temp->next = NULL;
            delete temp;
            length--;
        }
    }
// Remove Last Element
    void pop_back(){
        Node *current = First->next;
        Node *Previous = First;
        if(isEmpty())
            cout << "The Linked List is Empty.\n";
        else if(length == 1)
        {
            delete First;
            Last = First = NULL;
            length--;
        }
        else{
            while(current != Last)
            {
                Previous = current;
                current = current->next;
            }
            delete current;
            Previous->next = NULL;
            Last = Previous;
            length--;
        }
    }
// Remove an Element
    void erase(int Element){
        if(isEmpty())
            cout << "The Linked List is Empty.\n";
        Node *Previous, *current;
        if(First->item == Element)
        {
            current = First;
            First = First->next;
            delete current;
            length--;
            if(length == 0)
                Last = NULL;
        }
        else{
            current = First->next;
            Previous = First;
            while(current != NULL){
                if(current->item == Element)
                    break;
                Previous = current;
                current = current->next;
            }
            if(current == NULL)
                cout << "Element Not Found.\n";
            else{
                Previous->next = current->next;
                if(Last == current)
                    Last = Previous;
                delete current;
                length--;
            }
        }
    }
// Reverse The Element
    void reverse(){
        Node *Previous, *current, *Next;
        if(isEmpty())
                cout << "The Linked List is Empty.\n";
        else{
            Next = Previous = NULL;
            current = First;
            while(Next != NULL){            // current != NULL
                Next = current->next;
                current->next = Previous;
                Previous = current;
                current = Next;
            }
            First = Previous;
        }
    }
// Search for an element
    int Search(int Element){
        Node *current;
        int pos = 0;
        current = First;
        while(current != NULL){
            if(current->item == Element)
                return pos;
            current = current->next;
            pos++;
        }
        return -1;
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
// Printing the element from first
    void Display(){
        if(isEmpty())
            cout << "The Linked List is Empty.\n";
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
    LinkedList Li;
    Li.push_front(20);              // 20
    Li.push_back(30);               // 20 30
    Li.push_front(10);              // 10 20 30
    Li.push_back(50);               // 10 20 30 50
    cout << Li.size() << "\n";      // 4
    Li.push_at(2, 40);              // 10 20 30 40 50
    Li.Display();                   // 10 20 30 40 50
    Li.push_at(2, 40);              // 10 20 30 40 40 50
    Li.Display();                   // 10 20 30 40 40 50
    Li.erase(40);                   // 10 20 30 40 50
    Li.Display();                   // 10 20 30 40 50
    Li.push_back(50);               // 10 20 30 40 50 50
    Li.push_front(10);              // 10 10 20 30 40 50 50
    Li.Display();                   // 10 10 20 30 40 50 50
    Li.pop_front();                 // 10 20 30 40 50 50
    Li.Display();                   // 10 20 30 40 50 50
    Li.pop_back();                  // 10 20 30 40 50
    Li.Display();                   // 10 20 30 40 50
    cout << Li.Search(40) << "\n";  // 3
    cout << Li.front() << "\n";     // 10
    cout << Li.back() << "\n";      // 50
    cout << Li.size() << "\n";      // 5
    Li.clear();
    Li.Display();                   // The Linked List is Empty.
    cout << Li.size() << "\n";      // 0
    return 0;
}
// End Main
