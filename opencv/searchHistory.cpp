#include "searchHistory.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;

CSearchHistory::CSearchHistory()
	: m_initNaver(" "), m_webSite(" "), m_inWebsite(" "), m_searchTime(" "), m_freq(), m_pic(" ")
{
}

CSearchHistory::CSearchHistory(string initNaver, string webSite, string inWebsite, string searchTime, int freq, string picture)
	: m_initNaver(initNaver), m_webSite(webSite), m_inWebsite(inWebsite), m_searchTime(searchTime), m_freq(freq), m_pic(picture)
{

}

CSearchHistory::~CSearchHistory()
{
}

string CSearchHistory::GetWord()
{
	return m_initNaver;
}

void CSearchHistory::SetWord(string initNaver)
{
	m_initNaver = initNaver;
}

string CSearchHistory::GetWebsite()
{
	return m_webSite;
}

void CSearchHistory::SetWebsite(string webSite)
{
	m_webSite = webSite;
}

string CSearchHistory::GetInWeb()
{
	return m_inWebsite;
}

void CSearchHistory::SetInWeb(string inWebsite)
{
	m_inWebsite = inWebsite;
}

string CSearchHistory::GetTime()
{
	return m_searchTime;
}

void CSearchHistory::SetTime(string searchTime)
{
	m_searchTime = searchTime;
}

int CSearchHistory::GetFreq()
{
	return m_freq;
}
string CSearchHistory::GetPicture()
{
	return m_pic;
}

void CSearchHistory::SetPicture(string picture)
{
	m_pic = picture;
}

void CSearchHistory::SetFreq(int freq)
{
	m_freq = freq;
}

void CSearchHistory::PrintPicture()		// 5. opencv를 통해 사진을 출력하는 함수
{
	Mat srcImage = imread(m_pic);
	//if (srcImage.empty()) {
		imshow("Display window", srcImage);
	//}
	waitKey(0);

}
// Function Headers
void detectAndDisplay(Mat frame);		//8. 얼굴인식 opencv코드

// Global variables
// Copy this file from opencv/data/haarscascades to target folder
string face_cascade_name = "c:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt2.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";
int filenumber; // Number of file to be saved
string filename;

int CSearchHistory::FindPicture()			
{
	// Load the cascade
	if (!face_cascade.load(face_cascade_name)) {
		printf("--(!)Error loading\n");
		return (-1);
	}

	// Read the image file
	Mat frame = imread(m_pic);
	// Apply the classifier to the frame
	if (!frame.empty()) {
		detectAndDisplay(frame);
	}
	else {
		printf(" --(!) No captured frame -- Break!");
		//break;
	}
	waitKey(0);
	//int c = waitKey(10);

	//if (27 == char(c)) {
		//break;
	//}

	return 0;
}

// Function detectAndDisplay
void detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	Mat crop;
	Mat res;
	Mat gray;
	string text;
	stringstream sstm;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	// Detect faces
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	// Set Region of Interest
	cv::Rect roi_b;
	cv::Rect roi_c;

	size_t ic = 0; // ic is index of current element
	int ac = 0; // ac is area of current element

	size_t ib = 0; // ib is index of biggest element
	int ab = 0; // ab is area of biggest element

	for (ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)

	{
		roi_c.x = faces[ic].x;
		roi_c.y = faces[ic].y;
		roi_c.width = (faces[ic].width);
		roi_c.height = (faces[ic].height);

		ac = roi_c.width * roi_c.height; // Get the area of current element (detected face)

		roi_b.x = faces[ib].x;
		roi_b.y = faces[ib].y;
		roi_b.width = (faces[ib].width);
		roi_b.height = (faces[ib].height);

		ab = roi_b.width * roi_b.height; // Get the area of biggest element, at beginning it is same as "current" element

		if (ac > ab)
		{
			ib = ic;
			roi_b.x = faces[ib].x;
			roi_b.y = faces[ib].y;
			roi_b.width = (faces[ib].width);
			roi_b.height = (faces[ib].height);
		}

		crop = frame(roi_b);
		resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // This will be needed later while saving images
		cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

										   // Form a filename
		filename = "";
		stringstream ssfn;
		ssfn << filenumber << ".png";
		filename = ssfn.str();
		filenumber++;

		//imwrite(filename, gray);

		Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
		Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
		rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
	}

	// Show image
	sstm << "Crop area size: " << roi_b.width << "x" << roi_b.height << " Filename: " << filename;
	text = sstm.str();

	putText(frame, text, cvPoint(30, 30), FONT_HERSHEY_COMPLEX_SMALL, 0.8, cvScalar(0, 0, 255), 1, CV_AA);
	imshow("original", frame);

	if (!crop.empty())
	{
		imshow("detected", crop);
	}
	
}


























