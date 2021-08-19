#include<iostream>
using namespace std;
int knapSackHelper(int* weights, int* values, int n, int maxWeight, int** dp){
    if(n==0 || maxWeight<=0){
        return 0;
    }
    if(dp[n][maxWeight]!=-1){
        return dp[n][maxWeight];
    }
    if(weights[0]>maxWeight){
        return knapSackHelper(weights + 1, values + 1, n - 1, maxWeight, dp);
    }
    int x=values[0]+knapSackHelper(weights+1,values+1,n-1,maxWeight-weights[0], dp);
    int y=knapSackHelper(weights+1,values+1,n-1,maxWeight, dp);
    int ans=max(x,y);
    dp[n][maxWeight]=ans;
    return ans;
}
int knapSack(int* weights, int* values, int n, int maxWeight){
    int**dp=new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++){
            dp[i][j]=-1;
        }
    }
    return knapSackHelper(weights,values,n,maxWeight,dp);
}

int main()
{
    int n;
    cin >> n;
    int *wt = new int[n];
    int *val = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++)
    {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapSack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}