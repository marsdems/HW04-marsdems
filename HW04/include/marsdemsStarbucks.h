/**********************************************************
* Programmer: Mike Marsden
* Assignment: Homework04
* Date: 10/27/2012
* File: marsdemsStarbucks.h
**********************************************************/
#include "Starbucks.h"

class marsdemsStarbucks : public Starbucks {
public: 
		void build(Entry* c, int n);
		Entry* getNearest(double x, double y);
		Entry* arrayData_;
private:
		int totalSize;
};