#include<stdio.h>


#define maxn 100001


int a[maxn];
int tree[4*maxn];
int n;


void update(int node, int b, int e, int idx, int value){
    if (idx<b || idx>e)return;

    if (idx<=b && idx>=e){
        tree[node] += value;
        //cout <<"index : "<<idx<< "node : "<< node<< " value : " << tree[node] << endl;
        return;
    }

    int mid = (b + e) / 2;
    int left = 2 * node, right = 2 * node + 1;

    update(left, b, mid, idx, value);
    update(right, mid + 1, e, idx, value);
    tree[node] = tree[left] + tree[right];
}


int query(int node, int b, int e, int k)
{
    if (b==e)
    {
        //cout << "query idx : "<< b << endl;
        return b;
    }

    int mid = (b + e) / 2;
    int left = 2 * node, right = 2 * node + 1;

    int store = tree[left];
    int ans = 0, lft=0,rgt=0;
    if (store<k) return  query(right, mid + 1, e, k-store);
    return  query(left, b, mid, k);
}


int main()
{
    //CIN
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cout << "Fi Amanillah" << endl;

    int T;
    //cin >> q;
    //setbuf(stdout, NULL);
    scanf("%d", &T);


    int n=0, ans=0;
    int test_case;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int t,k;
        //cin >> t >> k;
        scanf("%d %d", &t, &k);

        if(t==1){
            n++;
            update(1,1,maxn-1, k, 1);
        }else if(t==2){
            n--;
            update(1,1,maxn-1, k, -1);
        }else if(t==3){
            ans = query(1,1,maxn-1,k);
            printf("%d\n", ans);
        }else if(t==4){
            int pathaw = (n-k+1);
            ans = query(1,1,maxn-1,pathaw);
            printf("%d\n", ans);
        }

    }

    return 0;
}
