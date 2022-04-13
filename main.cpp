#include <iostream>
#include <opencv2/opencv.hpp>

int main() {

	cv::VideoCapture vid(0);

	if (!vid.isOpened())
	{
		std::cout << "Web Cam can not open." << std::endl;
		system("paused");
		return -1;
	}

	cv::namedWindow("Window", cv::WindowFlags::WINDOW_AUTOSIZE);

	while (true)
	{
		cv::Mat frame;
		bool control = vid.read(frame);

		if (!control)
		{
			std::cout << "Web Cam frame can not open." << std::endl;
			system("pause");
			break;
		}

		cv::Mat hsv_frame;
		cv::cvtColor(frame, hsv_frame, cv::COLOR_BGR2HSV);

		// (175, 50, 20)-(180, 255, 255) -> red
		// (45, 100, 50)-(75, 255, 255) -> green
		// (69, 37, 0)-(134, 255, 255) -> blue
		// (0, 0, 0)-(180, 255, 30) -> black
		// (0, 0, 200)-(180, 255, 255) -> white

		cv::Scalar lower_color(0, 0, 200);
		cv::Scalar upper_color(180, 255, 255);

		cv::Mat mask;
		cv::inRange(hsv_frame, lower_color, upper_color, mask);


		cv::imshow("Window", frame);
		cv::imshow("Mask", mask);

		if (cv::waitKey(30) == 27)
		{
			std::cout << "Quit with ESC" << std::endl;
			system("pause");
			break;
		}
	}

	return 0;
}