#include<opencv2/opencv.hpp>
#define SHOWIMG
using namespace std;
using namespace cv;




int WAITTIME = 10;

void onWaittimechange(int a, void* b)
{
	;
}
 
int main(int argc, char ** argv)
{


	VideoCapture vcap;
	VideoWriter* videoWriter = NULL;


	namedWindow("ROI");


	createTrackbar("WaitKeyTime", "ROI", &WAITTIME, 1000, onWaittimechange);
 
	onWaittimechange(WAITTIME, 0);
	vcap.open("H:/UAV-G/WiSARÑµÁ·ÊÓÆµ/4.avi");
	Mat frame;
	Rect mROI;
	namedWindow("ROI", 1);
	int i = 0;
	int j = 0;
	char fileName[20];
	while (vcap.isOpened())
	{
		i++;
		vcap.read(frame);
		if (frame.empty()) continue;
		if (i % 15 == 0)
		{
			j++;
			sprintf(fileName, "D:/DJI_FLIR%04d.jpg", j);
		    imwrite(fileName, frame);
		}


#ifdef SHOWIMG
		imshow("ROI", frame);
		waitKey(WAITTIME);
		
#endif



	}

	if (vcap.isOpened())
		vcap.release();
	if (videoWriter->isOpened())
		videoWriter->release();
	if (videoWriter)
		delete videoWriter;



	//    Mat src = imread("/home/kelfor/Desktop/IR_4.jpg");
	//    infraredImageProc.getProposalROI(src);
	//
	//    imshow("ROI",src);
	//    waitKey();

}
