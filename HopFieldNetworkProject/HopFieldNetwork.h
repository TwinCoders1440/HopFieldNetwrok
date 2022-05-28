//In the name of Allah
#pragma once

#include "Neuron.h"
#include <string>
#include <iostream>

using namespace std;

class HopFieldNetwork
{
private:
	int numberOfNeurons;
	Neuron **neurons;
	int **weightVectorsOfNeurons;
	int sizeOfAnyWeightVector;
	int *lastOutputVector;

public:
	HopFieldNetwork(int neuronNumber, int **neuronsWeightVectors,
		int weightVectorSize, int neuronsThreshold);
	~HopFieldNetwork(void);

	//.......................................................Properties
	int NumberOfNeurons();
	int **WeightVectorsOfneurons(String setGet, int** value);
	int *LastOutputVector();
	//.......................................................End Properties

	//.......................................................Methods()
	int *GetOutputVectorOf(int *inputVector);
	//.......................................................End Methods()

};

