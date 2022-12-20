#include <iostream>
using namespace std;
// Swap Function For the Min element in array
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
// Sort Function
void SelectionSort(int arr[], int size){
    int Min_Index;
    for(int i = 0; i < size-1; i++){
        Min_Index = i;
        for(int j = i+1; j < size; j++){
            if(arr[Min_Index] > arr[j]){
                Min_Index = j;
            }
        }
        swap(arr[Min_Index], arr[i]);
    }
}
// Display The Element
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// Main Function
int main(){
    int arr[] = {60, 40, 50, 30, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The array before selection sort: ";
    print(arr, n);          // The array before selection sort: 60 40 50 30 10 20
    SelectionSort(arr, n);
    cout << "\nThe array after selection sort: ";
    print(arr, n);          // The array after selection sort: 10 20 30 40 50 60
    return 0;
}
// End The main
// 60 40 50 30 10 20    | min element = 10  | swap(60, 10)
// 10 | 40 50 30 60 20  | min element = 20  | swap(40, 20)
// 10 20 | 50 30 60 40  | min element = 30  | swap(50, 30)
// 10 20 30 | 50 60 40  | min element = 40  | swap(50, 40)
// 10 20 30 40 | 60 50  | min element = 50  | swap(60, 50)
// 10 20 30 40 50 | 60  -> Sorted
