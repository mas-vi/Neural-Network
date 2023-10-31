#include <iostream>
#include <fstream>
#include <random>


int activationFunctionEq(int z);

void generateData(int n);

class NetworkEq {
private:
	int weights1[2][2];
	int weights2[2];
	
public:
	NetworkEq();
	bool predict(int a, int b);
		
};

void runNetworkEq(int n);