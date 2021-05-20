#include <iostream>
#include <bits/stdc++.h>>

using namespace std;
vector<string>ma(1);
vector<pair<int,int>>v;
bool vis[10][10];
//bool vi[10][6];
bool temp[10][10];

bool check(int s,int e)
{
    if(s<0||e<0||s>=10||e>=10)
        return false;
    if(vis[s][e]==true)
        return false;
    return true;


}
/*void bfs(char a[][6],int s,int e,string st,int p,int m)
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
}*/
void update(char a[][10],int s,int e,string z)
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
void bfsupdate(char a[][10],int s,int e,string st)
{
    if(s<0||e<0||s>=10||e>=10)
        return;
    if(vis[s][e]==false||temp[s][e]==true)
        return;
       /* if(a[s][e]=='0')
            return;
    if(a[s][e]=='1'&&(s!=p&&e!=m))
    return;*/

    //if(temp)
    //    return 1;
    if(a[s][e]=='1')
    {

            ma[0]=(st);
            //temp= 1;
            //return temp;

    }

    temp[s][e]=true;

    if(vis[s+1][e]==true)
         bfsupdate(a,s+1,e,st+"D");
    if(vis[s-1][e]==true)
    bfsupdate(a,s-1,e,st+"U");
    if(vis[s][e+1]==true)
    bfsupdate(a,s,e+1,st+"R");
    if(vis[s][e-1]==true)
    bfsupdate(a,s,e-1,st+"L");
    //temp[s][e]=false;

}
void print(char a[][10])
{
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {

            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    v.clear();
    ma.clear();


    char a[10][10]={{'.' ,'1' ,'.' ,'.' ,'.','.','.' ,'1' ,'.' ,'.' },
                    {'1' ,'.' ,'.' ,'.' ,'.','0','.' ,'.' ,'.' ,'.' },
                    {'.' ,'0' ,'.' ,'.' ,'.','.','.' ,'.' ,'0' ,'.' },
                    {'.' ,'.' ,'.' ,'0' ,'0','.','.' ,'.' ,'.' ,'.' },
                    {'.' ,'.' ,'.' ,'1' ,'.','.','.' ,'.' ,'.' ,'1' },
                    {'1' ,'.' ,'.' ,'.' ,'.','.','.' ,'0' ,'.' ,'.' },
                    {'.' ,'.' ,'.' ,'.' ,'.','.','.' ,'.' ,'.' ,'.' },
                    {'.' ,'1' ,'0' ,'.' ,'0','.','.' ,'.' ,'.' ,'1' },
                    {'.' ,'.' ,'.' ,'.' ,'.','.','.' ,'.' ,'.' ,'.' },
                    {'.' ,'.' ,'.' ,'.' ,'.','1','.' ,'.' ,'1' ,'.' }


    };
     print(a);
    cout<<"Enter the stating position with 0 as the starting row and 0 as the starting column"<<endl;

    int s,e;
    cin>>s>>e;
     while(true){
        if(s<0||e<0||s>=10||e>=10)
        {
            cout<<"The rows are numbered from 0 and the columns are numbered from 0\nEnter again"<<endl;
            cin>>s>>e;
            continue;
        }
        else
            break;


     }


   if(a[s][e]=='1')
   {
       cout<<"MINIMUM NO OF STEPS NEEDED  "<<0<<endl;
       cout<<"YOU ARE PRESENT ON THE EXIT   "<<endl;
       a[s][e]='S';
      print(a);
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

        q.pop();

        vis[x][y]=true;
        if(a[x][y]=='1')
        {

            vis[x][y]=true;
            break;
        }


        if(a[x+1][y]=='.'&&check(x+1,y))
        {
            q.push({x+1,y});

        }
        if((a[x+1][y]=='1')&&(x+1>=0&&y>=0&&y<10&&x+1<10))
            {


                vis[x+1][y]=true;
                break;

            }
         if(a[x-1][y]=='.'&&check(x-1,y))
        {
            q.push({x-1,y});


        }
        if((a[x-1][y]=='1')&&(x-1>=0&&y>=0&&y<10&&x-1<10))
            {



                vis[x-1][y]=true;
                break;
            }
        if(a[x][y+1]=='.'&&check(x,y+1))
        {
            q.push({x,y+1});


        }
        if((a[x][y+1]=='1')&&(x>=0&&y+1>=0&&y+1<10&&x<10))
            {


                vis[x][y+1]=true;
                break;
            }
        if(a[x][y-1]=='.'&&check(x,y-1))
        {
            q.push({x,y-1});


        }
        if((a[x][y-1]=='1')&&(x>=0&&y-1>=0&&y-1<10&&x<10))
            {


                vis[x][y-1]=true;
                break;
            }


    }



    string st="";



     memset(temp,false,sizeof(temp));

    bfsupdate(a,s,e,st);

    string z=ma[0];
    cout<<"MINIMUM NO OF STEPS NEEDED  "<<z.size()<<endl;
    cout<<z<<endl;
    update(a,s,e,z);

    print(a);


    return 0;
}
