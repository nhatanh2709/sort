#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int t=10;
    while(t--)
    {
        clock_t start=clock();
        double duration;
        vector<double>a(n+7);
        vector<double>q;
        for(int i=1; i<=n; i++)cin>>a[i];
        for(int i=1; i<=n; i++)q.push_back(a[i]);
        sort(q.begin(),q.end());
        duration=(clock()-start)/(double)CLOCKS_PER_SEC;
        cout<<fixed<<setprecision(4)<<duration<<"\n";

    }

}
