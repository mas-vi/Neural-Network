#include <iostream>
#include <fstream>
#include <random>
#include "networkEq.hpp"


//Implementation of a true neural netwrok

double sigmoid(double z)
{
	return 1.0 / (1 + exp(-z));
}
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
		for (int i = 0; i < hiddenSize; i++)
			hiddenBias[i] = dist(gen);
		for (int i = 0; i < outputSize; i++)
			outputBias[i] = dist(gen);


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
		printWeightsAndBiases();
		


	}



	std::vector<double> predict(const std::vector<double>& input)
	{
		std::vector<double> hiddenLayer(hiddenSize);
		std::vector<double> outputLayer(outputSize);
		for (int i = 0; i < hiddenSize; i++)
		{
			double z{0.0};
			for (int k = 0; k < inputSize; k++)
				z += weightsInputHidden[i][k] * input[k];
			z += hiddenBias[i];
			hiddenLayer[i] = sigmoid(z);
				
		}
		for (int i = 0; i < outputSize; i++)
		{
			double z{0.0};
			for (int k = 0; k < hiddenSize; k++)
				z += weightsHiddenOutput[i][k] * hiddenLayer[k];
			z += outputBias[i];
			outputLayer[i] = sigmoid(z);
		}
		return outputLayer;
		
	}

	void printWeightsAndBiases()
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
		for (int i = 0; i < hiddenSize; i++)
			std::cout << hiddenBias[i] << " ";
		std::cout << '\n';
		for (int i = 0; i < outputSize; i++)
			std::cout << outputBias[i] << " ";
		std::cout << '\n';
	}

	

};




int main()
{
	NeuralNetwork network(1, 8, 1);
	double d = network.predict({ 1.0 })[0];
	std::cout << d << '\n';
	
	

	
	




	return 0;
}