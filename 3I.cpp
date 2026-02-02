#include<bits/stdc++.h>
using namespace std;

pair<int, int> insertionSort(vector<int>& arr){
    int n = arr.size();
    int comparisions = 0;
    int shifts = 0;
    if(n>1){
        for(int i = 1; i<n; i++){
            int j = i-1;
            int key = arr[i];
            while(j>=0){
                comparisions++;
                if(arr[j]>key){
                    arr[j+1] = arr[j];
                    j--;
                    shifts++;
                }
                else break;
            }
            if(j+1 != i){
                arr[j+1] = key;
                shifts++;
            }
        }
    } 
    return {comparisions, shifts};
}

int main(){
    int n;
    cout<<"Enter the n : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the unsorted array : ";
    for(int i = 0; i<n; i++) cin>>arr[i];

    pair<int, int>p = insertionSort(arr);

    cout<<"Sorted array : ";
    for(int i = 0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;

    cout<<"No. of comparisions : "<<p.first<<endl;
    cout<<"No. of shifts : "<<p.second<<endl;
}

