/****************************************
Name:Carter Brady
Section: CSC 2400-004
Due date: 10/27/2023
Instructor: Cristina Radian
top file: main.cpp
****************************************/

#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

//shell sort algorithm splits the array into smaller sub arrays then applies insertion sort using nested for loops
//inputs: the array and the size of the array
//outputs: function has void return but arrays are passed through so the sorted array is updated
void ShellSort(int Array[], int n)
{
    //this for loop divides the array into sections
    for(int i = n/2; i > 0; i /= 2)
    {
        //this loop does an insertion sort using the sections 
        for(int j = i; j < n; j++)
        {
            //temporarily stores values of Array at j
            int temp = Array[j];

            int k;
            for(k = j; k >= i && Array[k-i] > temp;k-=i)
            {
                Array[k] = Array[k-i];
            }
            //puts value of array at j into array at k
            Array[k] = temp;
        };
    };
};

//insertion sort compares an item in the array to the value to its left then swaps if less than
//inputs: the array and the size of the array
//outputs: function has void return but arrays are passed through so the sorted array is updated
void InsertionSort(int Array[], int n)
{
    int temp;
    int m;

    //itterates through the array and swaps when needed
    for(int i = 1; i<n; i++)
    {
        temp = Array[i];
        m = i-1;

        //while the value at m in the array is greater than the temp value it is swapped with m+1
        //m is then decremented until the Array at m is less than or equal to temp
        while(m >= 0 && Array[m] > temp)
        {
            Array[m+1] = Array[m];
            --m;
        };
        //array at m+1 is then updated with the temp value
        Array[m+1] = temp; 
    };
};

//selection sort goes through the array and finds the minimum value then swaps the 
//minimum with the current index
//inputs: the array and the size of the array
//outputs: function has void return but arrays are passed through so the sorted array is updated
void SelectionSort(int Array[], int n)
{
    int minIndx;

    //itterates through the array
    for(int i = 0; i < n-1; i++)
    {
        //minimum is set to i at beginning of loop each time
        minIndx = i;

        //finds the minimum
        for(int j = i+1; j < n; j++)
        {
            if(Array[j] < Array[minIndx])
            {
                minIndx = j;
            }
        };

        //unless the minIndx is i it swaps minimum with index
        if(minIndx != i)
        {
            int temp = Array[minIndx];
            Array[minIndx] = Array[i];
            Array[i] = temp;
        };

    };
};

//bubble sort itterates through the array and compares the two values next to each other
//each itteration has to search one less element than the last
//inputs: the array and the size of the array
//outputs: function has void return but arrays are passed through so the sorted array is updated
void BubbleSort(int Array[], int n)
{
    //itterates through the array 
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            //swaps the elements if needed
            if(Array[j] > Array[j+1])
            {
                int temp = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = temp;
            };
        };
    };
};


//the array generation function takes in the size of the array and rather you want acending
//, decending, or completly random
//inputs:array being filled,the size of the array n, and arrType is which type of array to create
//output: no output the array is updated though
void GenerateArray(int Array[],int n,int arrType)
{
    switch(arrType)
    {
        //this case creates random array
        case 0:
            for (int i = 0; i < n; i++)
            {
                Array[i] = rand();
            };
            break;


        //this case creates increasing array
        case 1:
            for (int i = 0; i < n; i++)
            {
                //semi random but each element has a range it can be so that they increase
                Array[i] = (rand()%20)+(20*i);
            };
            break;

        //this case creates decreasing array
        case 2:
            for (int i = 0; i < n; i++)
            {
                //semi random but each element has a range it can be so that they decrease
                Array[i] = (rand()%20)+(20*(n-i));
            };
            break;
        default:
            //tell them to restart program and be better
            cout << "You should not be seeing this please rerun the program sorry!" << endl;
            break;        
    };
};

