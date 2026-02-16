// Week5 - Ques(1) "Return the maximum occurrences number" 
#include<bits/stdc++.h>
using namespace std;

char maxOccurenceElement(vector<char>& arr){
    vector<int>freq(26,0);
    int n = arr.size();
    for(int i = 0; i<n; i++)
        freq[arr[i]-'a']++;
    int maxInd = 0;
    for(int i = 0; i<26; i++){
        if(freq[i]>freq[maxInd])
            maxInd = i;
    }
    return (char)('a'+maxInd);
}

int main(){
    int t;
    cout<<"Enter the test : ";
    cin>>t;
    while(t--){
        int n;
        cout<<"Enter the size of arr : ";
        cin>>n;
        vector<char>arr(n);
        for(int i = 0; i<n; i++ )
            cin>>arr[i];
        cout<<maxOccurenceElement(arr)<<endl;
    }
}