#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string shortestCommonSupersequence(string str1, string str2){
    int m = str1.size();
    int n = str2.size();
    int dp[m+1][n+1];
    
    for(int i=0;i<m+1;i++){
        for(int j=0;j<n+1;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
    }
    
    int i=m, j=n;
    string s = "";
    while(i>0 && j>0){
        if(str1[i-1] == str2[j-1]){
           s.push_back(str1[i-1]);
            i--; j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(str1[i-1]);
                i--;
            }
            else{
                s.push_back(str2[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        s.push_back(str1[i-1]);
        i--;
    }
    while(j>0){
        s.push_back(str2[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}

int main(){
    cout << shortestCommonSupersequence("abac", "cab") << endl;
    return 0;
}