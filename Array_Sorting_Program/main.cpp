/* Ramzi Yakan
   Array Sorting Program
   Sorts an array by using either the bubble sort, insertion sort, or selection sort method.
   Feb 2 2018
   */

#include <cstdlib>
#include <iostream>

using namespace std;

void createArray(int bubbleSortArray [10]);
int chooseSortingMethod();
void bubbleSort(int listArray[]);
void insertionSort(int listArray[]);
void selectionSort(int listArray[]);
bool checkIfSorted (int listArray[]);
void displayArray (int listArray[]);

int main(int argc, char *argv[])
{
    int Array [10];
    int option=1;
    createArray(Array);
    cout<<endl;
    option = chooseSortingMethod();
    while (checkIfSorted(Array)==0)
    {
        switch(option)
        {
            case 1:
            {
                bubbleSort(Array);
            }
            case 2:
            {
                insertionSort(Array);
            }
            case 3:
            {
                selectionSort(Array);
            }
        }
    }
    displayArray(Array);
}

void createArray(int a[10])
{
    cout<<"Please enter 10 values."<<endl;
    for (int j=0; j<10; j++)
        {
             cin>>a[j];
        }
    return;
}

int chooseSortingMethod()
{
    int choice;
    cout<<"How do you want to sort your created array?"<<endl;
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cin>>choice;
    while ((choice!=1) and (choice!=2) and (choice!=3))
    {
        cout<<"Please give a valid response."<<endl;
        cin>>choice;
    }
    return choice;
}

void bubbleSort(int listArray[])
{
    int buffer = 0;
    for (int i = 0; i<10; i++)
    {
            if (listArray[i] > listArray[i+1])
            {
                buffer=listArray[i];
                listArray[i]=listArray[i+1];
                listArray[i+1]=buffer;
                displayArray(listArray);
                cout<<endl;
            }
    }
    return;
}

void insertionSort(int listArray[])
{
    int buffer = 0;
    for (int i = 0; i<10; i++)
    {
            for (int j=i-1; j>=0; j--)
                if ((listArray[j+1] < listArray[j]))
                {
                    buffer=listArray[j+1];
                    listArray[j+1]=listArray[j];
                    listArray[j]=buffer;
                    displayArray(listArray);
                    cout<<endl;
                }
    }
    return;
}

void selectionSort(int listArray[])
{
    int buffer = 0;
    for (int i = 0; i<10; i++)
    {
            int lowestNumber = listArray[i];
            int lowestPosition = i;
            for (int j = i; j<10; j++)
            {
                if (listArray[j] < lowestNumber)
                {
                    lowestNumber = listArray[j];
                    lowestPosition = j;
                }
            }
            listArray[lowestPosition] = listArray[i];
            listArray[i] = lowestNumber;
            displayArray(listArray);
            cout<<endl;
    }
    return;
}

bool checkIfSorted (int listArray[])
{
    for (int i=0; i<10; i++)
    {
        if (listArray[i] > listArray[i+1])
        {
                return 0;
        }
    }
    return 1;
}

void displayArray (int listArray[])
{
    for (int i=0; i<10; i++)
    {
        cout<<listArray[i]<<" ";
    }
    return;
}


