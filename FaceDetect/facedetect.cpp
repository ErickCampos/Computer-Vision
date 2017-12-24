#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(){
	VideoCapture camera(0);
	Mat frame;
	
	CascadeClassifier face_cascade;
	vector<Rect> face(2);
	face_cascade.load("haarcascades/haarcascade_frontalface_default.xml");
	
	
	while(1){
		camera >> frame;
		
		face_cascade.detectMultiScale(frame, face, 2.1, 3, 0 |CV_HAAR_SCALE_IMAGE, Size(100, 100) );
		
		for(int i=0; i<face.size(); i++){
			rectangle(frame, face[i], CV_RGB(0, 255, 0), 1);
		}
		
		imshow("WebCam", frame);
		char esc = (char)waitKey(30);
		if(esc==27)
			break;
	}
	
	return 0;
}
