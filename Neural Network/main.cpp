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
		out.close();
	}
}

int activationFunction(int z)
{
	return z >= 0;
}

class Network {
private:
	int inputLayer[2];
	int hiddenLayer[2];
	int outputLayer;
	int weights1[2][2] = { {1,-1},{-1,1} };
	int weights2[2] = { 1,1 };
	int accuracy{};
	int desiredOutput{};
	int k{};
public:
	void run()
	{
		std::ifstream in("data.txt");
		if (!in.is_open())
		{
			std::cout << "Could not open the data.txt\n";
		}
		else {
			while (in)
			{
				if (k == 10)
				{
					std::cout << "Accuracy for an epoch = " << accuracy / 10.0<<"\n";
					k = 0;
					accuracy = 0;
				}
				in >> inputLayer[0] >> inputLayer[1] >> desiredOutput;
				for (int i = 0; i < 2; i++)
				{
					int z = 0;
					for (int i = 0; i < 2; i++)
						z += weights1[i][k] * inputLayer[k];
					hiddenLayer[i] = activationFunction(z);
				}
				int z = 0;
				for (int k = 0; k < 2; k++)
					z += weights2[k] * hiddenLayer[k] - 1;
				outputLayer = activationFunction(z);
				if (outputLayer == desiredOutput)
					accuracy++;
				k++;
				


			}
		}

	}
};

int main()
{
	generateData(100);
	Network network;
	network.run();

	
	




	return 0;
}