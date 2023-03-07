#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+7;
int a[M];
int n;
int find_index(int x,int y)
{
    int value=a[y];
    int cnt=x;
    for(int i=x; i<=y-1; i++)
    {
        if(a[i]<value)
        {
            swap(a[cnt],a[i]);
            cnt++;
        }
    }
    swap(a[cnt],a[y]);
    return cnt;
}
void calc(int x,int y)
{
    if(x>=y)return;
    //cout<<x<<" "<<y<<endl;
    int index=find_index(x,y);
    calc(x,index-1);
    calc(index+1,y);
}
int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int t=10;
    while(t--)
    {
        clock_t start=clock();
        for(int i=1; i<=n; i++)cin>>a[i];
        double duration;
        calc(1,n);
        duration=(clock()-start)/(double)CLOCKS_PER_SEC;
        cout<<fixed<<setprecision(4)<<duration<<"\n";
    }
}
