#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;
const int M=1e6+7;
const int MAXN=1e4;
int power(int x,int y)
{
    int ans=1;
    for(int i=1;i<=y;i++)ans*=x;
    return ans;
}
int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    int n=M;
    vector<double>q1;
    vector<double>q2;
    for(int i=1;i<=n;i++)
    {
        int value_x=mt()%MAXN;
        int value_y=mt()%MAXN;
        int cnt=0;
        int used=value_y;
        while(used)
        {
            used/=10;
            cnt++;
        }
        double res=(double)value_x+(double)((double)value_y/(double)power(10,cnt));
        q1.push_back(res);
    }
    sort(q1.begin(),q1.end());
    for(int i=1;i<=n;i++)
    {
        int value_x=mt()%MAXN;
        int value_y=mt()%MAXN;
        int cnt=0;
        int used=value_y;
        while(used)
        {
            used/=10;
            cnt++;
        }
        double res=(double)value_x+(double)((double)value_y/(double)power(10,cnt));
        q2.push_back(res);
    }
    sort(q2.begin(),q2.end(),greater<double>());
    for(double node:q1)cout<<node<<" ";
    cout<<endl;
    for(double node:q2)cout<<node<<" ";
    cout<<endl;
    for(int i=1; i<=6; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int value_x=mt()%MAXN;
            int value_y=mt()%MAXN;
            cout<<value_x<<"."<<value_y<<" ";
        }
        cout<<endl;
    }
}

