#include<iostream>
using namespace std;
#include<time.h>
#include<random>
#include <iomanip>

int partition(int a[],int l, int h){
    int piv = a[l];
    int j = h;
    for(int i =h; i>l;i--){
        if(a[i] > piv){
            swap(a[i],a[j]);
            j--;
        }
    }
    swap(a[j],a[l]);
    return j;
}

void quickSort(int a[], int l,int h){
    if(l<h){
        int pi = partition(a,l,h);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,h);
    }
}

int main(){
    clock_t start,end;
    int n = 2000;
    int arr[n];
    for(int i=0;i<n;i++){
        int temp = rand();
        arr[i] = temp;
    }
    start = clock();
    quickSort(arr,0,n-1);
    end = clock();
    double tt = double(end -start)/double(CLOCKS_PER_SEC);
    cout << "The time taken is "<<fixed<< tt<<setprecision(7)<<endl;
    for(int i:arr){
        cout<<i<<",";
    }
}