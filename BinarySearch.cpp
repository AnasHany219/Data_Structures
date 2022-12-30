#include<iostream>
using namespace std;

// Binary Search deals with sorted array
int BinarySearch(int arr[], int left, int right, int key){

    while(left <= right){
        int m = (left + right) / 2;
        if(arr[m] == key)
            return m;
        if(arr[m] > key)
            right = m - 1;
        else
            left = m + 1;
    }
    return -1;
}
int main(){
    //           0  1   2   3   4   5   6   7   8   9  10  11  12  13  14
    int arr[] = {1, 6, 10, 15, 18, 22, 31, 40, 55, 60, 80, 90, 95, 97, 99};
    int n = sizeof(arr) / sizeof(arr[0]); // n = 60 / 4 = 15

    int num;
    cout << "Enter The number: "; cin >> num;

    int result = BinarySearch(arr, 0, n-1, num);
    if(result == -1)
        cout << "Not Found!\n";
    else
        cout << "The number in Index: " << result;
    /*
    --------Output---------
    Enter The number: 10
    The number in Index: 2
    -----------------------
    Enter The number: 20
    Not Found!
    -----------------------
    Enter The number: 30
    Not Found!
    -----------------------
    Enter The number: 40
    The number in Index: 7
    */
    return 0;
}
/*
             7
        /         \
      3             11
    /   \         /    \
  1      5      9        13
 / \    / \    / \       / \     
0   2  4   6  8   10   12   14
*/
