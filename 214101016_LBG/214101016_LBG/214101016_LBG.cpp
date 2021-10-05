// 214101016_LBG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "utils.h"		//File containing functions created

int main()
{
	int uSize = 6340, k = 8, p = 12;	//Initialize quantities

	//Create empty matrices for codebook and universe
	double** codebook = new double*[k];
	double** universe = new double*[uSize];

	int i=0,j=0;

	//Initialize matrix and codebook arrays by zero

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

	universeToMatrix(universe, uSize, p);	//Feed Universe.csv in matrix

	double* codebook_arr = universeToArray(universe,uSize,p);	//Make codebook array of size 1 to start
	double epsilon = 0.03;

	codebook = LBG(universe,uSize,codebook_arr,k,p,epsilon);	//Apply LBG

	printf("\nFinal codebook through LBG:\n\n");
	printCodebook(codebook,k,p);								//Print result

	system("PAUSE");											//Pause output in console

	return 0;
}

