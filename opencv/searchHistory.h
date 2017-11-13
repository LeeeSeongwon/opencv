#pragma once
#include <iostream>
#include <string>

using namespace std;
// Characteristic :
// string형으로검색어, 웹사이트, 정보부분, 날짜, 빈도수그리고사진을 저장
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
	// private 멤버변수들에대한Getters, Setters
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
	
	void PrintPicture();  // 7.사진을 출력
	// Preconditions : CSearchHistory.m_Pic안에 사진경로가들어있어야한다
	// Postconditions : 알맞은 사진경로일 경우 사진이출력된다.
	// Returns : None
	int FindPicture();	// 8.얼굴이 있는 사진을 찾는다
	// Preconditions : CSearchHistory.m_Pic안에 사진경로가 들어있어야한다. 사진에 사람얼굴이 있다.
	// Postconditions : 알맞은 사진경로의 경우 사진이 출력되며 얼굴부분에 초록색 네모박스가 생긴다.
	// Returns : 성공한 경우 return 0. 실패하면 에러 메세지를 출력한다.

};
