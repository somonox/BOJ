#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 987654321;

ll n, dp[100001][2];
string s1, s2;

ll func(int i, int flag, string s1, string s2)
{
    ll tmp1 = 0, tmp2 = 0;
    if(s1[0]=='+') tmp1 = dp[i-1][flag] + (s1[1]-'0');
    if(s2[0]=='+') tmp2 = dp[i-1][flag] + (s2[1]-'0');
    if(s1[0]=='-') tmp1 = dp[i-1][flag] - (s1[1]-'0');
    if(s2[0]=='-') tmp2 = dp[i-1][flag] - (s2[1]-'0');
    if(s1[0]=='*') tmp1 = dp[i-1][flag] * (s1[1]-'0');
    if(s2[0]=='*') tmp2 = dp[i-1][flag] * (s2[1]-'0');
    if(s1[0]=='/') tmp1 = dp[i-1][flag] / (s1[1]-'0');
    if(s2[0]=='/') tmp2 = dp[i-1][flag] / (s2[1]-'0');
    return max(tmp1, tmp2);
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    cin >> n;    
    dp[0][0] = dp[0][1] = 1;
    for(int i=1; i<=n; i++)
    {
        cin >> s1 >> s2;

        if(dp[i-1][0]>0) dp[i][0] = func(i, 0, s1, s2);
        if(dp[i-1][1]>0) dp[i][1] = max(dp[i-1][0], func(i, 1, s1, s2));  
    }

    if(max(dp[n][0], dp[n][1])<=0) cout << "ddong game";
    else cout << max(dp[n][0], dp[n][1]);
    return 0;
}