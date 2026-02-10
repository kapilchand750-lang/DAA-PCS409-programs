// Week4 : Ques(1) : Merge Sort

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int l, int mid, int r, int &cmp){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int>left(n1);
    vector<int>right(n2);
    for(int i = 0; i<n1; i++)
        left[i] = arr[l + i];
    for(int j = 0; j<n2; j++)
        right[j] = arr[mid+1+j];
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        cmp++;
        if(left[i]<right[j])
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }  
    while(i<n1)
        arr[k++] = left[i++];
    while(j<n2)
        arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r, int &cmp){
    if(l<r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid, cmp);
        mergeSort(arr, mid+1, r, cmp);
        merge(arr, l, mid, r, cmp);
    }
}

int main(){
    int n;
    cout<<"Enter the n : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the unsorted array : ";
    for(int i = 0; i<n; i++) cin>>arr[i];
    
    int cmp = 0;
    mergeSort(arr,0,n-1,cmp);

    cout<<"Sorted array : ";
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Total comparisions: "<<cmp<<endl;

}