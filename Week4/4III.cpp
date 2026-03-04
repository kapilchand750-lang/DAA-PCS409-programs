// Week4 (Ques3) : Using Quick Select for finding kth smallest

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr,int left,int right)
{
    int pivot = arr[right];
    int i = left;

    for(int j = left; j < right; j++)
    {
        if(arr[j] <= pivot)
        {
            swap(arr[i],arr[j]);
            i++;
        }
    }

    swap(arr[i],arr[right]);

    return i;
}

int quickSelect(vector<int>& arr,int left,int right,int k)
{
    if(left <= right)
    {
        int pos = partition(arr,left,right);

        if(pos == k)
            return arr[pos];

        if(pos > k)
            return quickSelect(arr,left,pos-1,k);

        return quickSelect(arr,pos+1,right,k);
    }

    return INT_MAX;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        vector<int> arr(n);

        for(int i=0;i<n;i++)
            cin >> arr[i];

        int k;
        cin >> k;

        if(k > n || k <= 0)
        {
            cout << "not present" << endl;
            continue;
        }

        int result = quickSelect(arr,0,n-1,k-1);

        cout << result << endl;
    }
}