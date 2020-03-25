#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    cout << "Waveshare OpenCV Tutorial"<< endl;
    cout << "OpenCV"<<endl;
	cout << "A demo to show whether The OpenCV and CSI camera is well installed"  << endl;
    cout << "OpenCV Version:" << CV_VERSION << endl;
    // 0: use CSI camera,1：use USB camera
    VideoCapture cap(0);
    if(!cap.isOpened())
    {
        cout<<"can't open this camera"<<endl;
		return -1;
    }    
    Mat FrameImage,GrayImage,BlurImage,CannyImage;


	cap.set(CAP_PROP_FRAME_WIDTH, 480);
	cap.set(CAP_PROP_FRAME_HEIGHT, 640);
	
    while(1)
    {
        cap>>FrameImage;

		//imshow("camera", FrameImage);
		
        //Change to gray image
        cvtColor(FrameImage,GrayImage,COLOR_BGR2GRAY);
		
		
        //blur the image
        blur(GrayImage,BlurImage,Size(7,7));
		//imshow("Camera BlurImage",BlurImage);
		
        //use canny to detect contour
        Canny(BlurImage,CannyImage,3,9);
        //show the image
        imshow("Camera Capture",CannyImage);
		#if 0
		#endif
		
		#if 1
        //Press Q to quit
        if(char(waitKey(1)) == 'q')
        {
            break;
        }
		#endif
    }
    return 0;
}