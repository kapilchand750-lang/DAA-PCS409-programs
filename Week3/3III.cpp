#include<bits/stdc++.h>
using namespace std;

bool bruteForce(vector<int>&arr){ //used copy such that no one can change original array
    int n = arr.size();
    // sort arr T[n] = O(nlogn)
    sort(arr.begin(), arr.end());
    // linear search T[n] = O(n)
    for(int i = 0, j = i+1; i<n-1; i++, j++){
        if(arr[i]==arr[j]) return true;
    }
    return false;
}

bool optimal(vector<int>&arr){ //T[n] = O(n)  
    unordered_map<int, int>freq;
    for(auto n : arr) freq[n]++;
    for(auto p : freq){
        if(p.second>1) return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the n : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the unsorted array : ";
    for(int i = 0; i<n; i++) cin>>arr[i];

    cout<<"Duplicates present : "<<bruteForce(arr)<<endl;
    cout<<"Duplicates present : "<<optimal(arr)<<endl;
}