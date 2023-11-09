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

void insertion_sort(int arr[], int n)
{
    int i,j,temp;
    for(int i=1;i<n;i++){
        j = 0;
        while(j<i){
            if(arr[i]<arr[j]){
                break;
            }
            j++;
        }
        int temp = arr[j];
        arr[j]  = arr[i];

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