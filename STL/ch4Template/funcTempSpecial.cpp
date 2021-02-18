#include <iostream>
using namespace std ;

template<typename T1, int size>
void PrintArray(T1* arr){
    for(int i=0; i< size; i++){
        cout << arr[i] << ", " << endl ;
    }
    cout << endl ;
}

int main(){
    int arr1[5] = {10, 20, 30, 40, 50} ;
    double arr2[3] = {.1, 1.1, 2.2} ;
    PrintArray<int, 5>(arr1) ;
    PrintArray<double, 3>(arr2) ;

    return 0;
}
