// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

void createArray(std::vector<int>& bubbleSortArray);
int chooseSortingMethod();
void bubbleSort(std::vector<int>& listArray);
void insertionSort(std::vector<int>& listArray);
void selectionSort(std::vector<int>& listArray);
bool checkIfSorted(const std::vector<int>& listArray);
void displayArray(std::vector<int>& listArray);

int main(int argc, char *argv[])
{
	// Holds the list of numbers that the user wants to sort
	auto numberList = std::vector<int>();
	createArray(numberList);

	cout << endl;
	while (checkIfSorted(numberList) ==0)
	{
		switch (chooseSortingMethod())
		{
		case 1:
		{
			bubbleSort(numberList);
		}
		case 2:
		{
			insertionSort(numberList);
		}
		case 3:
		{
			selectionSort(numberList);
		}
		}
	}
	displayArray(numberList);
}

void createArray(std::vector<int>& numberList)
{
	auto numberInput = 0;
	auto listLength = 0;
	cout << "How many values would you like to enter?" << endl;
	cin >> listLength;

	// Make the numberlist the size of number so that it doesn't have to keep expanding
	numberList.reserve(listLength);
	std::cout << "Enter the values" << endl;
	for (auto j = 0; j<listLength; j++)
	{
		cin >> numberInput;
		numberList.emplace_back(numberInput);
	}
	return;
}

int chooseSortingMethod()
{
	int choice;
	cout << "How do you want to sort your created array?" << endl;
	cout << "1. Bubble Sort" << endl;
	cout << "2. Insertion Sort" << endl;
	cout << "3. Selection Sort" << endl;
	cin >> choice;
	while ((choice != 1) && (choice != 2) && (choice != 3))
	{
		cout << "Please give a valid response." << endl;
		cin >> choice;
	}
	return choice;
}

void bubbleSort(std::vector<int>& numberList)
{
	int buffer = 0;
	for (auto i = 0; i< (numberList.size()-1) ; i++)
	{
		if (numberList.at(i) > numberList.at(i + 1))
		{
			buffer = numberList.at(i);
			numberList.at(i) = numberList.at(i + 1);
			numberList.at(i + 1) = buffer;
			displayArray(numberList);
			cout << endl;
		}
	}
	return;
}

void insertionSort(std::vector<int>& numberList)
{
	int buffer = 0;
	for (auto i = 0; i<numberList.size(); i++)
	{
		for (auto j = i - 1; j >= 0; j--)
			if ((numberList.at(j + 1) < numberList.at(j)))
			{
				buffer = numberList[j + 1];
				numberList.at(j + 1) = numberList.at(j);
				numberList.at(j) = buffer;
				displayArray(numberList);
				cout << endl;
			}
	}
	return;
}

void selectionSort(std::vector<int>& numberList)
{
	int buffer = 0;
	for (auto i = 0; i<numberList.size(); i++)
	{
		int lowestNumber = numberList.at(i);
		int lowestPosition = i;
		for (auto j = i; j<numberList.size(); j++)
		{
			if (numberList.at(j) < lowestNumber)
			{
				lowestNumber = numberList.at(j);
				lowestPosition = j;
			}
		}
		numberList.at(lowestPosition) = numberList.at(i);
		numberList.at(i) = lowestNumber;
		displayArray(numberList);
		cout << endl;
	}
	return;
}

bool checkIfSorted(const std::vector<int>& numberList)
{
	for (auto i = 0; i < (numberList.size()-1); i++)
	{
		if (numberList.at(i) > numberList.at(i + 1))
		{
			return 0;
		}
	}
	return 1;
}

void displayArray(std::vector<int>& numberList)
{
	for (auto i = 0; i<numberList.size(); i++)
	{
		cout << numberList.at(i) << " ";
	}
	return;
}
