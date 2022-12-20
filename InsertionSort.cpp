#include <iostream>
using namespace std;
// Swap Function For the Min element in array
void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
// Sort Function
void InsertionSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
// Display The Element
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// Main Function
int main(){
    int arr[] = {80, 90, 60, 30, 50, 70, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before insertion sort: ";
    print(arr, n);          // The array before insertion sort: 60 40 50 30 10 20
    InsertionSort(arr, n);
    cout << "\nThe array after insertion sort: ";
    print(arr, n);          // The array after insertion sort: 10 20 30 40 50 60
    return 0;
}
// End The main
// 80 | 90 60 30 50 70 40   | 90 > 80
// 80 90 | 60 30 50 70 40   | 60 < 80
// 60 80 90 | 30 50 70 40   | 60 < 80
// 30 60 80 90 | 50 70 40   | 30 < 60
// 30 60 80 90 | 50 70 40   | 30 < 50 < 60
// 30 50 60 80 90 | 70 40   | 60 < 70 < 80
// 30 50 60 70 80 90 | 40   | 30 < 40 < 60
// 30 40 50 60 70 80 90     -> Sorted
