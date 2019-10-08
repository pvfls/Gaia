#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <istream>
#include <iostream>
#include <fstream>
#include <new>
#include <time.h>
#include <locale.h>
#include <stdint.h>
#define TAM 10

using namespace std;

void bubbleSort(int* vetor)
/*Mais simples... compara os elementos em pares e automaticamente troca caso seja necessário, bom para listas pequenas*/
{
    int x, y, aux;

    for(x = 0; x < TAM; x++)
    {
        for(y = x + 1; y < TAM; y++)
        {
            if(vetor[x] > vetor[y])
            {
                aux = vetor[x];
                vetor[x] = vetor[y];
                vetor[y] = aux;
            }

        }
    }
}

void insertionSort(int* vetor)
/*Também bom para listas pequenas, a partir de uma posição, analisa os anteriores a ele um por um para saber se está no
local ideal*/
{
    int i, j, cur;

    for(i = 1; i < TAM; i++)
    {
        cur = vetor[i];
        j = i - 1;

        while(j >= 0 && cur < vetor[j])
        {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = cur;
    }
}

void selectionSort(int* vetor)
/*Bom para listas pequenas, põe os elementos em ordem a medida em que eles são encontrado, percorre a lista muitas vezes*/
{
    int smallest, i, j, aux;

    for(i = 0; i < TAM; i++)
    {
        smallest = i;

        for(j = i + 1; j < TAM; j++)
        {
            if(vetor[j] < vetor[smallest])
            {
                smallest = j;
            }
        }

        if(smallest != i)
        {
            aux = vetor[i];
            vetor[i] = vetor[smallest];
            vetor[smallest] = aux;
        }
    }   
}

void quickSort(int* vetor, int begin, int end)
/*Um dos mais completos, bom com listas grandes, bom quando não se sabe a situação da lista, organiza os elementos da lis
ta em agrupamentos cada vez menores e no final ordena-os "par a par"*/
{
    int left, right, mid, cur, aux;

    left = begin;
    right = end;
    
    mid = (int) ((left + right)/2);
    cur = vetor[mid];

    while(right > left){

        while(vetor[left] < cur)
        {
            left += 1;
        }

        while(vetor[right] > cur)
        {
            right -= 1;
        }

        if(left <= right)
        {
            aux = vetor[left];
            vetor[left] = vetor[right];
            vetor[right] = aux;

            left += 1;
            right -= 1;
        }
    }

    if(begin < right)
    {
        quickSort(vetor, begin, right);
    }

    if(left < end)
    {
        quickSort(vetor, left, end);
    }
}

void shellSort(int* vetor)
/*Bom com listas grandes, compara também elementos que nao estão tão próximos, usa-se uma variável para definir o gap en
tre os elementos da lista a serem comparados e, aos poucos, diminui-se esse gap, até que esteja sendo comparado 1 a 1*/
{

    int i, j, h, atual;

    h = 1;

    while(h < TAM)
    {
        h = 3*h + 1;
    }

    while(h > 1)
    {
        h = h / 3;
        
        for(i = 1; i < TAM; i++)
        {
            atual = vetor[i];
            j = i - h;

            while(j >= 0 && atual < vetor[j])
            {
                vetor[j + h] = vetor[j];
                j -= h;
            }

            vetor[j + h] = atual;
        }
    }
}

void merge(int* vetor, int left, int mid, int right)
/* Junta dois subArrays em um só, função principal para implementação da mergeSort*/
{
    int tamVetorLeft = mid - left + 1;
    int tamVetorRight = right - mid;
    int vetorLeft[tamVetorLeft];
    int vetorRight[tamVetorRight];
    int i, j, k;

    for(i = 0; i < tamVetorLeft ; i++)
    {
        vetorLeft[i] = vetor[left + i];
    }

    for(j = 0; j < tamVetorRight ; j++)
    {
        vetorRight[j] = vetor[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < tamVetorLeft && j < tamVetorRight)
    {
        if(vetorLeft[i] <= vetorRight[j])
        {
            vetor[k] = vetorLeft[i];
            i++;
        }
        else
        {
            vetor[k] = vetorRight[j];
            j++;
        }
        k++;
    }

    while(i < tamVetorLeft)
    {
        vetor[k] = vetorLeft[i];
        i++;
        k++;
    }

    while(j < tamVetorRight)
    {
        vetor[k] = vetorRight[i];
        j++
;        k++;
    }
}

void mergeSort(int* vetor, int left, int right)
/*Dividir para conquistar, separa varios subarrays e alinha-os, depois une os subarrays e alinha-os, fazendo com que
no final exista um unico array com todos os elementos perfeitamente ordenados*/
{
    int mid;

    if(left < right)
    {
        mid = left + ((right - left) / 2);

        mergeSort(vetor, left, mid);

        mergeSort(vetor, mid + 1, right);

        merge(vetor, left, mid, right);
    }
}


int randomNumber(int range)
{

	/*
	-Gera números aleatoriamente
	-Precisa da time.h 
	*/
		
	srand((unsigned)time(NULL));

	// numero apos a porcetagem define o range da aleatoriedade
	int x = rand() % range; // ex entre 0 e 999

	return x;
}

void limpaTela()
{
	/*
	-Limpa a tela do cmd
	-Precisa da stdlib.h
	*/
	system("CLS");
}

void binarySearch(int x[TAM], int valor)
{
    int limiteEsquerda;
    int limiteDireita;
    int cursor, pos;
    bool y;

    limiteEsquerda = 0;
    limiteDireita = TAM - 1;

    while (limiteEsquerda <= limiteDireita)
    {
    cursor = (limiteEsquerda + limiteDireita) / 2;

        if(valor == x[cursor])
        {
            y = 1;
            pos = cursor;
        }

        if(valor > x[cursor])
        {
            limiteEsquerda = cursor + 1;
        }
        else
        {
        limiteDireita = cursor - 1;
        }
    }
    
    if(y)
    {
        cout << "Valor encontrado na pos: " << pos << " do vetor";  
    }
    else
    {
        cout << "Valor nao encontrado no vetor";
    }
}