// Greedy Algorithm to find Minimum number of Coins
#include<bits/stdc++.h>
using namespace std;
int deno[]={1,2,5,10,20,50,100,500,1000} ;
int n= sizeof(deno)/sizeof(deno[0]);
void findmin(int v )
{
    sort(deno, deno+n);
    vector<int> ans ;
    int i;
    for ( i = n-1; i >=0 ; i--)
    {
        while (v>=deno[i])
        {
            ans.push_back(deno[i]);
            v-=deno[i];
        }
        if (v<=0)
        {
            break;
        }
    }
    cout<<"Following is the denominations for  minimal  number of change :\n  " ;
    for ( i = 0; i < ans.size(); i++)
    {
    cout<<ans[i]<<"  ";
    }
    
}
int main()
{
     int n = 93;
     findmin(93) ;
}