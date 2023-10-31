#include "networkEq.hpp"

NetworkEq::NetworkEq():
	weights1  { {1,-1},{-1,1} },
	weights2{1,1}
{
	

}
bool NetworkEq::predict(int a, int b)
{
	int inputLayer[2] = { a,b };
	int hiddenLayer[2]{};
	
	for (int i = 0; i < 2; i++)
	{
		int z{};
		for (int k = 0; k < 2; k++)
			z += weights1[i][k] * inputLayer[k];
		hiddenLayer[i] = activationFunctionEq(z);
	}
	int z{};
	for (int i = 0; i < 2; i++)
	{
		z += weights2[i] * hiddenLayer[i];
	}
	z -= 1;
	return z;
}

int activationFunctionEq(int z)
{
	return (z >= 0) ? 1 : 0;
}

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
		for (int i = 0; i < n; i++)
		{
			r1 = dist(gen);
			r2 = dist(gen);
			out << r1 << " " << r2 << " " << (r1 == r2) << "\n";
		}

		
		out.close();
	}
}

void runNetworkEq(int n)
{
	generateData(n);
	NetworkEq eq;
	std::ifstream in("data.txt");
	if (!in.is_open())
		std::cout << "Could not open data.txt\n";
	else
	{
		int a, b, output;
		int count{}, countEq{};
		while (in)
		{
			in >> a >> b >> output;
			if (eq.predict(a, b) == static_cast<bool>(output))
				countEq++;
			count++;

		}
		std::cout << "The network had an accuracy of " << static_cast<double>(countEq) / count;
	}
}
