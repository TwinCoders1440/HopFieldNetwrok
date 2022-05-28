//In the name of Allah

#include "stdafx.h"
#include "HopFieldNetwork.h"


HopFieldNetwork::HopFieldNetwork(int neuronNumber, int **neuronsWeightVectors,
								 int weightVectorSize, int neuronsThreshold)
{
	numberOfNeurons = neuronNumber;
	neurons = new Neuron*[numberOfNeurons];

	WeightVectorsOfneurons("set", neuronsWeightVectors);
	sizeOfAnyWeightVector = weightVectorSize;

	for (int i = 0; i < numberOfNeurons; i++)
	{
		neurons[i] = new Neuron(weightVectorsOfNeurons[i], weightVectorSize, neuronsThreshold);

	}//end for

	lastOutputVector = new int[sizeOfAnyWeightVector];

}//end Cosntrocot()
HopFieldNetwork::~HopFieldNetwork(void)
{
}

//.......................................................Properties
int HopFieldNetwork::NumberOfNeurons()
{
	return numberOfNeurons;

}//end NumberOfNeurons
int **HopFieldNetwork::WeightVectorsOfneurons(String setGet, int** value)
{
	if (setGet == "get")
	{
		int **weightVectorsOfneurons2 =
			new int*[sizeOfAnyWeightVector];
		for (int i = 0; i < sizeOfAnyWeightVector; i++)
		{
			weightVectorsOfneurons2[i] = new int[sizeOfAnyWeightVector];
			for (int j = 0; j < sizeOfAnyWeightVector; j++)
				weightVectorsOfneurons2[i][j] = weightVectorsOfNeurons[i][j];
		}//end i for

		return weightVectorsOfneurons2;
	}//end if
	else if (setGet == "set")
	{
		int sizeOfWeightVectors = sizeof value;
		delete weightVectorsOfNeurons;
		weightVectorsOfNeurons = new int*[sizeOfWeightVectors];

		for (int i = 0; i < sizeOfWeightVectors; i++)
			weightVectorsOfNeurons[i] = value[i];
	}//end set if
	else
		fatal("setGet in WeightVectorsOfneurons must be \"set\" or \"get\"");

	return value;
}//end WeightVectorsOfneurons
int *HopFieldNetwork::LastOutputVector()
{
	int *lastOutputVector2 = new int[sizeOfAnyWeightVector];
	for (int i = 0; i < sizeOfAnyWeightVector; i++)
		lastOutputVector2[i] = lastOutputVector[i];

	return lastOutputVector2;

}//end lastOutputVector
//.......................................................End Properties

//.......................................................Methods()
int *HopFieldNetwork::GetOutputVectorOf(int *inputVector)
{
	int f = sizeof(inputVector);
	if (sizeof (inputVector) != sizeOfAnyWeightVector)
		fatal("Input vector size must be equal to size of weight vector");

	int *innerInputVector = new int[sizeOfAnyWeightVector];
	String stableRecallSaver;
	String stableRecallMatcher;

	stableRecallMatcher.append(sizeOfAnyWeightVector, '1');
	for (int i = 0; i < sizeOfAnyWeightVector; i++)
		innerInputVector[i] = inputVector[i];
	for (int i = 0; i < sizeOfAnyWeightVector; )
	{
		lastOutputVector[i] = neurons[i]->GetOutputOf(innerInputVector);
		cout<< "Internal activation of neuron"<< i<< " = "<<
			neurons[i]->InternalActivation()<< endl;
		if (lastOutputVector[i] == innerInputVector[i])
			stableRecallSaver.append("1");
		else
			stableRecallSaver.append("0");

		innerInputVector[i] = lastOutputVector[i];

		i++;
		if (i == sizeOfAnyWeightVector)
		{
			if (stableRecallSaver == stableRecallMatcher)
				break;
		}//end if
	}//end for

	int *lastOutputVector2 = new int[sizeOfAnyWeightVector];
	for (int i = 0; i < sizeOfAnyWeightVector; i++)
		lastOutputVector2[i] = lastOutputVector[i];
	return lastOutputVector2;

}//end GetOutputVectorOf(int *inputVector)
//.......................................................End Methods()

/*int *HopFieldNetwork::GetOutputVectorOf(int *inputVector)
{
	if (sizeof (inputVector) != sizeOfAnyWeightVector)
		fatal("Input vector size must be equal to size of weight vector");

	for (int i = 0; i < sizeOfAnyWeightVector; i++)
	{
			lastOutputVector[i] = neurons[i]->GetOutputOf(inputVector);
			cout<< "Internal activation of neuron"<< i<< " = "<<
				neurons[i]->InternalActivation()<< endl;
	}//end for

	int *lastOutputVector2 = new int[sizeOfAnyWeightVector];
	for (int i = 0; i < sizeOfAnyWeightVector; i++)
		lastOutputVector2[i] = lastOutputVector[i];
	return lastOutputVector2;

}//end GetOutputVectorOf(int *inputVector)*/