#pragma once
#include <iostream>
#include <stdio.h>
# include <opencv2/core/core.hpp>
# include <opencv2/features2d/features2d.hpp>
# include "opencv2/highgui/highgui.hpp"
# include "opencv2/nonfree/features2d.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <conio.h>   //���Ϻ����� �ʿ��� �������

using namespace cv;
using namespace std;

int sample4(const string& NameOne, const string& NameTwo)    //NameOne:���������ȿ� �ִ� ����, NameTwo:�񱳴��
{
	
	Mat img_1 = imread(NameOne, CV_LOAD_IMAGE_GRAYSCALE);    //�̹����ҷ���
	Mat img_2 = imread(NameTwo, CV_LOAD_IMAGE_GRAYSCALE);   

	if (!img_1.data || !img_2.data)                        //�������
	{
		printf(" --(!) Error reading images \n"); return -1;
	}

	//-- Step 1: Detect the keypoints using SURF Detector
	int minHessian = 400;

	SurfFeatureDetector detector(minHessian);

	std::vector<KeyPoint> keypoints_1, keypoints_2;

	detector.detect(img_1, keypoints_1);
	detector.detect(img_2, keypoints_2);

	//-- Step 2: Calculate descriptors (feature vectors)
	SurfDescriptorExtractor extractor;

	Mat descriptors_1, descriptors_2;

	extractor.compute(img_1, keypoints_1, descriptors_1);
	extractor.compute(img_2, keypoints_2, descriptors_2);

	//-- Step 3: Matching descriptor vectors using FLANN matcher
	FlannBasedMatcher matcher;
	std::vector< DMatch > matches;
	matcher.match(descriptors_1, descriptors_2, matches);

	double max_dist = 0; double min_dist = 100;

	//-- Quick calculation of max and min distances between keypoints
	for (int i = 0; i < descriptors_1.rows; i++)
	{
		double dist = matches[i].distance;
		if (dist < min_dist) min_dist = dist;
		if (dist > max_dist) max_dist = dist;
	}

	printf("-- Max dist : %f \n", max_dist);
	printf("-- Min dist : %f \n", min_dist);

	//-- Draw only "good" matches (i.e. whose distance is less than 2*min_dist,
	//-- or a small arbitary value ( 0.02 ) in the event that min_dist is very
	//-- small)
	//-- PS.- radiusMatch can also be used here.
	std::vector< DMatch > good_matches;

	for (int i = 0; i < descriptors_1.rows; i++)
	{
		if (matches[i].distance <= max(2 * min_dist, 0.02))
		{
			good_matches.push_back(matches[i]);
		}
	}

	//-- Draw only "good" matches
	Mat img_matches;
	drawMatches(img_1, keypoints_1, img_2, keypoints_2,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);

	//-- Show detected matches
	imshow("Matching result", img_matches);
	waitKey();

	int i;
	for (i = 0; i < (int)good_matches.size(); i++)
	{
		printf("-- Matching result [%d] Keypoint 1: %d  -- Keypoint 2: %d  \n", i, good_matches[i].queryIdx, good_matches[i].trainIdx);		
	}
	if (i > 99) {
		printf("same person!!!!!!!!!");
		return 1;
	}
	return 0;
}

int reFile(string& NameTwo)         //�����ϴ� �Լ�
{
	string locate1 = "C:\\Users\\Lee seong won\\Documents\\Visual Studio 2015\\projects\\facecompare\\" + NameTwo;   //������ġ
	string locate2 = "C:\\Users\\Lee seong won\\Desktop\\" + NameTwo;    //��������ġ
	
	char* locate3 = new char[locate1.size() + 1];             //fopen()������ string->char*�� ��ȯ
	char* locate4 = new char[locate2.size() + 1];
	strcpy_s(locate3, locate1.size() + 1, locate1.c_str());
	strcpy_s(locate4, locate2.size() + 1, locate2.c_str());

	FILE *ftr1 = fopen(locate3, "rb");
	FILE *ftr2 = fopen(locate4, "wb");

	char buf[13000];
	int read;

	if (ftr1 == NULL || ftr2 == NULL)
	{
		printf("������ ������ �� �����ϴ�\a");
		_getch();
	}

	while (1)
	{
		read = (int)fread((void *)buf, 1, 13000, ftr1);

		if (read < 13000)
		{
			if (feof(ftr1) != 0)
			{
				fwrite((void *)buf, 1, read, ftr2);
				printf("���� �Ϸ�");
				break;
			}
			else
				printf("���� ����");
			break;
		}
		fwrite((void *)buf, 1, 13000, ftr2);
	}

	fclose(ftr1);
	fclose(ftr2);
	_getch();

	return 0;
}

int reFile2()          //�����ϴ� �Լ�22
{

	FILE *ftr1 = fopen("D:\\sample.jpg", "rb");     //�������� ��ġ�� �̸�
	FILE *ftr2 = fopen("C:\\Users\\Lee seong won\\Desktop\\image\\sample.jpg", "wb"); //������ ���� ��ġ�� ���� �̸��� �������־���� 

	char buf[13000];
	int read;

	if (ftr1 == NULL || ftr2 == NULL)
	{
		printf("������ ������ �� �����ϴ�\a");
		_getch();
	}

	while (1)
	{
		read = (int)fread((void *)buf, 1, 13000, ftr1);

		if (read < 13000)
		{
			if (feof(ftr1) != 0)
			{
				fwrite((void *)buf, 1, read, ftr2);
				printf("���� �Ϸ�");
				break;
			}
			else
				printf("���� ����");
			break;
		}
		fwrite((void *)buf, 1, 13000, ftr2);
	}

	fclose(ftr1);
	fclose(ftr2);
	_getch();

	return 0;
}
