#include<queue>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
void prepareadjList(unordered_map<int,set<int>>&adjList, vector<pair<int,int>>&edges)
{
    for(int i=0;i<edges.size();++i)
    {
          int u=edges[i].first;
          int v=edges[i].second;
          adjList[u].insert(v);
          adjList[v].insert(u);
    }


}
void bfs(unordered_map<int,set<int>>&adjList,vector<int>&ans,unordered_map<int,bool>&visited,int node)
{
    queue<int>q;
    q.push(node);
    visited[node]=1;
    while(!q.empty())
    {
        int frontNode=q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto i:adjList[frontNode])
        {

            if(!visited[i])
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }

}

int main()
{
    int vertex,nedges;
    vector<pair<int,int>>edges;
    cout<<"Enter no of vertex: ";
    cin>>vertex;
    cout<<"Enter no of edges: ";
    cin>>nedges;
    edges.resize(nedges);
    for(int i=0;i<nedges;i++)
    {
          cout<<"Enter Source vertex: ";
          cin>>edges[i].first;
        cout<<"Enter Destination vertex: ";
          cin>>edges[i].second;

    }
        for(int i=0;i<nedges;i++)
    {
         cout<<edges[i].first;
         cout<<"->";
         cout<<edges[i].second;
         cout<<endl;
    }
        unordered_map<int,set<int>>adjList;
        unordered_map<int,bool>visited;
        prepareadjList(adjList,edges);

        vector<int>ans;
        for(int i=0;i<vertex;i++)
        if(!visited[i])
        {
            bfs(adjList,ans,visited,i);
        }
        for(int j=0;j<ans.size();++j)
      {
          cout<<ans[j]<<",";
      }
}

