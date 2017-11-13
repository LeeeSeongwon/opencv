#pragma once
#include "searchHistory.h"

typedef CSearchHistory ListElementType;	  //1��, list Ŭ�������� elem�� CSearchHistory�� ����ϵ��� ����
// Characteristic : 
// inorder List�� ������ �Ǿ� ListElementType�� ������ ���� ������ �� �ִ�.

class List
{
public:
	List();
	~List();

	void insert(const ListElementType & elem);
	// Preconditions : None
	// Postconditions : ��带 inorder linked list�� ����
	// Returns : None
	bool first(ListElementType & elem);
	// Preconditions : None
	// Postconditions : current�� head�� ����Ű�� ������ ��������, head�� �ƴ� Node�� ����Ű�� ������ head�� ����Ű�� �Ѵ�.
	// Returns : current�� head�� ����Ű�� �ִ°�� false, �������� true
	bool next(ListElementType & elem); 
	// Preconditions : �ּ� 1���� first�� ȣ���߾�� �Ѵ�.
	// Postconditions : current�� tail�� ����Ű�� ������ ��������, tail�� �ƴ� Node�� ����Ű�� ������ tail�� ����Ű�� �Ѵ�.
	// Returns : current�� tail�� ����Ű�� �ִ� ��� false, �������� true
	bool Current(ListElementType & elem);
	// Preconditions :  �ּ� 1���� first�� ȣ���߾�� �Ѵ�.
	// Postconditions : �����带 ����Ŵ
	// Returns : ó���� ��尡 ������ false, ������ true
	bool last(ListElementType & elem);
	// Preconditions :  �ּ� 1���� first�� ȣ���߾�� �Ѵ�.
	// Postconditions : ������ ��带 ī��Ŵ
	// Returns : ó���� ��尡 ������ false, ������ true

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
	Link tail;		// 2��. tail������ �߰�
	int nTopIndex; // 5��. Stack�� ���� Node���� ����� �� ����� nTopIndex
																				
public:
	void printLists();		//1.	����Ʈ���
	// Preconditions : ��尡 �Ѱ� �̻�
	// Postconditions : first������ �ڿ� �� �̻� ���� ���������� ���
	// Returns : None
	void printLast();			//2.������ ��� ���
	// Preconditions : ��� ��尡 �Ѱ� �̻�
	// Postconditions : ���� ����� ���� ����Ų��
	// Returns : None
	bool findOut(const string& word);    //3.���� �˻�� ���� ��� ã��
	// Preconditions : 1�� �̻��� ��尡 ����
	// Postconditions : ���� �˻�� ���� ����� SearchHistory ��� ���
	// Returns : �����ϸ� true, �����ϸ� false
	bool deleteByKeyword(const string& word2);		 //4. keyword�˻�� ������ ����� �Լ�
	// Precondition : List�� �ּ� 1���� ��尡 �����ؾ� �Ѵ�.
	// Postcondition : List�� �˻������ ���ؼ� ���� �˻����� ���� ��� delete. ������ ����Ʈ ���
	// Return : ���� �˻�� ���� ��� delete �����ϸ� true, �����ϸ� false
	void addOneList(ListElementType newone);		  // 5. �ϳ��� �˻� �����丮 �߰�
	// Preconditions : �߰��� �˻��� �����丮 �������ڷ� �޾ƿ�
	// Postconditions : �˻��� �ϳ��� �󵵼��� ���Ŀ� �°� ����Ʈ�� �߰��� ��ü ����Ʈ ���
	// Returns : None
	void AddAll(List& CAdd, List& CStack);			 // 6. �ٸ� ����Ʈ �߰��� ���ϱ�
	// Preconditions : �̹� �ִ� inorder list CStack�� ���� �Է¹��� inorder list CAdd�� �������ڷ� ����
	// Postconditions : ��� �����丮�� �󵵼����� �°� ���ĵǿ� ���
	// Returns : None
	void FindAndShowImage(const string& word3);		 // 7. ���� �˻�� ���� ��� ã�� ������ ���
	// Preconditions : �˻��� keyword�� �������ڷ� �޴´�
	// Postconditions : ã����� �˻����� �Բ� ������ ��µȴ�.
	// Returns : None
	void Push(ListElementType elem);			// 4. Push�Լ� �߰�
	// Preconditions : None
	// Postconditions : Stack ������ ���ο� Node�� ���� ���� �ְ�, ������ ���� list�� �߰��Ѵ�.
	// Returns : None
	ListElementType Pop();		// 4. Pop�Լ� �߰�
	// Preconditions : Stack�� �ּ� 1���� Node�� �����ؾ� �Ѵ�.
	// Postconditions : Stack�� ���� �ֱٿ� �־��� ���� �̾ƿ´�. �̾Ƴ� �� ���� ���̻� �������� ������ "���̻� �������� ����"�� ǥ��
	// Returns : ���� �ֱٿ� �־��� Node�� elem
	bool IsEmpty();
	// Preconditions : Stack�� �ִ� ������ 1���� Node�� �������� �Ѵ�.
	// Postconditions : Stack�� �����ִ� Node�� ���̻� ������ false�� �����ϰ� �ȴ�.
	// Returns : Stack�� ���̻� ���� ������ true, ������ false
	int FindByPicture(const string&);					// 8.���� �ִ� ������ ã�´�
	// Preconditions : CSearchHistory.m_Pic�ȿ� ������ΰ� ����־���Ѵ�. ������ ������� �ִ�.
	// Postconditions : �˸��� ��������� ��� ������ ��µǸ� �󱼺κп� �ʷϻ� �׸�ڽ��� �����.
	// Returns : ������ ��� return 0. �����ϸ� ���� �޼����� ����Ѵ�.

};
