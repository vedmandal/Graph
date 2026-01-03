#include<iostream>
using namespace std;


 void implementation_of_unweighted_graph(){
    int v,e;
    cout<<"Enter vertex and Edge"<<endl;
    cin>>v>>e;

    int arr[v][v];
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    cout<<"Enter Edges"<<endl;

    for(int i=0;i<e;i++){
            int src,nbr;
            cout<<"Enter Edges( source and neighbour)"<<endl;
            cin>>src>>nbr;
            arr[src][nbr]=1;
            arr[nbr][src]=1;

        }
    

   cout<<"Adjacency matrix output"<<endl;

   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
   }

 }



 void implementation_of_weighted_graph(){
    int v,e;
    cout<<"Enter vertex and Edge"<<endl;
    cin>>v>>e;

    int arr[v][v];
    
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    cout<<"Enter Edges"<<endl;

    for(int i=0;i<e;i++){
            int src,nbr,w;
            cout<<"Enter Edges( source and neighbour and weight)"<<endl;
            cin>>src>>nbr>>w;
            arr[src][nbr]=w;
            arr[nbr][src]=w;

        }
    

   cout<<"adjacency matrix output"<<endl;

   for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
   }

 }



int main(){

   implementation_of_unweighted_graph();
   implementation_of_weighted_graph();

    
}