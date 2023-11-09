#include<iostream>
using namespace std;
#include<time.h>
#include<random>
#include <iomanip>

void merge(int a[], int lt,int rt, int mid){
    int i,j,k; 
    int n1 = mid- lt + 1;
    int n2 = rt - mid;

    int LA[n1], RA[n2];
    for(i=0;i<n1;i++){
        LA[i] = a[lt+i];
    }
    for(j=0;j<n1;j++){
        RA[j] = a[mid + 1 + j];
    }
    i=0;
    j=0;
    k=lt;
    while(i<n1 &&j<n2){
        if(LA[i]<RA[j]){
            a[k] = LA[i];
            k++;
            i++;
        }
        else{
            a[k] = RA[j];
            k++;
            j++;
        }
    }

    while(i<n1){
         a[k] = LA[i];
            k++;
            i++;
    }
    while(j<n2){
        a[k] = RA[j];
            k++;
            j++;
    }

}
void mergeSort(int a[],int beg,int end){
    if(beg < end){
        int mid = (beg + end)/2;
        mergeSort(a,beg,mid);
        mergeSort(a,mid+1,end);
        merge(a,beg,end,mid);
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
    mergeSort(arr,0,n-1);
    end = clock();
    double tt = double(end -start)/double(CLOCKS_PER_SEC);
    cout << "The time taken is "<<fixed<< tt<<setprecision(7)<<endl;
    for(int i:arr){
        cout<<i<<",";
    }
}   

