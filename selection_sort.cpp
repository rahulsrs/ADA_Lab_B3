#include <iostream>
#include <time.h>
#include <random>
#include<iomanip>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n - 1; i++)
    {
        int min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

int main(){
    clock_t start,end;
    int n = 1000;
    int arr[n];
    for(int i=0;i<n;i++){
        int temp = rand();
        arr[i] = temp;
    }
    start = clock();
    selection_sort(arr,n);
    end = clock();
    double tt = double(end -start)/double(CLOCKS_PER_SEC);
    cout << "The time taken is "<<fixed<< tt<<setprecision(7)<<endl;
    for(int i:arr){
        cout<<i<<",";
    }
}