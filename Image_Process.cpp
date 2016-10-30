
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

#define face_width 200
#define face_height 200

bool Face_Detect(Rect face){
	bool isLarge;
	if (face.width>face_width || face.height>face_height){
			cout << "Back, please!"<<endl;
			isLarge = true;
	}
	else isLarge = false;
	cout << "here"<<  endl;
	return isLarge;	
}
