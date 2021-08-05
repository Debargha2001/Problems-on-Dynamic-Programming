#include<iostream>
#include<climits>
using namespace std;

int minCostPathHelper(int** input,int m,int n,int i,int j,int** dp){
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>=m || j>=n){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int opt1 = minCostPathHelper(input,m,n,i+1,j,dp);
    int opt2 = minCostPathHelper(input, m, n, i, j+1, dp);
    int opt3 = minCostPathHelper(input, m, n, i + 1, j+1, dp);
    int ans=input[i][j]+min(opt1,min(opt2,opt3));
    dp[i][j]=ans;
    return ans;
}

int minCostPath(int **input, int m, int n)
{
    int** dp=new int*[m];
    for(int i=0;i<m;i++){
        dp[i] = new int[n];
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    return minCostPathHelper(input,m,n,0,0,dp);
}

// main function

int main()
{
    int **arr, n, m;
    cin >> n >> m;
    arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}
