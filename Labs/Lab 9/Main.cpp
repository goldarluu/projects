/*
	Goldar Luu 

	April 14, 2021

	CS A250 
	Lab 9 Binary Search 
*/

#include <iostream> 
#include <algorithm> 
#include <cmath> 

using namespace std;

int iterativeSearch(int arr[], int search, int len);
int iterativeBinarySearch(int arr[], int search, int left, int right);
int recursiveBinarySearch(int arr[], int search, int left, int right, int& numOfComp);

int main()
{
    cout << "hello " << endl;;
    int arr[100];
    int len = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < len; i++) {
        arr[i] = i + 1;
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    int search = 1, left = 0, right = len - 1, numOfComp = 0;
    cout << "Element to Search: 1" << endl;
    cout << "   Iterative Search Number Of Comaprison: "
        << iterativeSearch(arr, search, len) << endl
        << "   Iterative Binary Search Number of Comparison: "
        << iterativeBinarySearch(arr, search, left, right) << endl
        << "   Recursive Binary Search Number of Comparison: "
        << recursiveBinarySearch(arr, search, left, right, numOfComp)
        << endl << endl << endl;


    search = 50, numOfComp = 0;
    cout << "Element to Search: 50" << endl
        << "   Iterative Search Number Of Comaprison: "
        << iterativeSearch(arr, search, len) << endl
        << "   Iterative Binary Search Number of Comparison: "
        << iterativeBinarySearch(arr, search, left, right) << endl
        << "   Recursive Binary Search Number of Comparison: "
        << recursiveBinarySearch(arr, search, left, right, numOfComp)
        << endl << endl << endl;

    search = 101;
    cout << "Element to Search: 101" << endl
        << "   Iterative Search Number Of Comparison: ";
    (iterativeSearch(arr, search, len) != -1) ? cout
        << iterativeSearch(arr, search, len) << endl :
        cout << "Element not Found" << endl;

    cout << "   Iterative Binary Search Number of Comparison: ";
    (!iterativeBinarySearch(arr, search, left, right)) ? cout
        << iterativeBinarySearch(arr, search, left, right) << endl
        : cout << "Element not Found" << endl;
    cout << "   Recursive Binary Search Number of Comparison: ";
    (!recursiveBinarySearch(arr, search, left, right, numOfComp))
        ? cout << recursiveBinarySearch(arr, search, left, right, numOfComp) :
        cout << "Element not Found" << endl;
    cout << endl << endl;

    return -1;
}

int iterativeSearch(int arr[], int search, int len)
{
    int numOfComp = 0;
    for (int i = 0; i < len; i++)
    {
        if (search == arr[i])
        {
            numOfComp++;
            return numOfComp;
        }
        else
            numOfComp++;
    }
    return -1;
}

int iterativeBinarySearch(int arr[], int search, int left, int right)
{
    int numOfComp = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        numOfComp++;
        if (arr[mid] == search) return numOfComp;
        else if (arr[mid] < search)
        {
            left = mid + 1;
            ++numOfComp;
        }
        else
        {
            right = mid - 1;
            ++numOfComp;
        }
    }
    if (left > right)
        return -1;
}

int recursiveBinarySearch(int arr[], int search, int left, int right, 
    int& numOfComp)
{
    // base case 
    numOfComp++;
    if (numOfComp < 15)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search)
        {
            return numOfComp;
            /*numOfComp = 0;*/
        }
        else if (arr[mid] < search)
        {
            numOfComp++;
            return (recursiveBinarySearch(arr, search, mid + 1,
                    right, numOfComp));
        }
        else
        {
            numOfComp++;
            return (recursiveBinarySearch(arr, search, left, mid - 1, 
                    numOfComp));
        }
    }
    else return -1;
}
