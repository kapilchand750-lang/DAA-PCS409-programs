// Week 1  : Ques 2 : Search O(log(n)) with comparisions.
#include<bits/stdc++.h>
using namespace std;

pair<bool, int> binarySearch(vector<int>& arr, int key){
    int start = 0;
    int end = arr.size()-1;
    int comparisions = 0;
    while(start<=end){
        int mid = start + (end - start)/2;
        comparisions++;
        if(arr[mid]==key)
            return {true, comparisions};
        else if(arr[mid]>key)
            end = mid-1;
        else 
            start = mid + 1;
    }
    return {false, comparisions};
}

int main(){
    int n ; 
    cout<<"Enter the number of searches : ";
    cin>>n;
    while(n--){
        int n = 0;
        cout<<"Enter the size of array : ";
        cin>>n;
        vector<int> arr(n);
        cout<<"Start entering : ";
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        int key;
        cout<<"Enter key to be searched : ";
        cin>>key;
        pair<bool, int>result = binarySearch(arr, key);
        if(result.first) cout<<"Found!"<<endl;
        else cout<<"Not Found!"<<endl;
        cout<<"No. of comparisions : "<<result.second<<endl;
    }
}