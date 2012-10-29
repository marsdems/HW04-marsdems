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
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void HW04App::setup()
{
	Entry* inputFile = new Entry[10];
	ifstream in("Starbucks_2006.csv");

	for (int i = 0; i< 7655; i++) {
		getline(in, inputFile[i].identifier);

		in >> inputFile[i].x;
		in.get();
		in >> inputFile[i].y;
		in.get();
	}

	marsdemsStarbucks* inputData = new marsdemsStarbucks();

	inputData->build(inputFile, 10);
	Entry* nearest = inputData -> getNearest(.1,.1);

	cout << nearest->identifier << endl;
	cout << nearest->x << endl;
	cout << nearest->y << endl;
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
	// gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04App, RendererGl )
