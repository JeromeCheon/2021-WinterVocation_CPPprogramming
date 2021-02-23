/*  STL은 Standard Template Library의 약자로, 프로그램에 필요한 자료구조와 알고리즘을 템플릿으로 제공하는 라이브러리. 반복자라는 구성 요소를 통해 연결
    * container : 객체를 저장하는 객체로 컬랙션 또는 자료구조라고 함
    * Iterator: 포인터와 비슷한 개념으로 컨테이너의 원소를 가리키고, 가리키는 원소에 접근하여 다음 원소를 가리키게 하는 기능함
    * Algorithm : 정렬, 삭제 ,검색, 연산 등을 해결하는 일반화된 방법을 제공하는 함수 템플릿
    * Function object : 함수처럼 동작하는 객체로 operator 연산자를 오버로딩한 객체. 컨테이너와 알고리즘 등에 클라이언트의 정책 반영하게 해
    * Adaptor : 구성 요소의 인터페이스를 변경하여 새로운 인터페이스를 갖는 구성요소로 변경
    * Allocator : 컨테이너의 메모리 할당 정책을 캡슐화한 클래스 객체로 모든 컨테이너는 자신만의 기본 할당기를 가지고 있음.

-- Container
: 컨테이너는 같은 타입을 저장, 관리할 목적으로 만들어진 클래스. 기본적으로 두가지로 나뉜다.
    * Standard Sequence Container : 컨테이너 원소가 자신만의 삽입 위치(순서)를 가지는 컨테이너(vector, deque, list -> 선형적 )
    * Standard associative Container : 저장 원소가 삽입 순서와 다르게 특정 정렬 기준에 의해 자동 정렬 되는 컨테이너(set, multiset, map, multimap-> 비선형적 )
    * 잠깐, string container는 시퀀스 컨테이너의 일종이지만 문자만을 저장하는 컨테이너로 표준 컨테이너의 요구사항을 지키지 못해. 얘는 일종의 almost container. 즉 근사 컨테이너야.
        ** 배열 기반 컨테이너 : 데이터 여러개가 하나의 메모리 단위에 저장 돼 (vector, deque)
    대표적인 컨테이너가 vector. 시퀀스 컨테이너는 컨테이너 끝에 데이터를 추가하고 제거하기 위한 push_back()과 pop_back() 멤버 함수를 가진다.
    또한 배열 기반 컨테이너는 operator[] 연산자를 이용해 일반 배열처럼 컨테이너 원소에 접근할 수 있음. 모든 컨테이너는 원소의 개수를 반환하는 size() 멤버 함수를 가짐.

        ** 노드 기반 컨테이너 : 데이터 하나를 하나의 메모리 단위에 저장 (list, set, multiset, map, multimap)
-- iterator
: 반복자는 포인터와 비슷하게 동작. 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법 제공. 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할.
이 덕에 알고리즘은 특정 컨테이너에 종속되지 않고 독립적으로 언제든 컨테이너와 결합하여 동작 가능.
    * 반복자는 컨테이너 내부의 원소(객체)를 가리키고 접근할 수 있어야 함(* 연산자 제공)
    * 반복자는 다음 원소로 이동하고 컨테이너의 모든 원소를 순회할 수 있어야 함. (++, !=, == 연산자 제공)
    * STL에서 컨테이너 원소의 집합을 순차열(sequence)라고 함. 이 개념은 원소의 순서있는 집합을 의미. sequence 는 하나의 시작과 하나의 끝을 갖는다.
    * STL의 모든 컨테이너는 자신만의 반복자를 제공. begin()과 end()가 순차열의 시작과 끝을 가리키는 반복자 반환.
    * 순차열은 순서 있는 원소의 집합이므로 구간 [begin, end)뿐만 아니라 [begin, iter)와 [iter, end)도 모두 순차열.
    * *연산자로 반복자가 가리키는 순차열의 원소에 접근하여 ++ 연산자로 다음 원소로 이동한다.
        ** input iterator : 현 위치의 원소를 한번만 읽을 수 있는 반복자
        ** output iterator : 현 위치의 원소를 한번만 쓸 수 있는 반복자
        ** forward iterator : 입력, 출력 반복자 기능에 순방향으로 이동(++)이 가능한 재할당될 수 있는 반복자
        ** bidirectional iterator 순방향, 역방향 둘다 가능
        ** random access iterator : 양방향 반복자 기능에 +, -, +=, -=, [] 연산이 가능한 반복자
    * 모든 컨테이너는 양방향 반복자 이상을 제공. 배열 기반 컨테이너인 vector와 deque는 임의 접근 반복자 제공.

-- Algorithm
: STL은 순차열의 원소를 조사, 변경, 관리, 처리할 목적으로 알고리즘이라는 구성 요소를 제공. 알고리즘은 한쌍의 반복자[begin, end)를 필요로 함.
대부분 순방향 반복자를 요구하지만 몇몇 알고리즘은 임의 접근 반복자를 요구함
    * nonmodifying Algorithm 원소를 수정하지 않는 알고리즘
    * modifying algorithm 원소를 수정하는 알고리즘
    * removing algorithm : 제거 알고리즘
    * mutating algorithm : 변경 알고리즘
    * sorting algorithm 정렬 알고리즘
    * sorted range algorithm 정렬된 범위 알고리즘
    * numeric algorithm 수치형 알고리즘

-- Fucntion object
: 함수 객체는 클라이언트가 정의한 동작을 다른 구성 요소에 반영하려 할 때 사용돼. 많은 STL 알고리즘이 함수 객체, 함수, 함수 포인터 등의 함수류를 인자로 받아 알고리즘을 유연하게 동작시켜.

-- adaptor
: 구성요소의 인터페이스를 변경함. 종류로는 컨테이너 어댑터, 반복자 어댑터, 함수 어댑터가 있음
    * container adaptor : stack, queue, priority_queue
    * iterator adaptor : reverse_iterator, back_insert_iterator, front_insert_iterator, insert_iterator
    * function adaptor : binder, negator, adaptor for pointers to functions
        ** 대표적인 컨테이너 어댑터가 stack. 이는 일반 컨테이너를 LIFO 방식의 stack구조 컨테이너로 변환. empty, size, push_back, pop_back, back 인터페이스(멤버 함수)를 지원하는 컨테이너는
        모두 stack 컨테이너 어댑터를 사용하여 LIFO 방식의 스택으로 변환할 수 있음. 시퀀스 컨테이너는 모두 멤버 함수를 가지므로 stack 컨테이너 어댑터의 컨테이너로 이용할 수 있음. 디폴트는 deque.
        ** 대표적인 반복자 어댑터가 reverse_iterator. 이는 일반 반복자의 동작 방식을 반대로 동작시키는 역방향 반복자로 변환.
        ** 대표적인 함수 어댑터 : not2 이는 조건자 함수 객체(이항)를 NOT(반대) 변환.
-- Allocator
: 할당기는 컨테이너의 메모리 할당 정보와 정책(메모리 할당 모델)을 캡슐화한 STL 구성 요소임. Allocator는 템플릿 클래스이며 모든 컨테이너는 기본 할당기를 사용.
new와 delete를 사용자가 오버로딩 해서 사용할 수 있듯 STL의 할당기도 사용자가 직접 할당기를 정의하고 사용할 수 있다.

모든 컨테이너는 템플릿 매개변수에 할당기를 인자로 받는다. 기본 할당기는 allocator<T>이며 컨테이너는 템플릿 매개변수에 디폴트 매개변수 값으로 기본 할당기를 지정.
    * vector -> vector<typename T, typename Alloc = allocator<T>>
    * set -> set<typename T, typename Pred = less<T>, typename Alloc = allocator<T>>
*/
#include <iostream>
#include <vector>

using namespace std ;

int main(){
    // int type 저장하는 container v를 생성.
    vector<int> v ;
    v.push_back(10) ;
    v.push_back(20) ;
    v.push_back(30) ;
    v.push_back(40) ;
    v.push_back(50) ;
    // for (unsigned int i = 0; i < v.size(); i++) {
        // cout << v[i] << endl ;
    // }
    vector<int>::iterator iter ; // create iterator (Yet it doesn't indicate  any factors)
    for(iter = v.begin() ; iter != v.end() ; ++iter)
        cout << *iter << endl ;
    return 0 ;
}
