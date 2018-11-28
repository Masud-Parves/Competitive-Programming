#include<bits/stdc++.h>
#include<bitset>
 
using namespace std;
 
/*
 
        Bismillahir Rahmanir Rahim
        SPOJ PRIME1 - Prime Generator
        Problem Link : https://www.spoj.com/problems/PRIME1
        Topics : Segmented Sieve
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/
 
 
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a)  a.begin(), a.end()
 
 
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
 
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
 
#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define mx  100009
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define NOT_VISITED 0
#define IS_VISITED 1
 
 
 
int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};
 
 
const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
 
 
 
vector < int > primes,sg,sgPrimes;
 
void sieve()
{
    bitset<mx+1>flag;
    flag.reset();
    primes.push_back(2);
 
    flag[0]=flag[1]=true;
 
    for(int i=4 ; i<=mx ; i+=2)
    {
        flag[i]=true;
    }
 
    for(int i=3 ; i<=mx ; i+=2)
    {
        if(flag[i]==false) /// i is prime
        {
            primes.push_back(i);
            for(int j=i+i ; j<=mx ; j=j+i)
            {
                flag[j]=true; ///j is not prime
            }
        }
    }
}
 
 
void segmentedSieve(ll l, ll r)
{
    bitset<mx+1>isPrime;
    isPrime.set();
    if(l==1)
        isPrime[0]=0;
 
    for(int i=0 ; primes[i]*primes[i]<=r ; i++)
    {
        ll curPrime=primes[i];
 
        ll base=(l/curPrime)*curPrime;
        if(base<l)
        {
            base+=curPrime;
        }
        for(ll j=base ; j<=r ; j+=curPrime)
            isPrime[j-l]=0;
        if(base==curPrime) isPrime[base-l]=1;
    }
    for(int i=0 ; i<=r-l ; i++)
    {
        if(isPrime[i]!=0)
            cout<<i+l <<endl;
    }
    cout<<endl;
}
 
int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    sieve();
 
    int t;
    cin>>t;
 
    TEST_CASE(t)
    {
        ll l,r;
        cin>>l>>r;
        segmentedSieve(l,r);
    }
 
    return 0;
}