#include <bits/stdc++.h>
#define int long long int
#define endl "\n"
#define all(x) (x).begin(), (x).end()

using namespace std;

int modInv(int A,int M){
    int Mod=M;
    int y=0,x=1;
    if(M == 1){
        return 0;
    }
    while(A>1){
        int q=A/M;
        int t=M;
        M=A%M,A=t;
        t=y;
        y=x-q*y;
        x=t;

    }
    if(x<0){
        x+=Mod;
    }
    return x;
}

// time complexity = O(log M)
    const int mod=1e9+7;


void solve(){

    int n;
    cin>>n;

    if(n==1){
        cout<<0<<endl;
        return;
    }

    vector<int>fact(n+1,0);
    fact[0]=1;
    fact[1]=1;
    fact[2]=2;

    for(int i=3;i<=n;i++)
    {
        fact[i]=(fact[i-1] % mod * (i%mod))% mod;
    }

    //calculating factorials upto n

    int answer=0;
    int sign =1;


    for(int i=2;i<=n;i++){
        int modInvVal=modInv(fact[i],mod);
        int s= ((fact[n]%mod) * (modInvVal % mod)) % mod;        //modmultiplication
        if(sign ==1){
            answer=((answer%mod)+(s%mod)) % mod;

        }
        else{
            answer=((answer%mod)-(s%mod)+mod)%mod;
        }
        sign*=-1;
    }

    cout<<answer<<endl;

}

signed main(){

    solve();

}

//tc= O(N*log N)
//sc= O(N)
