// 214101016_Kmeans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "utils.h"			//File where functions are defined

int main()
{
	int uSize = 6340, k = 8, p = 12;			//Initialize values

	//Create matrices for codebook and universe
	double** codebook = new double*[k];
	double** universe = new double*[uSize];

	int i=0,j=0;

	//Initialize codebook and universe matrices with zeros
	for(i=0;i<k;i++)
	{
		codebook[i] = new double[p];
		for(j=0;j<p;j++)
			codebook[i][j] = 0;
	}

	for(i=0;i<uSize;i++)
	{
		universe[i] = new double[p];
		for(j=0;j<p;j++)
			universe[i][j] = 0;
	}

	universeToMatrix(universe, uSize, p);				//Convert Universe.csv to matrix
	codebookInit(universe, uSize, codebook, k, p);		//Initialize codebook using random vectors from universe


	codebook = kmeans(universe,uSize,codebook,k,p);		//Apply K means and create codebook

	printf("The final codebook is:\n\n");
	printCodebook(codebook,k,p);						//Print resultant codebook

	system("PAUSE");									//Pause console to show output

	return 0;
}
