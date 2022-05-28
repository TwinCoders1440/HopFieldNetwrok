//In the name of Allah
#pragma once

#include "Utilities.h"
#include <string>
#include <cstdio>

using namespace std;
typedef string String;

class Neuron
{
private:
	bool isNeuronActivated;
	int *weightVector;
	int internalActivation;
	int threshold;

public:
	Neuron(int* weightVectorOfNeuron, int sizeOfWeightVector,
		int thresholdOfNeuron);
	~Neuron(void);

	//................properties
	bool IsNouronActivated();
	int* WeightVector(String getSet, int* value);
	int InternalActivation();
	int Threshold(String getSet, int value);
	//.................End Porperties

	int GetOutputOf(int* inputVector);
};

