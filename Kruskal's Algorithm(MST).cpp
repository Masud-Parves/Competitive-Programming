#include<bits/stdc++.h>

using namespace std;

/*

        Bismillahir Rahmanir Rahim
        Problem :
        Problem Link :
        Topics :
        Solver : Masud Parves
        I Love Code More than Sharks Love Blood <3
*/


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2



int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N  (1<<pos);}
//int Reset(int N,int pos){return N= N & ~(1<<pos);}
//bool Check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/


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

struct edge
{
    int u,v,w;
};

vector<edge>graph,output;
int parent[maxn],mstValue=0;
int n,e;


bool compare(edge a, edge b)
{
    return a.w<b.w;
}
int Find(int node)
{
    if(parent[node]==node)
        return node;
    return parent[node]=Find(parent[node]);
}
void initPar(int node)
{
    for(int i=0 ; i<=node ; i++)
    {
        parent[i]=i;
    }
}
void minimumSpaningTree(int node)
{
    /*
        Kruskal's algorithm works on  both connected and disconnected graph.
        Kruskal's algorithm can be shown to run in O(E log E) time, or equivalently, O(E log V) time,
           where E is the number of edges in the graph and V is the number of vertices.
    */
    sort(graph.begin(), graph.end(), compare);

    initPar(node);
    int cnt=0;
    for(int i=0 ; i<(int)graph.size() ; i++)
    {
        int uPr=Find(graph[i].u);
        int vPr=Find(graph[i].v);
        if(uPr!=vPr)
        {
            if(cnt==n-1)
                break;
            output.pb(graph[i]);
            mstValue+=graph[i].w;
            parent[uPr]=vPr;
            cnt++;
        }
    }

}


int main()
{
    CIN
    //freopen("in.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin>>n>>e;

    for(int i=0 ; i<e ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        edge input;
        input.u=u;
        input.v=v;
        input.w=w;
        graph.pb(input);
    }

    minimumSpaningTree(n);

    cout<<mstValue<<endl;
    for(int i=0 ; i<(int)output.size() ; i++)
    {
        if(output[i].u<output[i].v)
            cout<<output[i].u<<" "<<output[i].v<<" "<<output[i].w<<endl;
        else
            cout<<output[i].v<<" "<<output[i].u<<" "<<output[i].w<<endl;

    }


    return 0;
}


