#include <bits/stdc++.h>
using namespace std;
int main() {
       string a,b;
       cin >> a >> b;
       int la = a.length();
       int lb = b.length();
       int lcs[la+1][lb+1];
       memset(lcs,0,sizeof(lcs));
       for (int i = 1;i<=la;i++) {
              for (int j = 1; j <=lb;j++) {
                     if (a[i-1] == b[j-1]) {
                            lcs[i][j] = lcs[i-1][j-1]+1;
                     }
                     else {
                            lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
                     }
              }
       }
       cout << lcs[la][lb];
}
