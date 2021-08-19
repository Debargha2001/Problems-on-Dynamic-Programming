#include<iostream>
using namespace std;
int editDistanceHelper(string s, string t, int** dp){
    // base case
    int m=s.size();
    int n=t.size();
    if(m==0 || n==0){
        return max(m,n);
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s[0]==t[0]){
        return editDistanceHelper(s.substr(1),t.substr(1),dp);
    }
    // insert
    int x=editDistanceHelper(s.substr(1),t,dp);
    // delete
    int y=editDistanceHelper(s,t.substr(1),dp);
    // replace
    int z=editDistanceHelper(s.substr(1),t.substr(1),dp);
    int ans=1+min(x,min(y,z));
    dp[m][n]=ans;
    return ans;
}
int editDistance(string s, string t){
    int m=s.size();
    int n=t.size();
    int** dp=new int* [m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    return editDistanceHelper(s,t,dp);
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDistance(s,t);
}