#include <iostream>
#include <bits/stdc++.h>>

using namespace std;
vector<string>ma(1);
vector<pair<int,int>>v;
bool vis[10][6];
bool vi[10][6];

bool check(int s,int e)
{
    if(s<0||e<0||s>=10||e>=6)
        return false;
    if(vis[s][e]==true)
        return false;
    return true;


}
void bfs(char a[][6],int s,int e,string st,int p,int m)
{
    if(s<0||e<0||s>=10||e>=6)
        return;
    if(vi[s][e]==true)
        return;
        if(a[s][e]=='0')
            return;
    if(a[s][e]=='1'&&(s!=p&&e!=m))
    return;

    if(s==p&&e==m)
    {
        if(ma[0].empty())
        {
        // cout<<ma.size()<<" "<<st<<endl;
            ma[0]=(st);
         // cout<<ma.size()<<" --"<<ma[0]<<endl;
        }
        else
        {
            if(st.size()<ma[0].size())
            {
              // cout<<st<<endl;

                ma[0]=(st);
            }
        }
    }
        vi[s][e]=true;
        //cout<<s<<" "<<e<<endl;
    bfs(a,s+1,e,st+"D",p,m);
    bfs(a,s-1,e,st+"U",p,m);
    bfs(a,s,e+1,st+"R",p,m);
    bfs(a,s,e-1,st+"L",p,m);
    vi[s][e]=false;
}
void update(char a[][6],int s,int e,string z)
{
    for(int i=0;i<z.size();i++)
    {
        if(z[i]=='U')
        {
            a[s-1][e]='*';
            s=s-1;
        }
         if(z[i]=='D')
        {
            a[s+1][e]='*';
            s=s+1;
        }
         if(z[i]=='R')
        {


            a[s][e+1]='*';
            e=e+1;
        }
         if(z[i]=='L')
        {
            a[s][e-1]='*';
            e=e-1;
        }
    }

}
int main()
{
    v.clear();


    char a[10][6]={{'.' ,'1' ,'.' ,'.' ,'.','.',},
                    {'1' ,'.' ,'.' ,'.' ,'.','.',},
                    {'.' ,'0' ,'.' ,'.' ,'.','.',},
                    {'.' ,'.' ,'.' ,'0' ,'1','.',},
                    {'.' ,'.' ,'.' ,'1' ,'.','.',},
                    {'1' ,'.' ,'.' ,'.' ,'.','.',},
                    {'.' ,'.' ,'.' ,'.' ,'.','.',},
                    {'.' ,'1' ,'0' ,'.' ,'0','.',},
                    {'.' ,'.' ,'.' ,'.' ,'.','.',},
                    {'.' ,'.' ,'.' ,'.' ,'.','1',}


    };
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<6;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the stating position"<<endl;
    int s,e;
    cin>>s>>e;
   // s--;e;
   if(a[s][e]=='1')
   {
       cout<<"MINIMUM NO OF STEPS NEEDED  "<<0<<endl;
       a[s][e]='S';
       for(int i=0;i<10;i++)
    {
        for(int j=0;j<6;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
       return 0;
   }
   if(a[s][e]=='0')
   {
       cout<<"MINIMUM NO OF STEPS NEEDED  "<<0<<endl;
      cout<<"YOU ARE STANDING ON A OBSTACLE"<<endl;
      return 0;
   }

a[s][e]='S';

    memset(vis,false,sizeof(vis));
    queue<pair<int,int>>q;



    q.push({s,e});
    vis[s][e]=true;
    while(!q.empty())
    {
        pair<int,int>p=q.front();
        int x=p.first;
        int y=p.second;
       // cout<<x<<" "<<y<<endl;
        q.pop();

        vis[x][y]=true;
        if(a[x][y]=='1')
        {
            v.push_back({x,y});
            break;
        }


        if(a[x+1][y]=='.'&&check(x+1,y))
        {
            q.push({x+1,y});
          // cout<<"d "<<x+1<<" "<<y<<endl;
        }
        if((a[x+1][y]=='1')&&(x+1>=0&&y>=0&&y<10&&x+1<6))
            {

                v.push_back({x+1,y});
                break;

            }
         if(a[x-1][y]=='.'&&check(x-1,y))
        {
            q.push({x-1,y});
          // cout<<"u "<<x-1<<" "<<y;

        }
        if((a[x-1][y]=='1')&&(x-1>=0&&y>=0&&y<6&&x-1<10))
            {


                v.push_back({x-1,y});
                break;
            }
        if(a[x][y+1]=='.'&&check(x,y+1))
        {
            q.push({x,y+1});
           // cout<<"r "<<x<<" "<<y+1;

        }
        if((a[x][y+1]=='1')&&(x>=0&&y+1>=0&&y+1<6&&x<10))
            {
                //cout<<"pb"<<endl;
                v.push_back({x,y+1});
                break;
            }
        if(a[x][y-1]=='.'&&check(x,y-1))
        {
            q.push({x,y-1});

       //cout<<"l "<<x<<" "<<y-1;
        }
        if((a[x][y-1]=='1')&&(x>=0&&y-1>=0&&y-1<6&&x<10))
            {

                v.push_back({x,y-1});

                break;
            }
           // cout<<endl;

    }


    int p,m;
    for(auto x:v)
      {p=x.first;m=x.second;}
      //cout<<p<<"--- "<<m<<endl;
      vis[p][m]=true;
      cout<<endl;
    string st="";

    memset(vi,false,sizeof(vi));
    bfs(a,s,e,st,p,m);
    //sort(ma.begin(),ma.end());

    string z=ma[0];
    cout<<"MINIMUM NO OF STEPS NEEDED  "<<z.size()<<endl;
    cout<<z<<endl;
    update(a,s,e,z);

  for(int i=0;i<10;i++)
    {
        for(int j=0;j<6;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    //bfs(a,s,e,st);*/
    return 0;
}
