#include <iostream>
using namespace std;
const int MAX_SIZE = 1000;
// Creating Circular Queue "FIFO"
class Queue{
private:
    int front;              // For first element
    int back;               // For last element
    int count;              // Check if queue is full or empty!
    int items[MAX_SIZE];
public:
// Default Constructor
    Queue(){
        front = count = 0;
        back = MAX_SIZE-1;
    }
// Add Elements
    void push(int element){
        if(count == MAX_SIZE)
            cout << "The Queue is full\n";
        else{
            back = (back + 1) % MAX_SIZE;   // 999+1 % 1000 = 0 -> first index
            items[back] = element;
            count++;
        }
    }
// Remove First Element
    void pop(){
        if(count == 0)
            cout << "The Queue is Empty\n";
        else{
            front = (front + 1) % MAX_SIZE; // 0+1 % 1000 = 1 -> next index -> ignore previous element
            count--;
        }
    }
// Printing the element from first
    void Display(){
        for(int i = front; i != back+1; i)
        {
            cout << items[i] << " ";
            i = (i + 1) % MAX_SIZE;         // 0+1 % 1000 = 1 -> next index
        }
        cout << "\n";
    }
};
// End Class
int main(){
    Queue Qu;
    Qu.push(0);
    Qu.pop();
    Qu.pop();       // The Queue is Empty
    Qu.push(10);
    Qu.push(20);
    Qu.push(30);
    Qu.push(40);
    Qu.Display();   // 10 20 30 40
    return 0;
}
// End Main
