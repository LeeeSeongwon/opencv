#include <iostream>
#include <string>
#include "List.h"
#include "color.h"

using namespace std;

int main()
{
	List CSearchLists;
	List CAdd;  //6���� ���� �߰��� ����Ʈ
	CSearchHistory	CSearch10 = { "��̴뼱��¥", "www.blog.naver.com / daesunjujo ? Redirect = Log&logNo = 220962832337", "2017�� 5�� 9��","11�� 4�� �˻���",9, "image\\rose.jpg" }
		, CSearch9 = { "Ÿ�̿ϸ���","www.blog.naver.com/topnotchlady?Redirect=Log&logNo=220505160823/t", "Ÿ�̿� Ÿ������ ��Ĳ��","2�� 16�� �˻���", 30,"image\\taiwan.jpg" }
		, CSearch8 = { "�ſ�� �԰� �Ӿ�����" ,"www.cafe.naver.com / starconvert / 12888 / t","�ܹ�","1�� 10�� �˻���",23 ,"image\\honey.jpg" }
		, CSearch7 = { "������ ���� ����", "www.tv.naver.com / v / 1570552 / t" , "�Ϸ� å��" ,"3�� 5�� �˻���", 12,"image\\gongu.jpg" }
		, CSearch6 = { "��ī�� ����","www.blog.naver.com/ginahonga/10187348190/t" ,"��ī�� 3��4�� ������", "11�� 13�� �˻���", 60,"image\\macao.jpg" }
		, CSearch5 = { "�нĸ���","www.blog.naver.com/aamy78/220957719544/t" ,"���Ŀ��� ���ö�����","2�� 25�� �˻���", 5 ,"image\\dduck.jpg" }
		, CSearch4 = { "��������", "www.korean.visitkorea. or .kr / kor / bz15 / where / festival / festival.jsp ? cid = 1592898", "����ȣ��",  "6�� 16�� �˻��� ", 17,"image\\flower.jpg" }
		, CSearch3 = { "�Ľ�Ÿ����","www.blog.naver.com/hyonee_s2?Redirect=Log&logNo=220890927737", "���̵� �ں�Ʈ����", "9�� 4�� �˻���",3 ,"image\\coventgarden.jpg" }
		, CSearch2 = { "�ؿ�����","www.blog.hunian.co.kr/220956685027" ,"ĳ����","11�� 9�� �˻���" ,15, "image\\canada.jpg" }
	, CSearch1 = { "������ �Ű�", "www.youtube.com/watch?v=Uc2bxObsXHU", "�̷� ����","4�� 26�� �˻���", 32, "image\\iu.jpg" };

	SetColor_Yellow;
	cout << "**********1�� ���� inorder linked list�� �̿��� ���**********" << endl << endl;
	SetColor_White;
	CSearchLists.insert(CSearch1);
	CSearchLists.insert(CSearch2);
	CSearchLists.insert(CSearch3);
	CSearchLists.insert(CSearch4);
	CSearchLists.insert(CSearch5);
	CSearchLists.insert(CSearch6);
	CSearchLists.insert(CSearch7);
	CSearchLists.insert(CSearch8);
	CSearchLists.insert(CSearch9);
	CSearchLists.insert(CSearch10);

	CSearchLists.printLists();		// 1. list ���


	SetColor_Yellow;
	cout << "*********2�� ���� last�Լ������ ������ ���� ���**********" << endl << endl;
	SetColor_White;
	CSearchLists.printLast();		//  2. last�Լ� ȣ����


	SetColor_Yellow;
	cout << "**********3�� ���� find�Լ��� ����� �˻�����*********" << endl << endl;
	SetColor_White;
	cout << "keyword : ������" << endl << endl;
	CSearchLists.findOut("������ �Ű�");


	SetColor_Yellow;
	cout << "**********4�� ���� delete�Լ��� ����� ������ Ȯ��*********" << endl << endl;
	SetColor_White;
	cout << "keyword : ��������" << endl << endl;
	if (CSearchLists.deleteByKeyword("��������") == 0) cout << "��� ������ ���ؿ�" << endl;    //�˻�� ���� ��� ���
	else CSearchLists.printLists();


	SetColor_Yellow;
	cout << "**********5�� ���� �˻��� �߰�************" << endl << endl;
	SetColor_White;

	cout << "****�������� �ʴ� �˻��� �߰� : '���ø���'" << endl << endl;
	CSearchHistory CSearch11 = { "���ø���", "www.cafe.naver.com/lovedew2007/6577","2017�� 3�� 4��","3�� 2�� �˻���", 25, "sushi.jpg" };
	CSearchLists.addOneList(CSearch11);
	CSearchLists.printLists();

	cout << "****�����ϴ� �˻��� �߰� : '�ؿ�����'" << endl << endl;
	CSearchHistory CSearch12 = { "�ؿ�����","www.blog.hunian.co.kr/220956685027" ,"ĳ����","11�� 9�� �˻���" ,15, "image\\canada.jpg" };
	CSearchLists.addOneList(CSearch12);
	CSearchLists.printLists();

	SetColor_Yellow;
	cout << "**********6�� ���� AddAll�Լ� ����� list ���ϱ�*********" << endl << endl;
	SetColor_White;
	CSearchHistory newone2 = { "opencv���", "www.opencv.org/releases.html","window opencv","3�� 2�� �˻���", 33, "opencvv.jpg" };
	CSearchHistory newone1 = { "������Ÿ�� ���� �߻����","www.recommendd.tistory.com/20","������","8�� 2�� �˻���",47,"person.jpg" };
	CSearchHistory newone0 = { "�𻧻���","www.blog.naver.com/lenciel?Redirect=Log&logNo=220979299239","������","4�� 4�� �˻���",1,"duck.jpg" };
	CAdd.Push(newone0);
	CAdd.Push(newone1);
	CAdd.Push(newone2);		//�Է¹��� list�� inorder list�� �����

	cout << "--�Է¹��� list ����ϸ�--" << endl << endl;
	CAdd.printLists();		//ordered �� list ���

	CSearchLists.AddAll(CAdd, CSearchLists);    //AddAll�Լ��� �� list�� �Է¹޾� �󵵼��� ���� list�� �ϳ��� ��ħ

	cout << "--���� list�� �Է¹��� list�� �߰���--" << endl << endl;
	CSearchLists.printLists();


	SetColor_Yellow;
	cout << "**********7�� ���� FindAndShowImage�Լ����� ������� ���*********" << endl << endl;
	SetColor_White;
	cout << "keyword : ������" << endl << endl;
	CSearchLists.FindAndShowImage("������ �Ű�");


	SetColor_Yellow;
	cout << "**********8�� ���� ���� ����ִ� ���� �˻�*********" << endl << endl;
	SetColor_White;
	//CSearchLists.FindByPicture("Ÿ�̿�");

	return 0;
}



