#include "marsdemsStarbucks.h"

void marsdemsStarbucks::build(Entry* c, int n) {
	arrayData_ = new Entry[n];
	for (int i = 0; i < n; i++) {
			arrayData_[i] = c[i];
	}
	totalSize = n;
}

Entry* marsdemsStarbucks::getNearest(double x, double y) {
	Entry* currentNearest = new Entry();
	Entry* temp = arrayData_[0];
	for (int i = 0; i<size; i++) {
	
	
	
	
	
	}
	
	*currentNearest = temp;
	return currentNearest;
}