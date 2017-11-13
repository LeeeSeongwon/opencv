#pragma once
#include <iostream>
#include <string>

using namespace std;
// Characteristic :
// string�����ΰ˻���, ������Ʈ, �����κ�, ��¥, �󵵼��׸�������� ����
class CSearchHistory
{
public:
	CSearchHistory();
	CSearchHistory(string initNaver, string webSite, string inWebsite, string searchTime, int freq, string picture);
	~CSearchHistory();
private:
	string m_inWebsite;
	string m_initNaver;
	string m_webSite;
	string m_searchTime;
	string m_pic;
public:
	// private ��������鿡����Getters, Setters
	string GetWord();
	void SetWord(string initNaver);
	string GetWebsite();
	void SetWebsite(string webSite);
	string GetInWeb();
	void SetInWeb(string inWebsite);
	string GetTime();
	void SetTime(string searchTime);
	int m_freq;
	int GetFreq();
	void SetFreq(int freq);
	string GetPicture();
	void SetPicture(string picture);
	
	void PrintPicture();  // 7.������ ���
	// Preconditions : CSearchHistory.m_Pic�ȿ� ������ΰ�����־���Ѵ�
	// Postconditions : �˸��� ��������� ��� ��������µȴ�.
	// Returns : None
	int FindPicture();	// 8.���� �ִ� ������ ã�´�
	// Preconditions : CSearchHistory.m_Pic�ȿ� ������ΰ� ����־���Ѵ�. ������ ������� �ִ�.
	// Postconditions : �˸��� ��������� ��� ������ ��µǸ� �󱼺κп� �ʷϻ� �׸�ڽ��� �����.
	// Returns : ������ ��� return 0. �����ϸ� ���� �޼����� ����Ѵ�.

};