int main()
{
    //ask user for power of 10 that they want for the size of the arrays
    //make arrays
    //prompt user to press enter to sort the arrays 
    //keep a temp array that can hold the original value of the array while each function runs
    int nSize;
    int arrSize;

    //setup for output file
    ofstream outFS;
    outFS.open("output.txt", fstream::app);

    cout << "Please enter the multiple of 10 you want for the array size." << endl;
    cout << "Multiple of 10: ";
    cin >> nSize;
    cout << endl;
    arrSize = 10*nSize;  //the array size is decided by taking 10 to the power of input

    //creates all of the arrays then generates values to fill all of them
    int *arrRand1 = new int[arrSize];
    int *arrRand2 = new int[arrSize];
    int *arrRand3 = new int[arrSize];
    int *arrRand4 = new int[arrSize];
    int *arrRand5 = new int[arrSize];
    int *arrUp1 = new int[arrSize];
    int *arrUp2 = new int[arrSize];
    int *arrUp3 = new int[arrSize];
    int *arrUp4 = new int[arrSize];
    int *arrUp5 = new int[arrSize];
    int *arrDown1 = new int[arrSize];
    int *arrDown2 = new int[arrSize];
    int *arrDown3 = new int[arrSize];
    int *arrDown4 = new int[arrSize];
    int *arrDown5 = new int[arrSize];
    GenerateArray(arrRand1, arrSize, 0);
    GenerateArray(arrRand2, arrSize, 0);
    GenerateArray(arrRand3, arrSize, 0);
    GenerateArray(arrRand4, arrSize, 0);
    GenerateArray(arrRand5, arrSize, 0);
    GenerateArray(arrUp1, arrSize, 1);
    GenerateArray(arrUp2, arrSize, 1);
    GenerateArray(arrUp3, arrSize, 1);
    GenerateArray(arrUp4, arrSize, 1);
    GenerateArray(arrUp5, arrSize, 1);
    GenerateArray(arrDown1, arrSize, 2);
    GenerateArray(arrDown2, arrSize, 2);
    GenerateArray(arrDown3, arrSize, 2);
    GenerateArray(arrDown4, arrSize, 2);
    GenerateArray(arrDown5, arrSize, 2);

    //creating temp arrays that way the same arrays can be sent to all functions
    int* tempRand1 = new int[arrSize];
    int* tempRand2 = new int[arrSize];
    int* tempRand3 = new int[arrSize];
    int* tempRand4 = new int[arrSize];
    int* tempRand5 = new int[arrSize];
    int* tempUp1 = new int[arrSize];
    int* tempUp2 = new int[arrSize];
    int* tempUp3 = new int[arrSize];
    int* tempUp4 = new int[arrSize];
    int* tempUp5 = new int[arrSize];
    int* tempDown1 = new int[arrSize];
    int* tempDown2 = new int[arrSize];
    int* tempDown3 = new int[arrSize];
    int* tempDown4 = new int[arrSize];
    int* tempDown5 = new int[arrSize];

    //fills each array with the values from the dynamic array
    for(int i = 0; i<arrSize; i++)
    {
        tempRand1[i] = arrRand1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand2[i] = arrRand2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand3[i] = arrRand3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand4[i] = arrRand4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand5[i] = arrRand5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp1[i] = arrUp1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp2[i] = arrUp2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp3[i] = arrUp3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp4[i] = arrUp4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp5[i] = arrUp5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown1[i] = arrDown1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown2[i] = arrDown2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown3[i] = arrDown3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown4[i] = arrDown4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown5[i] = arrDown5[i];
    }


    //runs all arrays through each function
    //takes the time before the first sort and then takes the time after then 
    //uses the before and after to calculate how long it took to run
    //originally tried using C time but seconds not precise enough
    // so had to figure out chrono library
    auto start = high_resolution_clock::now();
    ShellSort(tempRand1, arrSize);
    ShellSort(tempRand2, arrSize);
    ShellSort(tempRand3, arrSize);
    ShellSort(tempRand4, arrSize);
    ShellSort(tempRand5, arrSize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    outFS << "Shell sort with random array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    ShellSort(tempUp1, arrSize);
    ShellSort(tempUp2, arrSize);
    ShellSort(tempUp3, arrSize);
    ShellSort(tempUp4, arrSize);
    ShellSort(tempUp5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Shell sort with increasing array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    ShellSort(tempDown1, arrSize);
    ShellSort(tempDown2, arrSize);
    ShellSort(tempDown3, arrSize);
    ShellSort(tempDown4, arrSize);
    ShellSort(tempDown5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Shell sort with decreasing array took " << duration.count() << " milliseconds." << endl << endl;

    //resetting temp arrays that way the same arrays can be sent to all functions
    for(int i = 0; i<arrSize; i++)
    {
        tempRand1[i] = arrRand1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand2[i] = arrRand2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand3[i] = arrRand3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand4[i] = arrRand4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand5[i] = arrRand5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp1[i] = arrUp1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp2[i] = arrUp2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp3[i] = arrUp3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp4[i] = arrUp4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp5[i] = arrUp5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown1[i] = arrDown1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown2[i] = arrDown2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown3[i] = arrDown3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown4[i] = arrDown4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown5[i] = arrDown5[i];
    }


    start = high_resolution_clock::now();
    InsertionSort(tempRand1, arrSize);
    InsertionSort(tempRand2, arrSize);
    InsertionSort(tempRand3, arrSize);
    InsertionSort(tempRand4, arrSize);
    InsertionSort(tempRand5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);


    outFS << "Insertion sort with random array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    InsertionSort(tempUp1, arrSize);
    InsertionSort(tempUp2, arrSize);
    InsertionSort(tempUp3, arrSize);
    InsertionSort(tempUp4, arrSize);
    InsertionSort(tempUp5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);


    outFS << "Insertion sort with increasing array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    InsertionSort(tempDown1, arrSize);
    InsertionSort(tempDown2, arrSize);
    InsertionSort(tempDown3, arrSize);
    InsertionSort(tempDown4, arrSize);
    InsertionSort(tempDown5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);


    outFS << "Insertion sort with decreasing array took " << duration.count() << " milliseconds." << endl << endl;

    //resetting temp arrays that way the same arrays can be sent to all functions
    for(int i = 0; i<arrSize; i++)
    {
        tempRand1[i] = arrRand1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand2[i] = arrRand2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand3[i] = arrRand3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand4[i] = arrRand4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand5[i] = arrRand5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp1[i] = arrUp1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp2[i] = arrUp2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp3[i] = arrUp3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp4[i] = arrUp4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp5[i] = arrUp5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown1[i] = arrDown1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown2[i] = arrDown2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown3[i] = arrDown3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown4[i] = arrDown4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown5[i] = arrDown5[i];
    }

    //Selection sort test
    start = high_resolution_clock::now();
    SelectionSort(tempRand1, arrSize);
    SelectionSort(tempRand2, arrSize);
    SelectionSort(tempRand3, arrSize);
    SelectionSort(tempRand4, arrSize);
    SelectionSort(tempRand5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Selection sort with random array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    SelectionSort(tempUp1, arrSize);
    SelectionSort(tempUp2, arrSize);
    SelectionSort(tempUp3, arrSize);
    SelectionSort(tempUp4, arrSize);
    SelectionSort(tempUp5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Selection sort with increasing array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    SelectionSort(tempDown1, arrSize);
    SelectionSort(tempDown2, arrSize);
    SelectionSort(tempDown3, arrSize);
    SelectionSort(tempDown4, arrSize);
    SelectionSort(tempDown5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Selection sort with decreasing array took " << duration.count() << " milliseconds." << endl << endl;

    //resetting temp arrays that way the same arrays can be sent to all functions
    for(int i = 0; i<arrSize; i++)
    {
        tempRand1[i] = arrRand1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand2[i] = arrRand2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand3[i] = arrRand3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand4[i] = arrRand4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempRand5[i] = arrRand5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp1[i] = arrUp1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp2[i] = arrUp2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp3[i] = arrUp3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp4[i] = arrUp4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempUp5[i] = arrUp5[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown1[i] = arrDown1[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown2[i] = arrDown2[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown3[i] = arrDown3[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown4[i] = arrDown4[i];
    }
    for(int i = 0; i<arrSize; i++)
    {
        tempDown5[i] = arrDown5[i];
    }

    //Bubble sort test
    start = high_resolution_clock::now();
    BubbleSort(tempRand1, arrSize);
    BubbleSort(tempRand2, arrSize);
    BubbleSort(tempRand3, arrSize);
    BubbleSort(tempRand4, arrSize);
    BubbleSort(tempRand5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Bubble sort with random array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    BubbleSort(tempUp1, arrSize);
    BubbleSort(tempUp2, arrSize);
    BubbleSort(tempUp3, arrSize);
    BubbleSort(tempUp4, arrSize);
    BubbleSort(tempUp5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Bubble sort with increasing array took " << duration.count() << " milliseconds." << endl;

    start = high_resolution_clock::now();
    BubbleSort(tempDown1, arrSize);
    BubbleSort(tempDown2, arrSize);
    BubbleSort(tempDown3, arrSize);
    BubbleSort(tempDown4, arrSize);
    BubbleSort(tempDown5, arrSize);
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    outFS << "Bubble sort with decreasing array took " << duration.count() << " milliseconds." << endl << endl;
    outFS << endl;
    outFS.close();



    //deallocates arrays
    delete[] arrRand1;
    delete[] arrRand2;
    delete[] arrRand3;
    delete[] arrRand4;
    delete[] arrRand5;
    delete[] arrUp1;
    delete[] arrUp2;
    delete[] arrUp3;
    delete[] arrUp4;
    delete[] arrUp5;
    delete[] arrDown1;
    delete[] arrDown2;
    delete[] arrDown3;
    delete[] arrDown4;
    delete[] arrDown5;
    delete[] tempRand1;
    delete[] tempRand2;
    delete[] tempRand3;
    delete[] tempRand4;
    delete[] tempRand5;
    delete[] tempUp1;
    delete[] tempUp2;
    delete[] tempUp3;
    delete[] tempUp4;
    delete[] tempUp5;
    delete[] tempDown1;
    delete[] tempDown2;
    delete[] tempDown3;
    delete[] tempDown4;
    delete[] tempDown5;

};