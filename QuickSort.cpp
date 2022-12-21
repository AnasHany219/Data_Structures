#include <iostream>
using namespace std;

void swap(int &x, int &y){
    int temp = x;
    x = y;
    y = temp;
}
int partition(int arr[], int begin, int end){
    int i = begin;      // for index to the first sub array
    int j = end;        // for index to the second sub array
    int pivot = i;      // for index pivot
    while(true){
        while(arr[pivot] <= arr[j] && pivot != j)
            j--;
        if(pivot == j)
            break;
        else if(arr[pivot] > arr[j]){
            swap(arr[pivot], arr[j]);
            pivot = j;
        }
        while(arr[pivot] >= arr[i] && pivot != i)
            i++;
        if(pivot == i)
            break;
        else if(arr[pivot] < arr[i]){
            swap(arr[pivot], arr[i]);
            pivot = i;
        }
    }
    return pivot;
}
// Sort Function
void QuickSort(int arr[], int begin, int end){
    if(begin < end){
        int piv = partition(arr, begin, end);
        QuickSort(arr, begin, piv-1);
        QuickSort(arr, piv+1, end);
    }
}
// Display The Element
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// Main Function
int main(){
    int arr[] = {50, 20, 60, 10, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before quick sort: ";
    print(arr, n);          // The array before quick sort: 50 20 60 10 30 40
    QuickSort(arr, 0, n-1);
    cout << "\nThe array after quick sort: ";
    print(arr, n);          // The array after quick sort: 10 20 30 40 50 60
    return 0;
}
// End The main
