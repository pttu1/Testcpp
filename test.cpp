#include <iostream>

using namespace std;

/*Given a set of N nuts of different sizes and N bolts of different sizes. 
There is a one-one mapping between the nuts and bolts. Match nut and bolts efficiently.*/

/*Constraints: 1 <= N <= 9

Comparison of a nut to another nut or a bold to another bolt is not allowed. 
This means nut cannot only be compared bolt and bolt with nut to see which is smaller or 
larger.

The elements should follow the following order ! # $ % & * @ ^ ~ */

/* Example 1: N = 5
            nuts[] = {@, %, $, #, ^}
            bolts[] = {%, @, #, $, ^}

            Output:
                #, $, %, @, ^
                #, $, %, @, ^*/
            
//Expected Time Complexity: O(NlogN)
//Expected Space Complexity: O(1)

//BruteForce is 2-D array comparison. 
//Coding Solution: QuickSort way. 



//Method to print the array
void printArray(char arr[])
{
    //int n = sizeof(arr)/sizeof(arr[0]);
    for (int i=0; i<6;  i++)
        cout << arr[i] << " ";
     cout <<"\n";
}  

//Similar to pivot partition method, Here we pass the pivot element too.
//Instead of choosing it inside the method. 
int partition (char arr[], int low, int high, char pivot)
{   
    int i = low;
    char temp1, temp2;

    for(int j=low;  i<high; j++){
        if(arr[j] < pivot)
        {
            temp1 =  arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
        }
        else if(arr[j] == pivot)
        {
            temp1 = arr[i];
            arr[j] = arr[high];
            arr[high] = temp1;
            j--;
        }
    }
    temp2= arr[i];
    arr[i] = arr[high];
    arr[high] = temp2;

    //Retur the partition index of array based on the pivot element of other array.
    return i;
}

//Function that works just like quick sort
void matchPairs(char nuts[], char bolts[], int low, int high)
{
    if(low < high)
    {
        //Choose last character of bolts array for nut partition.
        int pivot = partition(nuts, low, high, bolts[high]);

        //Now using the partition o nuts, choose that for bolts partition
        partition(bolts, low, high, nuts[pivot]);

        //Recursion for [low...pivot-1] &
        //{pivott+1...high] for nuts ad bolts array
        matchPairs(nuts, bolts, low, pivot-1);
        matchPairs(nuts, bolts, pivot+1, high);
    }
}


//Driver Code
int main()
{
    //Nuts and bolts represented in char array
    char nuts[] = {'@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '%', '&', '^', '@', '#'};

    //Method based on quick sort which matches nutss and bolts
    matchPairs(nuts, bolts, 0, 5);
    cout<<"Matched nuts and bolts are \n";
    printArray(nuts);
    printArray(bolts);

}