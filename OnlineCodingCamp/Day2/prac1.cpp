// 모의고사 2- 1번 청백전 문제.
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
/*
    1. 청팀과 백팀 구분 없이 N명의 사람이 일렬로 줄을 선다.
    2. 1번 사람부터 차례로 탈락할 사람을 지정
    3. 탈락한 사람을 지정한 사람은 줄의 맨 뒤로 이동하며, 탈락자는 게임에서 즉시 제외
    4. 한 팀이 팀원이 모두 제외될 떄까지 게임 반복.

    output : 백팀이 승리하면 0, 청팀이 승리하면 1
    ****** 해설지 ********
    이 문제는 상대 팀원 중 탈락할 사람을 어떤 순서로 선택을 해야 같은 팀이 이기는데 가장 최적이 될 수 있을지 고민해야.
    상대 팀원의 수가 k라고 했을 때 선택할 수 있는 방법 수는 총 k가지 이지만, 이를 좀더 단순화 하면 아래 세개로 압축할 수 있다.
    1. 맨 뒤에 있는 상대 팀원    2. 중간에 있는 상대 팀원        3. 맨 앞에 있는 상대 팀      여기서 답은 3. 맨 앞에 있는 상대를 끌어내리는게 좋아.
    자 그렇다면 어떤 알고리즘이 좋을까? 큐를 많이 떠올렸을 거다. 그런데 큐 하나만 쓰면 관리하기 어려우니 청팀 백팀 구분하여 두개의큐를 이용하자
    또한 큐에는 해당 팀원이 몇번째 순서에 있는지 기록해야 한다.
    한편, 이런 경우가 생길 수도 있다.
    청팀 : 6  7   8   9
    백팀 : 5
    이 때는 청팀이 패배한다는 결과가 도출될 수도 있기 때문에 이러한 상황을 피하려면 맨 앞에 있는 팀원들이 서로 값을 비교한 뒤, 줄의 맨 뒤로 이동하는 팀원에 대해 일정한 수를 더해줘야.
    어떠한 수와도 겹치지 않고 비교 작업에도 문제가 없으려면 현재 남아있는 사람 수만큼을 더해 줄 수 있겠지만 단순히 N을 더해줘도 해결 가능

*/
/*
long num ;
// char people[1000010] ;
string arr ;
bool flag = false ;

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

// 큐를 이용해야 할 것 같은데.. .
int main(){
    // memset(people, 0, sizeof(people)) ;
    cin >> num ;
    cin >> arr ;
    // seq.push_back(people) ;
    //cout << game() << endl ;
    return 0;
}*/
// 모범답안 ->  이렇게 간단할 수 있다니...
int main(){
    int num ;
    cin >> num ;
    queue<int> white, blue ;
    for (size_t i = 0; i < num; i++) {
        char starter ;
        cin >> starter ;    // 여기서 또 중요한건, 문자열 처럼 입력이 들어온다고 해도 이렇게 문자를 반복해서 받아도돼.
        if (starter == 'W') {
            white.push(i) ;
        }
        else
            blue.push(i) ;
    }
    while (white.size() && blue.size()) { // 와 이렇게도 표현이 가능하구나. 즉 둘 중 하나라도 0이 되면 while문이 멈추는 거야.
        int num1 = white.front();
        white.pop() ;
        int num2 = blue.front() ;
        blue.pop() ;
        if (num1 > num2) { // white가 더 크면
            blue.push(num2+num) ;
        }
        else
            white.push(num1+num) ;
    }
    if(white.size())   // 백팀의 큐가 아직 남아있을 때
        cout << "0" <<endl ;
    else
        cout << "1" << endl ;
}
