#include <iostream>
using namespace std ;

template<typename dstT, typename srcT>
void Copy(dstT* ar1, srcT* ar2, int num){
    // ar1 = new dstT[num] ;
    for(int i=0; i < num ; i++){
        ar1[i] = (dstT)ar2[i] ;
        // cout << ar1[i] << ar2[i] ;
    }
}

int main(){
    int arr1[5] = {10, 20, 30, 40 , 50} ;
    int arr2[5] ;
    Copy(arr2, arr1, 5) ;
    for (size_t i = 0; i < 5; i++) {
        cout << arr2[i] << " " ;
    }
    cout << endl ;
    return 0;
}
