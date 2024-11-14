#include<bits/stdc++.h>
using namespace std;
int F[1000];
int fib_rec(int n){
    if(n==0 || n==1)
        return n;
    return fib_rec(n-1)+fib_rec(n-2);
}
int fib_dp(int n){
    if(n==0 || n==1)
        return F[n];
    if(F[n-1]==-1)
        F[n-1] = fib_dp(n-1);
    if(F[n-2]==-1)
        F[n-2] = fib_dp(n-2);
    F[n] = F[n-1] + F[n-2];
    return F[n];

}
int fib_tab(int n){
    for(int i=2;i<=n;i++){
        F[i] = F[i-1]+F[i-2];
    }
    return F[n];
}
int main(){
    memset(F,-1,sizeof(F));
    F[0] = 0;
    F[1] = 1;
    clock_t t1 = clock();
    cout<<fib_tab(40)<<endl;
    clock_t t2 = clock();
    clock_t diff = t2-t1;
    cout<<diff<<" ms"<<endl;
    return 0;
}
