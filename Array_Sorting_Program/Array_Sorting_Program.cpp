/* Ramzi Yakan
   Array Sorting Program
   Sorts an array by using either the bubble sort, insertion sort, or selection sort method.
   Feb 15 2018
   */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

void initRandomArray(int listArray[], int sizeOfArray);
int chooseSortingMethod();
void bubbleSort(int listArray[], int sizeOfArray);
void insertionSort(int listArray[], int sizeOfArray);
void selectionSort(int listArray[], int sizeOfArray);
bool existsInArray(int listArray[], int value, int range);
void displayArray(int listArray[], int sizeOfArray);

int main(int argc, char *argv[])
{
    int arraySize = 0;
    cout<<"Please enter the size of your array."<<endl;
    cin>>arraySize;
    int Array [arraySize] = {arraySize+1};
    initRandomArray(Array, arraySize);
    cout<<endl;
    cout<<"Your Array: ";
    displayArray(Array, arraySize);
    cout<<endl<<endl;
    int option = chooseSortingMethod();
    cout<<endl;
    std::clock_t start;
    start = std::clock();
    switch(option)
    {
        case 1:
        {
            bubbleSort(Array, arraySize);
            break;
        }
        case 2:
        {
            insertionSort(Array, arraySize);
            break;
        }
        case 3:
        {
            selectionSort(Array, arraySize);
            break;
        }
    }
    displayArray(Array, arraySize);
    cout<<endl;
    int endt = std::clock();
    int duration = endt - start;
    cout<<endl<<"Your array was sorted in "<<duration<<" milliseconds."<<endl<<endl;
}

void initRandomArray(int listArray[], int sizeOfArray)
{
    for (int i = 0; i<sizeOfArray; i++)
    {
        while (true)
        {
            int val = rand()%sizeOfArray;
            if (existsInArray(listArray, val, i))
            {
                val = rand()%sizeOfArray;
            }
            else
            {
                listArray[i] = val;
                break;
            }
        }
    }
}

int chooseSortingMethod()
{
    int choice;
    cout<<"How do you want to sort your array?"<<endl;
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cin>>choice;
    while ((choice != 1) and (choice != 2) and (choice != 3))
    {
        cout<<"Please give a valid response."<<endl;
        cin>>choice;
    }
    return choice;
}

void bubbleSort(int listArray[], int sizeOfArray)
{
    int buffer = 0;
    int maxNumber = sizeOfArray-1;
    for (int j = maxNumber; j>=1; j--)
    {
        cout<<"*"<<endl;
        displayArray(listArray, sizeOfArray);
        cout<<endl;
        for (int i = 0; i<j; i++)
        {
            for (int k = 0; k <= i; k++)
            {
                cout << "  ";
            }
            cout<<"*"<<endl;
            if (listArray[i] > listArray[i+1])
            {
                buffer = listArray[i];
                listArray[i] = listArray[i+1];
                listArray[i+1] = buffer;
            }
            displayArray(listArray, sizeOfArray);
            cout<<endl;
       }
        cout<<endl<<endl;

    }

    return;
}

void insertionSort(int listArray[], int sizeOfArray)
{
    int buffer = 0;
    for (int i = 0; i<sizeOfArray; i++)
    {
            for (int j = i-1; j >= 0; j--)
            {
                if ((listArray[j+1] < listArray[j]))
                {
                    buffer = listArray[j+1];
                    listArray[j+1] = listArray[j];
                    listArray[j] = buffer;
                    displayArray(listArray, sizeOfArray);
                    cout<<endl<<endl;
                }
            }

    }
    return;
}

void selectionSort(int listArray[], int sizeOfArray)
{
    int buffer = 0;
    for (int i = 0; i<sizeOfArray; i++)
    {
            int lowestNumber = listArray[i];
            int lowestPosition = i;
            for (int j = i; j<sizeOfArray; j++)
            {
                if (listArray[j] < lowestNumber)
                {
                    lowestNumber = listArray[j];
                    lowestPosition = j;
                }
            }
            listArray[lowestPosition] = listArray[i];
            listArray[i] = lowestNumber;
            displayArray(listArray, sizeOfArray);
            cout<<endl<<endl;
    }
    return;
}

bool existsInArray(int listArray[], int value, int range)
{
    for (int i = 0; i < range; i++) {
        if (value == listArray[i])
            return true;
    }
    return false;
}

void displayArray (int listArray[], int sizeOfArray)
{
    for (int i = 0; i<sizeOfArray; i++)
    {
        cout<<listArray[i]<<" ";
    }
    return;
}
