#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, capacity;
    cout<<"Enter num of items and capacity: ";
    cin>>n>>capacity;

    int wt[100], val[100], dp[100][100];
    for(int i=1 ; i<=n;i ++){
        cout<<"Enter weight and profit: ";
        cin>>wt[i]>>val[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=capacity; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(wt[i]<=j){
                dp[i][j] = max(val[i] + dp[i-1][j-wt[i]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }


    cout<<"Maximum profit is : "<<dp[n][capacity];


}