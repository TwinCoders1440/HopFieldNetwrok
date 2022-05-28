//In the name of Allah
#include "stdafx.h"
#include "Neuron.h"


int GetInternalActivation(int *weightVector, int *inputVector);

Neuron::Neuron(int* weightVectorOfNeuron, int sizeOfWeightVector,
		int thresholdOfNeuron)
{
	weightVector = new int[sizeOfWeightVector];

	WeightVector("set", weightVectorOfNeuron);
	Threshold("set", thresholdOfNeuron);

}//end Constructor
Neuron::~Neuron(void)
{
}

//................properties
bool Neuron::IsNouronActivated()
{
	return isNeuronActivated;

}//end IsNouronActivated
int* Neuron::WeightVector(String getSet, int* value)
{
	if (getSet == "get")
	{
		int *weightVector2 = new int[sizeof(weightVector)];
		for (int i = 0; i < sizeof(weightVector); i++)
			weightVector2[i] = weightVector[i];

		return weightVector2;

	}//end get if
	else if (getSet == "set")
	{
		delete weightVector;
		weightVector = new int[sizeof(value)];

		for (int i = 0; i < sizeof(weightVector); i++)
			weightVector[i] = value[i];

	}//end set if
	else
		fatal("getSet in WeightVector must be \"set\" or \"get\"");

}//end WeightVector
int Neuron::InternalActivation()
{
	return internalActivation;

}//end InternalActivation
int Neuron::Threshold(String getSet, int value)
{
	if (getSet == "get")
	{
		return threshold;

	}//end get if
	else if (getSet == "set")
	{
		threshold = value;

	}//end set if
	else
		fatal("getSet in Threshold must be \"set\" or \"get\"");

}//end Threshold
//.................End Porperties

//.........................................................Methods()
int Neuron::GetOutputOf(int* inputVector)
	{
		internalActivation = GetInternalActivation(weightVector, inputVector);

		if (internalActivation >= threshold)
		{
			isNeuronActivated = true;
			return 1;
		}//end if
		else
		{
			isNeuronActivated = false;
			return 0;
		}//end else

	}//end GetOutputOf(input)

//.........................................................End Methods()

int GetInternalActivation(int *weightVector, int *inputVector)
{
	int internalActivation = 0;
	int sizeOfInput = sizeof(inputVector);

	if (sizeOfInput != sizeof(weightVector))
		fatal("Number of input components is not equal to"\
		" that in weightVector of neuron");

	for (int i = 0; i < sizeOfInput; i++)
	{
		internalActivation += inputVector[i] * weightVector[i];

	}//end for

	return internalActivation;

}//end GetInternalActivation(*weightVector, *input)