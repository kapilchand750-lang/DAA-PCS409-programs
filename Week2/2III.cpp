// Week2 (Ques3) : a[i] - a[j] = a[k];

#include<bits/stdc++.h>
using namespace std;

int pairDiff(vector<int>& arr, int key){
    unordered_map<int, int>freq;
    for(auto a : arr)
        freq[a]++;

    int cnt = 0;
    if(key==0){
        for(auto p : freq){
            if(p.second>1){ 
                int f = p.second;
                cnt += (f*(f-1))/2;
            }
        }
    }
    else {
        for(auto p : freq){
            int y = p.first;
            int x = key + y;
            if(freq.find(x)!=freq.end())
                {cnt += p.second * freq[x];}
        }
    }
    return cnt;
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
        cout<<"Enter the key : ";
        cin>>key;
        int cnt = pairDiff(arr, key);
        cout<<"Pair having difference = key : "<<cnt<<endl;
    }
}