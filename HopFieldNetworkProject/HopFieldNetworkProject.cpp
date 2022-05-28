//In the name of Allah
// HopFieldNetworkTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HopFieldNetwork.h"
#include <string>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout<< "In the name of Allah\n"<<
		"This app will recall 1010 0101 1001 0110 patterns correclly!\n\n";

	int patrn1[]= {1, 0, 1, 0};
	int patrn2[]= {0, 1, 0, 1};
	int patrn3[]= {1, 0, 0, 1};
	int patrn4[]= {0, 1, 1, 0};
	int patrn5[]= {1, 1, 1, 0};
	int patrn6[]= {0, 1, 1, 1};
	int *output = new int[4];

	int wt1[] = {0, -5, 4, 4};
	int wt2[] = {-5, 0, 4, 4};
	int wt3[] = {4, 4, 0, -5};
	int wt4[] = {4, 4, -5, 0};
	int *wtsptr[4] = {wt1, wt2, wt3, wt4};

	HopFieldNetwork hopFieldNetwor(4, wtsptr, 4, 0);

	output = hopFieldNetwor.GetOutputVectorOf(patrn1);
	cout<< "pattern1: 1010"<< endl;
	for (int i = 0; i < 4; i++)
	{
		cout<< "Output["<< i<< "] = "<< output[i]<< endl;

	}//end for

	cout<< "\npattern2: 0101"<< endl;
	output = hopFieldNetwor.GetOutputVectorOf(patrn2);
	for (int i = 0; i < 4; i++)
	{
		cout<< "Output["<< i<< "] = "<< output[i]<< endl;

	}//end for

	cout<< "\npattern3: 1001"<< endl;
	output = hopFieldNetwor.GetOutputVectorOf(patrn3);
	for (int i = 0; i < 4; i++)
	{
		cout<< "Output["<< i<< "] = "<< output[i]<< endl;

	}//end for

	cout<< "\npattern4: 0110"<< endl;
	output = hopFieldNetwor.GetOutputVectorOf(patrn4);
	for (int i = 0; i < 4; i++)
	{
		cout<< "Output["<< i<< "] = "<< output[i]<< endl;

	}//end for

	cout<< "\npattern5: 1110"<< endl;
	output = hopFieldNetwor.GetOutputVectorOf(patrn5);
	for (int i = 0; i < 4; i++)
	{
		cout<< "Output["<< i<< "] = "<< output[i]<< endl;

	}//end for

	cout<< "\npattern6: 0111"<< endl;
	output = hopFieldNetwor.GetOutputVectorOf(patrn6);
	for (int i = 0; i < 4; i++)
	{
		cout<< "Output["<< i<< "] = "<< output[i]<< endl;

	}//end for

	cin.getline(new char, 4);

	return 0;

}//end _tmain()

