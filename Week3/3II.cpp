#include<bits/stdc++.h>
using namespace std;

pair<int, int> selectionSort(vector<int>&arr){
    int n = arr.size();
    int comparisions = 0;
    int swaps = 0;
    for(int i = 0; i<n-1; i++){
        int min = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[min]) 
                min = j;
            comparisions++;
        }
        if(i!=min){
            swaps++;
            swap(arr[i], arr[min]);
        }
    }
    return {comparisions, swaps};
}

int main(){
    int n;
    cout<<"Enter the n : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the unsorted array : ";
    for(int i = 0; i<n; i++) cin>>arr[i];

    pair<int, int>p = selectionSort(arr);

    cout<<"Sorted array : ";
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"No. of comparisions : "<<p.first<<endl;
    cout<<"No. of swaps : "<<p.second<<endl;
}
