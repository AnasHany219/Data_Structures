#include <iostream>
using namespace std;

void Marge(int arr[], const int l, const int m, const int r){
    int i, j, k;
    const int size_arr1 = m - l + 1;  // size of first subarray [l, ..., m]
    const int size_arr2 = r - m;      // size of second subarray [m+1, ..., r]
    int *L_arr = new int[size_arr1];
    int *R_arr = new int[size_arr2];

    for(i = 0; i < size_arr1; i++)
        L_arr[i] = arr[l + i];
    for(j = 0; j < size_arr2; j++)
        R_arr[j] = arr[m+1 + j];

    i = 0;  // i for first index in first subarray
    j = 0;  // i for first index in second subarray
    k = l;  // i for first index in array
    while(i < size_arr1 && j < size_arr2){
        if(L_arr[i] <= R_arr[j]){
            arr[k] = L_arr[i];
            i++;
        }
        else{
            arr[k] = R_arr[j];
            j++;
        }
        k++;
    }
    while(i < size_arr1){
        arr[k] = L_arr[i];
        i++, k++;
    }
    while(j < size_arr2){
        arr[k] = R_arr[j];
        j++, k++;
    }
}
// Sort Function
void MargeSort(int arr[], int begin, int end){
    if(begin < end){
        int mid = begin + (end - begin) / 2;
        MargeSort(arr, begin, mid);
        MargeSort(arr, mid + 1, begin);
        Marge(arr, begin, mid, end);
    }
}
// Display The Element
void print(int arr[], int size){
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// Main Function
int main(){
    int arr[] = {30, 20, 40, 5, 90, 80, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The array before marge sort: ";
    print(arr, n);          // The array before marge sort: 30 20 40 5 90 80 10
    MargeSort(arr, 0, n-1);
    cout << "\nThe array after marge sort: ";
    print(arr, n);          // The array after marge sort: 5 10 20 30 40 80 90
    return 0;
}
// End The main
