#include<iostream>
using namespace std;
int LCSHelper(string s, string t, int** dp){
    int m=s.size();
    int n=t.size();
    if(m==0||n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s[0]==t[0])
    {
        return 1+LCSHelper(s.substr(1),t.substr(1), dp);
    }
    int ans=max(LCSHelper(s.substr(1),t,dp),LCSHelper(s,t.substr(1),dp));
    dp[m][n]=ans;
    return ans;
}

int LCS(string s, string t){
    int m=s.size();
    int n=t.size();
    int** dp=new int* [m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int [n+1];
        for(int j=0;j<=n;j++){
            dp[i][j]=-1;
        }
    }
    return LCSHelper(s,t,dp);
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t);
    return 0;
}