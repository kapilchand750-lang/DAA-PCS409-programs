// Week 1 : linear search with comparisions.
#include<bits/stdc++.h>
using namespace std;

pair<bool, int> linearSearch(vector<int>& arr, int key){
    int n = arr.size();
    int comparisions = 0;
    for(int i = 0; i<n; i++){
        comparisions++;
        if(arr[i] == key)
            return {true, comparisions};
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
        pair<bool, int>result = linearSearch(arr, key);
        if(result.first) cout<<"Found!"<<endl;
        else cout<<"Not Found!"<<endl;
        cout<<"No. of comparisions : "<<result.second<<endl;
    }
}
