#include "List.h"
#include <assert.h>
#include <iostream>

using namespace std;

List::List()
{
	head = 0;
	tail = 0;
	current = 0;
}
List::~List()
{

	while (head != 0) {
		Link delNode = head;
		head = head->next;
		delete delNode;
	}
}
void List::insert(const ListElementType & elem)
{
	// precondition: list is in order
	Link addedNode(new Node);
	assert(addedNode);
	addedNode->elem = elem;
	// Special case: if the existing list is empty, or if the new data
	// is less than the smallest item in the list, the new node is added
	// to the front of the list
	if (head == 0 || elem.m_freq <= head->elem.m_freq) {
		addedNode->next = head;
		head = addedNode;
	}
	else {
		// find the pointer to the node that is the predecessor
		// to the new node in the in-order list
		Link pred(head);
		// assertion: pred->elem <= addedNode->elem
		while (pred->next != 0 && pred->next->elem.m_freq <= addedNode->elem.m_freq)
			// loop invariant: pred->next != 0 && pred->next->elem <= elem
		{
			pred = pred->next;
		}
		// assertion 7-1: (pred->elem <= addedNode->elem) &&
		//    (addedNode->elem <= pred->next->elem || pred->next == 0)
		addedNode->next = pred->next;
		pred->next = addedNode;
		if (addedNode->next == 0) tail = addedNode;		//tail pointer 추가 마지막 노드를 가리킴
	
	}
	// postcondition: list is in order, with elem added in proper position
}

bool List::first(ListElementType & elem)
{
	// After calling first, current points to first item in list
	if (head == 0)
		return false;
	else {
		elem = head->elem;
		current = head;
		return true;
	}
}
bool List::next(ListElementType & elem)
{
	// with proper use, current should always be nonzero
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0)
		return false;
	else {
		current = current->next;
		elem = current->elem;
		return true;
	}
}
bool List::Current(ListElementType & elem)
{
	// with proper use, current should always be nonzero
	assert(current);

	// After each call, current always points to the item
	// that next has just returned.
	if (current->next == 0)
		return false;
	else {
		elem = current->elem;
		return true;
	}
}
bool List::last(ListElementType & elem)      // 2. last 함수 추가
{
	if (tail == 0)
		return false;
	else {
		elem = tail->elem;
		current = tail;
		return true;
	}

}

void List::printLists()				// 1. inorder list 결과출력함수
{
	CSearchHistory CList;
	bool bNotEmpty(first(CList));
	while (bNotEmpty)
	{
		cout << CList.GetWord() << endl;
		cout << CList.GetWebsite() << endl;
		cout << CList.GetInWeb() << endl;
		cout << CList.GetTime() << endl;
		cout << "검색횟수: " << CList.GetFreq() << endl;
		cout << endl;
		bNotEmpty = next(CList);
	}
	return ;
}

void List::printLast()				// 2. last불러서 마지막원소 출력하는 함수
{
	CSearchHistory CList;
	bool bNotEmpty(last(CList));		// 2. last 함수 부름
	while (bNotEmpty)
	{
		cout << CList.GetWord() << endl;
		cout << CList.GetWebsite() << endl;
		cout << CList.GetInWeb() << endl;
		cout << CList.GetTime() << endl;
		cout << "검색횟수: " << CList.GetFreq() << endl;
		cout << endl;
		bNotEmpty = next(CList);
	}
	return;
}

void List::Push(ListElementType elem) {										// 4. Push함수
	Link addedNode = new Node;
	assert(addedNode);

	++nTopIndex;															// 데이터의 수 증가
	addedNode->elem = elem;
	if (head == 0 || elem.m_freq <= head->elem.m_freq) {
		addedNode->next = head;
		head = addedNode;
	}
	else {
		// find the pointer to the node that is the predecessor
		// to the new node in the in-order list
		Link pred(head);
		// assertion: pred->elem <= addedNode->elem
		while (pred->next != 0 && pred->next->elem.m_freq <= addedNode->elem.m_freq)
			// loop invariant: pred->next != 0 && pred->next->elem <= elem
		{
			pred = pred->next;
		}
		// assertion 7-1: (pred->elem <= addedNode->elem) &&
		//    (addedNode->elem <= pred->next->elem || pred->next == 0)
		addedNode->next = pred->next;
		pred->next = addedNode;
	}
}

ListElementType List::Pop() {												// 4. Pop함수 : 가장 최근데 들어온 Node가 빠져나감
	//assert(nTopIndex >= 0);
	--nTopIndex;															// 데이터의 수 감소
	Link pDelNode = new Node();
	pDelNode = head;
	head = pDelNode->next;
	current = head;
	CSearchHistory CSearchHistory;
	CSearchHistory = pDelNode->elem;
	delete pDelNode;
	if (IsEmpty() == true) {
		cout << "Stack에 더 이상 값이 남아있지 않습니다." << endl;			// 4. isEmpty를 사용해서 만일 stack의 마지막 값이 pop될 경우 이를 알려준다.
	}
	return CSearchHistory;
}


bool List::IsEmpty()	// 4. -1로 초기화 되어 있다가 Push, Pop할 때마다 nTopIndex가 증가, 감소하고
{					// 이 값이 다시 -1이 되면 데이터가 더이상 존재하지 않음
	return bool(nTopIndex == -1);
}

int List::FindByPicture(const string& word3)			// 8.
{
	ListElementType CList;
	assert(head);
	for (current = head; current->next != 0; current = current->next) {	// 같은 검색어를 찾으면 break하고 current는 그자리에서 멈춰있다.
		if (current->elem.GetWord() == word3) {
			bool bNotEmpty(Current(CList));
			while (bNotEmpty)
			{
				CList.FindPicture();
				cout << CList.GetWord() << endl;
				bNotEmpty = 0;
			}
			return true;
		}
	}
	return false;
}



