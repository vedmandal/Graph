#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>

using namespace std;

string AlienDictionary(vector<string>&words){
    map<char,set<char>>graph;
    map<char,int>indegree;

    string ans="";
    bool flag=false;

    for(string word:words){
        for(char ch:word){
            indegree[ch]=0;
        }
    }

    for(int i=0;i<words.size()-1;i++){
        string curr=words[i];
        string next=words[i+1];

        int length=min(curr.size(),next.size());

        for(int j=0;j<length;j++){
            char c1=curr[j];
            char c2=next[j];

            if(c1!=c2){
                set<char>s;
                if(graph.find(c1)!=graph.end()){
                    s=graph[c1];
                   
                }
                if(s.find(c2)==s.end()){
                    s.insert(c2);
                    graph[c1]=s;
                    indegree[c2]++;

                }
                flag=true;
               break;

            }
            

        }
        if(!flag and curr.size()> next.size()){
            return "";
        }

    }

    queue<char>q;
    for(auto x:indegree){
        if(indegree[x.first]==0){
            q.push(x.first);
        }
    }

    while(!q.empty()){

        char rem=q.front();
        q.pop();

        ans+=rem;

        if(graph.find(rem)!=graph.end()){
            for(char nbr:graph[rem]){
                indegree[nbr]--;
                if(indegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

    }

    if(ans.size()!=indegree.size()){
        return "";
    }

    return ans;
    



}



int main(){
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    cout<<AlienDictionary(words);

}