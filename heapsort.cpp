#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+7;
int a[M];
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    maxx=n-1;
    for(int i=0;i<=n-1;i++)cin>>a[i];
    for(int i=n/2-1;i>=0;i--)change(i);
    for(int i=n-1;i>=0;i--)
    {
        maxx=i-1;
        swap(a[0],a[i]);
        change(0);

    }
    for(int i=0;i<=n-1;i++)cout<<a[i]<<" ";
}
