#pragma once
#include "searchHistory.h"

typedef CSearchHistory ListElementType;	  //1번, list 클래스에서 elem을 CSearchHistory를 사용하도록 수정
// Characteristic : 
// inorder List로 구현이 되어 ListElementType의 데이터 형을 저장할 수 있다.

class List
{
public:
	List();
	~List();

	void insert(const ListElementType & elem);
	// Preconditions : None
	// Postconditions : 노드를 inorder linked list로 저장
	// Returns : None
	bool first(ListElementType & elem);
	// Preconditions : None
	// Postconditions : current가 head를 가리키고 있으면 지나가고, head가 아닌 Node를 가리키고 있으면 head를 가리키게 한다.
	// Returns : current가 head를 가리키고 있는경우 false, 나머지는 true
	bool next(ListElementType & elem); 
	// Preconditions : 최소 1번은 first를 호출했어야 한다.
	// Postconditions : current가 tail을 가리키고 있으면 지나가고, tail이 아닌 Node를 가리키고 있으면 tail을 가리키게 한다.
	// Returns : current가 tail을 가리키고 있는 경우 false, 나머지는 true
	bool Current(ListElementType & elem);
	// Preconditions :  최소 1번은 first를 호출했어야 한다.
	// Postconditions : 현재노드를 가리킴
	// Returns : 처음에 노드가 없으면 false, 있으면 true
	bool last(ListElementType & elem);
	// Preconditions :  최소 1번은 first를 호출했어야 한다.
	// Postconditions : 마지막 노드를 카리킴
	// Returns : 처음에 노드가 없으면 false, 있으면 true

private:
	struct Node; // declaration without definition
	typedef Node *Link;
	struct Node {
		ListElementType elem;
		Link next;
		Link prev;
	};
	Link head;
	Link current;
	Link tail;		// 2번. tail포인터 추가
	int nTopIndex; // 5번. Stack에 남은 Node수를 계산할 때 사용할 nTopIndex
																				
public:
	void printLists();		//1.	리스트출력
	// Preconditions : 노드가 한개 이상
	// Postconditions : first노드부터 뒤에 더 이상 값이 없을때까지 출력
	// Returns : None
	void printLast();			//2.마지막 노드 출력
	// Preconditions : 적어도 노드가 한개 이상
	// Postconditions : 현재 노드의 값을 가리킨다
	// Returns : None
	bool findOut(const string& word);    //3.같은 검색어를 가진 노드 찾기
	// Preconditions : 1개 이상의 노드가 존재
	// Postconditions : 같은 검색어를 가진 노드의 SearchHistory 모두 출력
	// Returns : 성공하면 true, 실패하면 false
	bool deleteByKeyword(const string& word2);		 //4. keyword검색어가 같은거 지우는 함수
	// Precondition : List에 최소 1개의 노드가 존재해야 한다.
	// Postcondition : List의 검색어들을 비교해서 같은 검색어을 갖는 노드 delete. 나머지 리스트 출력
	// Return : 같은 검색어를 가진 노드 delete 성공하면 true, 실패하면 false
	void addOneList(ListElementType newone);		  // 5. 하나의 검색 히스토리 추가
	// Preconditions : 추가할 검색어 히스토리 전달인자로 받아옴
	// Postconditions : 검색어 하나가 빈도수순 정렬에 맞게 리스트에 추가됨 전체 리스트 출력
	// Returns : None
	void AddAll(List& CAdd, List& CStack);			 // 6. 다른 리스트 추가로 더하기
	// Preconditions : 이미 있던 inorder list CStack과 새로 입력받은 inorder list CAdd를 전달인자로 받음
	// Postconditions : 모든 히스토리가 빈도수순에 맞게 정렬되여 출력
	// Returns : None
	void FindAndShowImage(const string& word3);		 // 7. 같은 검색어를 같은 노드 찾고 사진을 출력
	// Preconditions : 검색어 keyword를 전달인자롤 받는다
	// Postconditions : 찾고싶은 검색노드와 함꼐 사진이 출력된다.
	// Returns : None
	void Push(ListElementType elem);			// 4. Push함수 추가
	// Preconditions : None
	// Postconditions : Stack 없으면 새로운 Node를 만들어서 값을 넣고, 순서에 맞춰 list에 추가한다.
	// Returns : None
	ListElementType Pop();		// 4. Pop함수 추가
	// Preconditions : Stack에 최소 1개의 Node가 존재해야 한다.
	// Postconditions : Stack의 가장 최근에 넣어진 값을 뽑아온다. 뽑아낸 후 값이 더이상 존재하지 않으면 "더이상 존재하지 않음"을 표시
	// Returns : 가장 최근에 넣어진 Node의 elem
	bool IsEmpty();
	// Preconditions : Stack에 있던 마지막 1개의 Node가 없어져야 한다.
	// Postconditions : Stack에 남아있는 Node가 더이상 없으면 false를 리턴하게 된다.
	// Returns : Stack에 더이상 값이 없으면 true, 있으면 false
	int FindByPicture(const string&);					// 8.얼굴이 있는 사진을 찾는다
	// Preconditions : CSearchHistory.m_Pic안에 사진경로가 들어있어야한다. 사진에 사람얼굴이 있다.
	// Postconditions : 알맞은 사진경로의 경우 사진이 출력되며 얼굴부분에 초록색 네모박스가 생긴다.
	// Returns : 성공한 경우 return 0. 실패하면 에러 메세지를 출력한다.

};
