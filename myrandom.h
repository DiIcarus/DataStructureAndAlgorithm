#pragma once
#include<iostream>
#include<stdio.h>
#include <time.h>
#include <stdlib.h> 
using namespace std;
class myrandom
{
public:
	int MAX = 1000, Limit = MAX;
	myrandom();
	~myrandom();
	//:::::::::::::::BEGIN:MAIN::::::::::::::::
	//int main() {
	//	int A[MAX] = { Limit };
	//	//initArr(A);
	//	//intRand1(A);
	//	intRand2(A);
	//	printArr(A);
	//	return 1;
	//}
	//:::::::::::::::::END:MAIN::::::::::::::::
	void initArr(int a[]) {
		int i = 0;
		while (i != MAX) {
			a[i] = Limit;
			i++;
		}
	}
	int putArray(int a[], int randvalue) {
		int i = 0;
		bool b = true;
		while (b) {
			if (a[i] == Limit) {
				a[i] = randvalue;
				b = false;
			}
			i++;
		}
		return i;
	}
	int testRand(int a[], int randvalue, int maxlim) {
		for (int i = 0; i < maxlim; i++) {
			if (a[i] == randvalue) {
				return 1;
			}
		}
		return 0;
	}
	void intRand(int a[]) {
		srand(time_t(NULL));
		int value;
		do {
			value = rand() % MAX;
			if (!testRand(a, value, MAX)) {
				value = putArray(a, value);
			}
		} while (value != MAX);
	}
	void printArr(int a[]) {
		int i = 0;
		while (i != MAX) {
			cout << a[i] << "\t";
			i++;
		}
	}
};

