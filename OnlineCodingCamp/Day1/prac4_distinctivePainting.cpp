#include <iostream>

using namespace std ;

typedef node{
    int id ;
    int col ;
    Node* next ;
    Node* prev ;
}Node;

void connect(Node* nd1, Node* nd2){
    // nd1->next =

}

int main(){
    int num = 0;
    int color = 0 ;
    int conn1 = 0, conn2 = 0 ;

    cin >> num >> color ;
    Node *place = new Node[num] ; // num 만큼 집을 만들기. 
    int *cost = new int[num]() ;
    for (int i = 0; i < color; i++) {
        cin >> cost[i] ;
    }
    for (int i = 0; i < num; i++) {
        cin >> conn1 >> conn2 ;
        connect(&place[conn1], &place[conn2]) ;
    }
    // 자 이제 색상 개수와 각 색상별 비용을 얻어서 저장했으니 이를 다뤄보자. 이걸... 구조체를 만들어서 링크드리스트를 써야 할 것 같은데...
    delete[] cost ;
    delete[] place ;
    return 0 ;
}
