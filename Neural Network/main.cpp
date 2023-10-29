#include <iostream>
#include <fstream>
#include <random>

void generateData(int n)
{
	std::ofstream out("data.txt");
	if (!out.is_open())
	{	
		std::cout << "Could not open data.txt\n";
	}
	else
	{
		out << n << "\n";
		std::random_device rd{};
		std::mt19937 gen(rd());
		std::uniform_int_distribution<>dist(1, 10);
		int r1, r2;
		int countEq{};
		for (int i = 0; i < n; i++)
		{
			r1 = dist(gen);
			r2 = dist(gen);
			out << r1 << " " << r2 << " " << (r1 == r2)<<"\n";
			if (r1 == r2)
				countEq++;
		}
		std::cout << "Count eq = " << countEq / 100.0;
	}
}


class numbersAreEqual {
private:
	int inputLayer[2];
	int hiddenLayer[2];
	int outputLayer;
	int weights1[2][2] = { {1,-1},{-1,1} };
	int weights2[2] = { 1,1 };
	int accuracy{};
	int deseiredOutput{};
public:
	numbersAreEqual() {

	}
};

int main()
{

	generateData(100);
	int inputLayer[2];
	int hiddenLayer[2];
	int outputLayer;
	int weights1[2][2] = { {1,-1},{-1,1} };
	int weights2[2] = { 1,1 };
	int accuracy{};
	int deseiredOutput{};
	for (int i = 0; i < 100; i++)
	{

	}




	return 0;
}