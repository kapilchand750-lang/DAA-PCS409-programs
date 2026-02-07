// Week2 (Ques2) : a[i] + a[j] = a[k]
#include<bits/stdc++.h>
using namespace std;

vector<int> threeIndices(vector<int>& arr){
    int n = arr.size();
    vector<int>ind;
    for(int k = n-1; k>=2; k--){
        for(int i = 0, j = k-1; i<j;){
            int sum = arr[i] + arr[j];
            if(sum<arr[k]) 
                i++;
            else if(sum>arr[k])
                j--;
            else if(sum == arr[k]){
                ind.push_back(i);
                ind.push_back(j);
                i++;
                j--;
            }
        }
    }
    return ind;
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
        vector<int>ind = threeIndices(arr);
        if(ind.size()==0)
            cout<<"Not Found!"<<endl;
        else{
            for(auto i = 0; i<ind.size(); i++)
                cout<<ind[i]<<" ";
            cout<<endl;
        }
    }
}