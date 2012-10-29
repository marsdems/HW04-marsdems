#include "Starbucks.h"

class marsdemsStarbucks : public Starbucks {
public: 
		marsdemsStarbucks();
		void build(Entry* c, int n);
		Entry* getNearest(double x, double y);
		Entry* arrayData_;
private:
		int totalSize;
};