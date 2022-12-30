#include<iostream>
using namespace std;

// Swap Function
void swap(int *x, int *y){
    int *temp = x;
    x = y;
    y = temp;
}
// Heapify function to exchange between parent and older child as "max heap"
void Heapify(int arr[], int n, int i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maximum = i;
    if(left < n && arr[left] > arr[maximum])
        maximum = left;
    if(right < n && arr[right] > arr[maximum])
        maximum = right;
    if(maximum != i){
        swap(arr[i], arr[maximum]);
        Heapify(arr, n, maximum);
    }
}
// Build function for heapify all elements of the array
void BuildHeap(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        Heapify(arr, n, i);
    }
}
// Heap sort Function
void HeapSort(int arr[], int n){
    BuildHeap(arr, n);
    for(int i = n-1; i >= 0; i--){
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}
// Display elements of the array
void print(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main(){
    int arr[] = {90, 10, 40, 70, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // n = 20 / 4 = 5

    print(arr, n);          // 90 10 40 70 5

    HeapSort(arr, n);

    print(arr, n);          // 5 10 40 70 90
    return 0;
}
