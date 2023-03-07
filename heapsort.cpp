#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
const int M=1e6+7;
double a[M];
int n,maxx;
void change(int index)
{
    int res=index;
    int value=a[index];
    int index_x=index*2+1;
    int index_y=index*2+2;
    if(index_x<=maxx&&a[index]<a[index_x])index=index_x;
    if(index_y<=maxx&&a[index]<a[index_y])index=index_y;
    swap(a[res],a[index]);
    if(index!=res)change(index);
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
        for(int i=n/2-1; i>=0; i--)change(i);
        for(int i=n-1; i>=0; i--)
        {
            maxx=i-1;
            swap(a[0],a[i]);
            change(0);
        }
        duration=(clock()-start)/(double)CLOCKS_PER_SEC;
        cout<<fixed<<setprecision(4)<<duration<<"\n";
    }
}
