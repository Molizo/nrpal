#include <iostream>
#include <fstream>

using namespace std;
ifstream in("nrpal.in");
ofstream out("nrpal.out");

int v[101];

int main()
{char ch;int n;bool error=false;
    in>>n;
    for(int i=0;i<n;i++)
    {
        in>>ch;
        if(ch == '*')
            v[i]=-1;
        else
            v[i]=ch - '0';
    }
    for(int i=0;i<n/2;i++)
    {
        if(v[i]==-1)
        {
            if(v[i+n/2+n%2]==-1)
                v[i]=v[i+n/2+n%2]=9;
            else
                v[i]=v[i+n/2+n%2];
        }
    }
    for(int i=0;i<n/2;i++)
    {
        if(v[n-i-n%2]==v[i] || v[n-i-n%2]==-1)
            v[n-i-n%2]=v[i];
        else
        {
            out<<"0";
            error=true;
            break;
        }
    }
    if(error == false)
    {
        for(int i=0;i<n;i++)
        out<<v[i]<<" ";
    }
    return 0;
}
