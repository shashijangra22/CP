// https://code.google.com/codejam/contest/2924486/dashboard#s=p3
#include<bits/stdc++.h>
using namespace std;

#define pll pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define loop(i,x,y,z) for(int i=x; i<=y; i+=z)

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
string dirMap="ESWN";

int turnLeft(int dir){
    if(dir==0) return 3;
    return dir-1;
}

int main(){
    IOS
    // do magic here
    int t,n,sx,sy,ex,ey,dir;
    string str;
    cin>>t;
    loop(cass,1,t,1){
        cout<<"Case #"<<cass<<": ";
        cin>>n;
        vector<vector<char>> grid(n+2,vector<char> (n+2,'#'));
        loop(row,1,n,1){
            cin>>str;
            loop(col,1,n,1){
                grid[row][col]=str[col-1];
            }
        }
        cin>>sx>>sy>>ex>>ey;
        if(grid[sx-1][sy]=='#' and grid[sx][sy+1]=='#' and grid[sx+1][sy]=='#' and grid[sx][sy-1]=='#'){
            cout<<"Edison ran out of energy.\n";
            continue;
        }
        if(sx==1 and sy==1) dir=0;
        else if(sx==1 and sy==n) dir=1;
        else if(sx==n and sy==n) dir=2;
        else dir=3;
        
        queue<pll> Q;
        vector<int> ans;
        Q.push({sx,sy});
        while(!Q.empty() and ans.size()<=10000){
            pll curr=Q.front();
            if (curr.first==ex and curr.second==ey) break;  //reached destination
            Q.pop();
            int initDir=dir;
            dir=turnLeft(dir);  // turn left to follow wall
            while(grid[curr.first+dx[dir]][curr.second+dy[dir]]=='#'){
                dir=(dir+1)%4;  // turn right if obstacle
            }
            ans.push_back(dir);
            Q.push({curr.first+dx[dir],curr.second+dy[dir]});
        }
        if(ans.size()>10000) cout<<"Edison ran out of energy.\n";
        else{
            cout<<ans.size()<<endl;
            for(auto x:ans) cout<<dirMap[x];
            cout<<endl;
        }
    }
    return 0;
}
