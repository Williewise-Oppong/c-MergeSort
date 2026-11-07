#include <iostream>
#include <cmath>

void merge(int arr[],int low, int high, int mid){
    const int SIZE1 = mid-low+1;
    const int SIZE2 = high-mid;
    int* left = new int[SIZE1+1];
    int* right = new int[SIZE2+1];

    for(int i=0;i<SIZE1;i++){
        left[i] = arr[low+i];
    }
    for(int j=0;j<SIZE2;j++){
        right[j] = arr[mid+j+1];
    }

    int i=0, j=0 , k=low;
    while(i<SIZE1 && j<SIZE2){
        if(left[i]<right[j]){
            arr[low++] = left[i++];
        }
        else{
            arr[low++] = right[j++];
        }
    }
    while(i<SIZE1){
        arr[low++] = left[i++];
    }
    while(j<SIZE2){
        arr[low++] = right[j++];
    }
}

void mergeSort(int arr[],int low,int high){
    if(low>=high)return;

    int mid = floor((low+high)/2);
    
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,high,mid);
}



int main(){
    int test[5] = {1,4,5,2,3};
    mergeSort(test,0,4);
    for(int i:test){
        std::cout<<i<<" ";
    }
    return 0;
}