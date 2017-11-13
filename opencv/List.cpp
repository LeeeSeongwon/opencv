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
		if (addedNode->next == 0) tail = addedNode;		//tail pointer �߰� ������ ��带 ����Ŵ
	
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
bool List::last(ListElementType & elem)      // 2. last �Լ� �߰�
{
	if (tail == 0)
		return false;
	else {
		elem = tail->elem;
		current = tail;
		return true;
	}

}

void List::printLists()				// 1. inorder list �������Լ�
{
	CSearchHistory CList;
	bool bNotEmpty(first(CList));
	while (bNotEmpty)
	{
		cout << CList.GetWord() << endl;
		cout << CList.GetWebsite() << endl;
		cout << CList.GetInWeb() << endl;
		cout << CList.GetTime() << endl;
		cout << "�˻�Ƚ��: " << CList.GetFreq() << endl;
		cout << endl;
		bNotEmpty = next(CList);
	}
	return ;
}

void List::printLast()				// 2. last�ҷ��� ���������� ����ϴ� �Լ�
{
	CSearchHistory CList;
	bool bNotEmpty(last(CList));		// 2. last �Լ� �θ�
	while (bNotEmpty)
	{
		cout << CList.GetWord() << endl;
		cout << CList.GetWebsite() << endl;
		cout << CList.GetInWeb() << endl;
		cout << CList.GetTime() << endl;
		cout << "�˻�Ƚ��: " << CList.GetFreq() << endl;
		cout << endl;
		bNotEmpty = next(CList);
	}
	return;
}

void List::Push(ListElementType elem) {										// 4. Push�Լ�
	Link addedNode = new Node;
	assert(addedNode);

	++nTopIndex;															// �������� �� ����
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

ListElementType List::Pop() {												// 4. Pop�Լ� : ���� �ֱٵ� ���� Node�� ��������
	//assert(nTopIndex >= 0);
	--nTopIndex;															// �������� �� ����
	Link pDelNode = new Node();
	pDelNode = head;
	head = pDelNode->next;
	current = head;
	CSearchHistory CSearchHistory;
	CSearchHistory = pDelNode->elem;
	delete pDelNode;
	if (IsEmpty() == true) {
		cout << "Stack�� �� �̻� ���� �������� �ʽ��ϴ�." << endl;			// 4. isEmpty�� ����ؼ� ���� stack�� ������ ���� pop�� ��� �̸� �˷��ش�.
	}
	return CSearchHistory;
}


bool List::IsEmpty()	// 4. -1�� �ʱ�ȭ �Ǿ� �ִٰ� Push, Pop�� ������ nTopIndex�� ����, �����ϰ�
{					// �� ���� �ٽ� -1�� �Ǹ� �����Ͱ� ���̻� �������� ����
	return bool(nTopIndex == -1);
}

int List::FindByPicture(const string& word3)			// 8.
{
	ListElementType CList;
	assert(head);
	for (current = head; current->next != 0; current = current->next) {	// ���� �˻�� ã���� break�ϰ� current�� ���ڸ����� �����ִ�.
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



