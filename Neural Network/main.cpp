#include <iostream>
#include <fstream>
#include <random>
#include "networkEq.hpp"


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
	std::vector<double> predict(const std::vector<double>& input)
	{
		
		
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
	runNetworkEq(150);
	
	

	
	




	return 0;
}