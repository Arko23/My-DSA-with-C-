#include<bits/stdc++.h>
using namespace std;
int coin_exchange(int M,int C[],int d){
    int sol[M+1],A[M+1];
    sol[0] = 0;
    A[0] = -1;
    for(int m=1;m<=M;m++){
        sol[m] = 9999;
        for(int i=0;i<d;i++){
            if(C[i]<=m){
                int cur = 1+sol[m-C[i]];
                if(cur<sol[m]){
                    sol[m] = cur;
                    A[m] = C[i];
                }
            }

        }
     }
        int m = M;
    while (m > 0) {
        cout << A[m] << " ";
        m = m - A[m];
        cout << " yet to pay " << m << endl;
    }
  return sol[M];
}
int main(){
    int coins[] = {1,5,23,25};
    int M = 46;
    int d = sizeof(coins)/sizeof(coins[0]);
    cout<<coin_exchange(M,coins,d);
    return 0;
}
