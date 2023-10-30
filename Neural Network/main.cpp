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
		
		std::cout << "Count eq = " << countEq / 100.0<<'\n';
		out.close();
	}
}

int activationFunction(int z)
{
	return z >= 0;
}

class NetworkEq {
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
					for (int j = 0;j < 2; j++)
						z += weights1[i][j] * inputLayer[j];
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

//Implementation of a true neural netwrok
class NeuralNetwork {
private:
	int inputSize;
	int hiddenSize;
	int outputSize;
	std::vector<std::vector<double>> weightsInputHidden;
	std::vector<std::vector<double>> weightsHiddenOutput;
	std::vector<double> hiddenBias;
	std::vector<double> outputBias;
	void initializeWeightsAndBiases()
	{
		std::random_device rd{};
		std::mt19937 gen(rd());
		std::uniform_real_distribution<>dist(-1, 1);
		for (int i = 0; i < hiddenSize; i++)
			for (int j = 0; j < inputSize; j++)
				weightsInputHidden[i][j] = dist(gen);
		for (int i = 0; i < outputSize; i++)
			for (int j = 0; j < hiddenSize; j++)
				weightsHiddenOutput[i][j] = dist(gen);


	}
public:
	NeuralNetwork(int inputSize, int hiddenSize, int outputSize) :
		inputSize{ inputSize },
		hiddenSize{ hiddenSize },
		outputSize{ outputSize }
	{
		weightsInputHidden.resize(hiddenSize, std::vector<double>(inputSize));
		weightsHiddenOutput.resize(outputSize, std::vector<double>(hiddenSize));
		hiddenBias.resize(hiddenSize);
		outputBias.resize(outputSize);
		initializeWeightsAndBiases();
		printWeights();
		


	}

	void printWeights()
	{
		for (int i = 0; i < hiddenSize; i++)
		{
			for (int j = 0; j < inputSize; j++)
				std::cout << weightsInputHidden[i][j] << " ";
			std::cout << "\n";
		}
		for (int i = 0; i < outputSize; i++)
		{
			for (int j = 0; j < hiddenSize; j++)
				std::cout << weightsHiddenOutput[i][j] << " ";
			std::cout << '\n';
		}
	}

};




int main()
{
	NeuralNetwork network(1, 8, 1);

	
	




	return 0;
}