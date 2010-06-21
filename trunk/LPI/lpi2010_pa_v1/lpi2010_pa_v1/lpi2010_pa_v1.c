// teste1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"





int main(int argc, char* argv[])
{
	CABECA array_listas[LISTAS];

	//inicializacao do array de estruturas cabeca
	memset(array_listas, 0, sizeof(CABECA) * LISTAS);



	menu();


	system("pause");
	return 0;
}

