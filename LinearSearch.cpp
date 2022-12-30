#include<iostream>
using namespace std;

int LinearSearch(int arr[], int size, int key){
    for(int i = 0; i < size; i++){
        if(key == arr[i])
            return i;
    }
    return -1;      //
}

int main(){
    int arr[] = {90, 10, 40, 70, 5};
    int n = sizeof(arr) / sizeof(arr[0]); // n = 20 / 4 = 5

    int num;
    cout << "Enter The number: "; cin >> num;

    int result = LinearSearch(arr, n, num);
    if(result == -1)
        cout << "Not Found!\n";
    else
        cout << "The number in Index: " << result;
    /*
    --------Output---------
    Enter The number: 10
    The number in Index: 1
    -----------------------
    Enter The number: 20
    Not Found!
    -----------------------
    Enter The number: 30
    Not Found!
    -----------------------
    Enter The number: 40
    The number in Index: 2
    */
    return 0;
}
