#include <iostream>
#include <string>
#include "List.h"
#include "color.h"

using namespace std;

int main()
{
	List CSearchLists;
	List CAdd;  //6번을 위한 추가할 리스트
	CSearchHistory	CSearch10 = { "장미대선날짜", "www.blog.naver.com / daesunjujo ? Redirect = Log&logNo = 220962832337", "2017년 5월 9일","11월 4일 검색함",9, "image\\rose.jpg" }
		, CSearch9 = { "타이완맛집","www.blog.naver.com/topnotchlady?Redirect=Log&logNo=220505160823/t", "타이완 타이페이 융캉제","2월 16일 검색함", 30,"image\\taiwan.jpg" }
		, CSearch8 = { "매운거 먹고 속쓰릴때" ,"www.cafe.naver.com / starconvert / 12888 / t","꿀물","1월 10일 검색함",23 ,"image\\honey.jpg" }
		, CSearch7 = { "공유가 찍은 광고", "www.tv.naver.com / v / 1570552 / t" , "일룸 책상" ,"3월 5일 검색함", 12,"image\\gongu.jpg" }
		, CSearch6 = { "마카오 여행","www.blog.naver.com/ginahonga/10187348190/t" ,"마카오 3박4일 여행경비", "11월 13일 검색함", 60,"image\\macao.jpg" }
		, CSearch5 = { "분식맛집","www.blog.naver.com/aamy78/220957719544/t" ,"영파여고 마늘떡볶이","2월 25일 검색함", 5 ,"image\\dduck.jpg" }
		, CSearch4 = { "벚꽃축제", "www.korean.visitkorea. or .kr / kor / bz15 / where / festival / festival.jsp ? cid = 1592898", "석촌호수",  "6월 16일 검색함 ", 17,"image\\flower.jpg" }
		, CSearch3 = { "파스타맛집","www.blog.naver.com/hyonee_s2?Redirect=Log&logNo=220890927737", "방이동 코벤트가든", "9월 4일 검색함",3 ,"image\\coventgarden.jpg" }
		, CSearch2 = { "해외인턴","www.blog.hunian.co.kr/220956685027" ,"캐나다","11월 9일 검색함" ,15, "image\\canada.jpg" }
	, CSearch1 = { "아이유 신곡", "www.youtube.com/watch?v=Uc2bxObsXHU", "이런 엔딩","4월 26일 검색함", 32, "image\\iu.jpg" };

	SetColor_Yellow;
	cout << "**********1번 문제 inorder linked list를 이용한 출력**********" << endl << endl;
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

	CSearchLists.printLists();		// 1. list 출력


	SetColor_Yellow;
	cout << "*********2번 문제 last함수만들어 마지막 원소 출력**********" << endl << endl;
	SetColor_White;
	CSearchLists.printLast();		//  2. last함수 호출함


	SetColor_Yellow;
	cout << "**********3번 문제 find함수를 사용한 검색예제*********" << endl << endl;
	SetColor_White;
	cout << "keyword : 아이유" << endl << endl;
	CSearchLists.findOut("아이유 신곡");


	SetColor_Yellow;
	cout << "**********4번 문제 delete함수를 만들어 예제로 확인*********" << endl << endl;
	SetColor_White;
	cout << "keyword : 벚꽃축제" << endl << endl;
	if (CSearchLists.deleteByKeyword("벚꽃축제") == 0) cout << "없어서 지우지 못해요" << endl;    //검색어가 없을 경우 출력
	else CSearchLists.printLists();


	SetColor_Yellow;
	cout << "**********5번 문제 검색어 추가************" << endl << endl;
	SetColor_White;

	cout << "****존재하지 않는 검색어 추가 : '스시맛집'" << endl << endl;
	CSearchHistory CSearch11 = { "스시맛집", "www.cafe.naver.com/lovedew2007/6577","2017년 3월 4일","3월 2일 검색함", 25, "sushi.jpg" };
	CSearchLists.addOneList(CSearch11);
	CSearchLists.printLists();

	cout << "****존재하는 검색어 추가 : '해외인턴'" << endl << endl;
	CSearchHistory CSearch12 = { "해외인턴","www.blog.hunian.co.kr/220956685027" ,"캐나다","11월 9일 검색함" ,15, "image\\canada.jpg" };
	CSearchLists.addOneList(CSearch12);
	CSearchLists.printLists();

	SetColor_Yellow;
	cout << "**********6번 문제 AddAll함수 만들어 list 더하기*********" << endl << endl;
	SetColor_White;
	CSearchHistory newone2 = { "opencv깔기", "www.opencv.org/releases.html","window opencv","3월 2일 검색함", 33, "opencvv.jpg" };
	CSearchHistory newone1 = { "라디오스타에 나온 잘생긴애","www.recommendd.tistory.com/20","박형식","8월 2일 검색함",47,"person.jpg" };
	CSearchHistory newone0 = { "찐빵사진","www.blog.naver.com/lenciel?Redirect=Log&logNo=220979299239","오리찐빵","4월 4일 검색함",1,"duck.jpg" };
	CAdd.Push(newone0);
	CAdd.Push(newone1);
	CAdd.Push(newone2);		//입력받은 list를 inorder list로 만들기

	cout << "--입력받은 list 출력하면--" << endl << endl;
	CAdd.printLists();		//ordered 된 list 출력

	CSearchLists.AddAll(CAdd, CSearchLists);    //AddAll함수로 두 list를 입력받아 빈도수에 맞춰 list를 하나로 합침

	cout << "--원래 list에 입력받은 list가 추가됨--" << endl << endl;
	CSearchLists.printLists();


	SetColor_Yellow;
	cout << "**********7번 문제 FindAndShowImage함수으로 영상까지 출력*********" << endl << endl;
	SetColor_White;
	cout << "keyword : 아이유" << endl << endl;
	CSearchLists.FindAndShowImage("아이유 신곡");


	SetColor_Yellow;
	cout << "**********8번 문제 얼굴이 들어있는 사진 검색*********" << endl << endl;
	SetColor_White;
	//CSearchLists.FindByPicture("타이완");

	return 0;
}



