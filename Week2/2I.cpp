// Week2(Ques1) : Find number of Duplicates if present

#include<bits/stdc++.h>
using namespace std;

int firstOcurrence(vector<int>& arr, int key){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid]==key)
            end = mid-1;
        else if(arr[mid]>key)
            end = mid - 1;
        else   
            start = mid + 1;
    }
    return start;
}

int lastOcurrence(vector<int>& arr, int key){
    int start = 0;
    int end = arr.size()-1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid]==key)
            start = mid + 1;
        else if(arr[mid]>key)
            end = mid - 1;
        else   
            start = mid + 1;
    }
    return end;
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
        int first = firstOcurrence(arr, key);
        int last = lastOcurrence(arr, key);
        if(first>last) 
            cout<<"Not Found!"<<endl;
        else   
            cout<<"Found : "<<last + 1 - first<<endl;
    }
}
