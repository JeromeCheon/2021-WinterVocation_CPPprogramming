// 모의고사 2- 1번 청백전 문제.
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;
/*
    1. 청팀과 백팀 구분 없이 N명의 사람이 일렬로 줄을 선다.
    2. 1번 사람부터 차례로 탈락할 사람을 지정
    3. 탈락한 사람을 지정한 사람은 줄의 맨 뒤로 이동하며, 탈락자는 게임에서 즉시 제외
    4. 한 팀이 팀원이 모두 제외될 떄까지 게임 반복.

    output : 백팀이 승리하면 0, 청팀이 승리하면 1

*/
long num ;
// char people[1000010] ;
string arr ;
bool flag = false ;
/*
bool game(void){
    // 일단 만약 3명이 들어왔는데 BWB이다. XBB -> BB | BWW이면 -> XWB -> WB-> WX -> W
    char starter ;
    for(int i=0; i< arr.length(); i++){
        int tmp = 0;
        starter = arr[i] ;
        if (starter == 'X') { // 탈락 됐으면 선택권 없으니 continue해서 차례를 마쳐야.
            tmp = arr.erase(i) ;
            // continue ;
        }
        else{ // 탈락자가 아닐 때만 실행해줘야지.
            for(int j = i+1; j<arr.length() ; j++){
                if(starter != arr.at(j) && arr.at(j) != 'X'){
                     // 첫 번째주자랑 다른 팀을 만나면 탈락 시켜줘야.
                     arr.at(j) = 'X' ;
                     arr.append(starter) ;
                     tmp = arr.erase(arr.begin()) ;
                     break ;

                }
            }
        }
    }
    if (arr.at(0) == 'B') {
        return 0 ;
    }
    else
        return true ;

}
*/
// 큐를 이용해야 할 것 같은데.. .
int main(){
    // memset(people, 0, sizeof(people)) ;
    cin >> num ;
    cin >> arr ;
    // seq.push_back(people) ;
    //cout << game() << endl ;
    return 0;
}
