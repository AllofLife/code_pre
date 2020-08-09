#include<stdio.h>
#include<stack.h>
#define max_node 20
#define max 20000
using namespace std;

int map[max_node][max_node];

void dfs(int start,int n)
{
    stack s;
    int i,vis[max_node],ctop;
    memset(vis,0,sizeof(vis));
    vis[start] = 1;
    printf("%d ",start);
    for (i = 1;i <= n;i++)
        if(!vis[i] && map[i][start] == 1)
        {
            vis[i] = 1;
            s.push(i);
        }
    while(!s.empty())
    {
        ctop = s.top();
        vis[ctop] = 1;
        printf("%d ",s.top());
        s.pop();
        for (i = 1;i <= n;i++)
            if(!vis[i] && map[i][ctop] == 1)
            {
                vis[i] = 1;
                s.push(i);
            }
    }
}

int main()
{
    int s,t,n;
    scanf("%d",&n);
    memset(map,max,sizeof(map));
    while(1)
    {
        scanf("%d %d",&s,&t);
        if(s == 0) break;
        map[s][t] = map[t][s] = 1;
    }
    dfs(1,n);
    return 0;
}