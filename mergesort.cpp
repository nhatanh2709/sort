#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
const int M=1e6+7;
double a[M],b[M];
int n;
void change(int x,int y)
{
    int mid=(x+y)/2;
    int cnt_x=mid-x+1;
    int cnt_y=y-mid;
    int num_x=0;
    int num_y=0;
    int k=x;
    while(num_x<=cnt_x-1&&num_y<=cnt_y-1)
    {
        if(a[x+num_x]<=a[mid+num_y+1])
        {
            b[k]=a[x+num_x];
            num_x++;
        }
        else
        {
            b[k]=a[mid+1+num_y];
            num_y++;
        }
        k++;
    }
    while(num_x<=cnt_x-1)
    {
        b[k]=a[x+num_x];
        num_x++;
        k++;
    }
    while(num_y<=cnt_y-1)
    {
        b[k]=a[mid+1+num_y];
        num_y++;
        k++;
    }
    for(int i=x; i<=y; i++)a[i]=b[i];
}
void calc(int x,int y)
{
    if(x>=y)return;
    int mid=(x+y)/2;
    calc(x,mid);
    calc(mid+1,y);
    change(x,y);
}
int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int num=10;
    cin>>n;


    while(num--)
    {
        clock_t start=clock();
        for(int i=1; i<=n; i++)cin>>a[i];
        double duration;
        calc(1,n);
        duration=(clock()-start)/(double)CLOCKS_PER_SEC;
        cout<<fixed<<setprecision(4)<<duration<<"\n";

    }
}
