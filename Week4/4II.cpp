// Week4 : Ques(2) : Quick Sort

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int l, int r){
    int pivot = arr[l];
    int start = l+1;
    int end = r;
    while(start<=end){
        while(start<=r && arr[start]<pivot)
            start++;
        while(end>=l+1 && arr[end]>pivot)                    
            end--;
        if(start<end)
           swap(arr[start], arr[end]);
    }
    swap(arr[l], arr[end]);
    return end;
}

void quickSort(vector<int>& arr, int l, int r){
    if(l<r){
        int pivot = partition(arr, l, r);
        quickSort(arr, l, pivot-1);
        quickSort(arr, pivot+1, r);
    }
}

int main(){
    int n;
    cout<<"Enter the n : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the unsorted array : ";
    for(int i = 0; i<n; i++) cin>>arr[i];


    quickSort(arr,0,n-1);

    cout<<"Sorted array : ";
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}