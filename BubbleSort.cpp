#include <iostream>
using namespace std;
// Swap Function For the Min element in array
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
// Sort Function
void BubbleSort(int arr[], int size){
    bool flag = true;                   // for check the arr is sorted or not.
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = false;
            }
        }
        if(flag == true)
            break;
    }
}
// Display The Element
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// Main Function
int main(){
    int arr[] = {100, 60, 20, 50, 30, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before bubble sort: ";
    print(arr, n);          // The array before bubble sort: 60 40 50 30 10 20
    BubbleSort(arr, n);
    cout << "\nThe array after bubble sort: ";
    print(arr, n);          // The array after bubble sort: 10 20 30 40 50 60
    return 0;
}
// End The main
// | | | | | 100 60 20 10 30 90 | if(100 > 60)? swap    | pass 1
// | | | | 60 | 100 20 10 30 90 | if(100 > 20)? swap    | pass 1
// | | | | 60 20 | 100 10 30 90 | if(100 > 10)? swap    | pass 1
// | | | | 60 20 10 | 100 30 90 | if(100 > 30)? swap    | pass 1
// | | | | 60 20 10 30 | 100 90 | if(100 > 90)? swap    | pass 1
// | | | | 60 20 10 30 90 | 100 | pass 1

// | | | | 60 20 10 30 90 | 100 | if(60 > 20)? swap     | pass 2
// | | | 20 | 60 10 30 90 | 100 | if(60 > 10)? swap     | pass 2
// | | | 20 10 | 60 30 90 | 100 | if(60 > 30)? swap     | pass 2
// | | | 20 10 30 | 60 90 | 100 | if(60 > 90)? noswap   | pass 2
// | | | 20 10 30 60 | 90 | 100 | pass 2

// | | | 20 10 30 60 | 90 | 100 | if(20 > 10)? swap     | pass 3
// | | 10 | 20 30 60 | 90 | 100 | if(20 > 30)? noswap   | pass 3
// | | 10 20 | 30 60 | 90 | 100 | if(30 > 30)? noswap   | pass 3
// | | 10 20 30 | 60 | 90 | 100 | pass 3

// | | 10 20 30 | 60 | 90 | 100 | if(10 > 20)? noswap   | pass 4
// | 10 | 20 30 | 60 | 90 | 100 | if(20 > 20)? noswap   | pass 4
// | 10 20 | 30 | 60 | 90 | 100 | pass 4

// | 10 20 | 30 | 60 | 90 | 100 | if(10 > 20)? noswap   | pass 5
// 10 | 20 | 30 | 60 | 90 | 100 | pass 5
