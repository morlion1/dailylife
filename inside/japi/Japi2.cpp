#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cv.h>
#include <highgui.h>
void Show(char *str, IplImage *img)
{
    cvNamedWindow( str, 1);
    cvShowImage( str, img );
}

using namespace cv;
using namespace std;

#define SCALE 0.2
#define NUM 2
#define BINS 8

int main(int argc, char** argv)
{
    string imgNames[NUM] = { "/japi/japi/image/333.jpeg","/japi/japi/image/444.jpeg" };


    Mat imgs[NUM];
    Mat imgsHLS[NUM];

    for (int i = 0; i < NUM; i++)
    {
        imgs[i] = imread(imgNames[i], IMREAD_COLOR);
        if (imgs[i].data == 0)
        {
            cout << "Unable to read " << imgNames[i] << endl;
            return 0;
        }
        cvtColor(imgs[i], imgsHLS[i], COLOR_BGR2HLS  );//COLOR_BGR2HLS);
    }

    Mat histogram[NUM];

    int channel_numbers[] = { 0, 1, 2 };
    for (int i = 0; i < NUM; i++)
    {
        int* number_bins = new int[imgsHLS[i].channels()];
        for (int ch = 0; ch < imgsHLS[i].channels(); ch++)
        {
            number_bins[ch] = BINS;
        }
        float ch_range[] = { 0.0, 255.0 };
        const float *channel_ranges[] = { ch_range, ch_range, ch_range };
        calcHist(&imgsHLS[i], 1, channel_numbers, Mat(), histogram[i], imgsHLS[i].channels(), number_bins, channel_ranges);
        normalize(histogram[i], histogram[i], 1.0);
    }

    cout << "Image Comparison by HISTCMP_CORREL   " << endl;
    for (int i = 0; i < NUM; i++)
    {
        for (int j = i + 1; j < NUM; j++)
        {
            double matching_score = compareHist(histogram[i], histogram[j], HISTCMP_CORREL);
            cout << imgNames[i] << "-" << imgNames[j] << ", " << matching_score << endl;
        }
    }
    return 0;
}

