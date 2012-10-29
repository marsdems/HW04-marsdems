/**********************************************************
* Programmer: Mike Marsden
* Assignment: Homework04
* Date: 10/27/2012
* File: HW04App.cpp
**********************************************************/
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Starbucks.h"
#include "marsdemsStarbucks.h"
#include <fstream>
#include <iostream>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	int sizeCount;

	void setup();
	void mouseDown( MouseEvent event );	
	Entry* getData();
	void update();
	void draw();
};

void HW04App::setup()
{
	sizeCount = 0;
	Entry* inputFile = getData();	
	int n = sizeCount;
	marsdemsStarbucks* inputData = new marsdemsStarbucks();

	//Testing Data for build() and getNearest()
	inputData->build(inputFile, n);
	Entry* nearest = inputData -> getNearest(.825088,.6786); //Looking for Yonkers, New York
	
	console() << nearest->identifier << "(" << nearest->x << ", " << nearest->y << ")" << endl;
}

Entry* HW04App::getData()
{
	ifstream in("../resources/Starbucks_2006.csv");
	Entry entry;
	double x, y;
	string text = "";
	while (in.good()) {
		getline(in, text, ',');
		in >> x;
		in.get();
		in >> y;
		in.get();
		sizeCount++;
	}
	in.clear();
	in.seekg(0);

	Entry* locs = new Entry [sizeCount];
	sizeCount = 0;

	while (in.good()) {
		getline(in, text, ',');
		in >> x;
		in.get();
		in >> y;
		in.get();
		(locs+sizeCount)->identifier = text;
		(locs+sizeCount)->x = x;
		(locs+sizeCount)->y = y;

		sizeCount ++;
	}
	in.close();

	return locs;
}

void HW04App::mouseDown( MouseEvent event )
{
}

void HW04App::update()
{
}

void HW04App::draw()
{
	// clear out the window with black
	 //gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04App, RendererGl )
