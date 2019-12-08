/*
Student Name:
Student Number:
Project Number: 4
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <list>
#include <queue>
#include "HelpStudents.h"

using namespace std;
vector<bool> visit;
vector<int> lastOne;
vector<int> vertexes;
vector<long int> bestDistance;
vector<vector<int>> adjacency;
vector<vector<int>> adjList;
vector<int>maxEdge;
HelpStudents::HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways) {
    // IMPLEMENT ME!
    vertexes=vector<int>();
    visit=vector<bool>();
    lastOne=vector<int>();
    for(int i=1;i<N+1;i++){
        vertexes.push_back(i);
        visit.push_back(false);
        if(i==K){
            lastOne.push_back(K);
        }
    }
    for(int l=0;l<N;l++){
        vector<int > random;
        vector<int> random1;
        adjacency.push_back(random);
        adjList.push_back(random1);
    }
    for(int m=0;m<M;m++){
        adjacency[ways[m].first.first-1].push_back(vertexes[ways[m].first.second-1]);
        adjacency[ways[m].first.second-1].push_back(vertexes[ways[m].first.first-1]);
        adjList[ways[m].first.second-1].push_back(ways[m].second);
        adjList[ways[m].first.first-1].push_back(ways[m].second);
    }
}

long long int HelpStudents::firstStudent() {
    // IMPLEMENT ME!
    deque<int> q;
    int last = 0;
   for(int i=1;i<vertexes.size()+1;i++){
       if(i==1){
           bestDistance.push_back(0);
       }
       if(lastOne.front()!=i){
           bestDistance.push_back(99999999);
       }
       if(lastOne.front()==i){
           last=i;
       }
   }
   q.push_back(vertexes[0]);
    while(!q.empty()){
        int current=q.front();
        visit[current-1]=true;
        q.pop_front();
        for(int i=0;i<adjacency[current-1].size();i++){
            if(!visit[adjacency[current-1][i]-1]){
                if(adjacency[current-1][i]!=last&&bestDistance[adjacency[current-1][i]-1]==99999999){
                    q.push_back(vertexes[adjacency[current-1][i]-1]);
                }
                int tempDistance=getEdgeW(current,adjacency[current-1][i])+bestDistance[current-1];
                if(tempDistance<bestDistance[adjacency[current-1][i]-1]){
                    bestDistance[adjacency[current-1][i]-1]=tempDistance;
                }
            }
        }
    }
    return bestDistance[last-1];

}
long long int HelpStudents::secondStudent() {
    // IMPLEMENT ME!
    deque<int> q;
    int last = 0;
    for(int i=1;i<vertexes.size()+1;i++){
        if(lastOne.front()==i){
            last=i;
        }
        if(i==1) {
            maxEdge.push_back(0);
        }
        else{
            maxEdge.push_back(99999999);
        }
    }
    q.push_back(vertexes[0]);
    while(!q.empty()){
        int current=q.front();
        visit[current-1]=true;
        q.pop_front();
        for(int i=0;i<adjacency[current-1].size();i++){
            if(!visit[adjacency[current-1][i]-1]){
                if(adjacency[current-1][i]!=last&&maxEdge[adjacency[current-1][i]-1]==99999999){
                    q.push_back(vertexes[adjacency[current-1][i]-1]);
                }
                int newW=getEdgeW(current,adjacency[current-1][i]);
                
                if(maxEdge[adjacency[current-1][i]]>maxEdge[current-1]){
                    maxEdge[adjacency[current-1][i]]=maxEdge[current-1];
                    if(newW>maxEdge[adjacency[current-1][i]]){
                        maxEdge[adjacency[current-1][i]]=newW;
                    }
                }
                else{
                    maxEdge[adjacency[current-1][i]]=maxEdge[current-1];

                }
            }
        }
    }
    return maxEdge[last];


}
long long int HelpStudents::thirdStudent() {
    // IMPLEMENT ME!
    deque<int> q;
    int last = 0;
    for(int i=1;i<vertexes.size()+1;i++){
        if(i==1){
            bestDistance.push_back(0);
        }
        if(lastOne.front()!=i){
            bestDistance.push_back(99999999);
        }
        if(lastOne.front()==i){
            last=i;
        }
    }
    q.push_back(vertexes[0]);
    while(!q.empty()){
        int current=q.front();
        visit[current-1]=true;
        q.pop_front();
        for(int i=0;i<adjacency[current-1].size();i++){
            if(!visit[adjacency[current-1][i]-1]){
                if(adjacency[current-1][i]!=last&&bestDistance[adjacency[current-1][i]-1]==99999999){
                    q.push_back(vertexes[adjacency[current-1][i]-1]);
                }
                int tempDistance=1+bestDistance[current-1];
                if(tempDistance<bestDistance[adjacency[current-1][i]-1]){
                    bestDistance[adjacency[current-1][i]-1]=tempDistance;
                }
            }
        }
    }
    return bestDistance[last-1];

}
long long int HelpStudents::fourthStudent() {
    deque<int> q ;
    int last = 0;
    for(int i=1;i<vertexes.size()+1;i++){
        if(i==1){
            bestDistance.push_back(0);
        }
        if(lastOne.front()!=i){
            bestDistance.push_back(99999999);
        }
        if(lastOne.front()==i){
            last=i;
        }
    }
    q.push_back(vertexes[0]);
    while(!q.empty()){
        int current=q.front();
        visit[current-1]=true;
        q.pop_front();
        int k = getMinAdj(current);
        if(current==last){
            return bestDistance[current-1];
        }
        if(k==99999999){
            return -1;
        }
        bestDistance[k-1]=bestDistance[current-1]+getEdgeW(current,k);
        q.push_back(k);
    }
    return -1;
}
long long int HelpStudents::fifthStudent() {
    // IMPLEMENT ME!
}
long long int HelpStudents::getEdgeW(int a , int b){
   for(int i=0;i<adjacency[a-1].size();i++){
       if(adjacency[a-1][i]==b){
           return adjList[a-1][i];
       }
   }
   return 0;
}
long long int HelpStudents::getMinAdj(int a){
    long int min =99999999;
    long int min2=99999999;
    for(int i=0;i<adjacency[a-1].size();i++){
        int l =getEdgeW(a,adjacency[a-1][i]);
        if(min==l){
            if(min2>adjacency[a-1][i]){
                min2=adjacency[a-1][i];
            }
        }
        if(min>l&&!visit[adjacency[a-1][i]-1]){
            min=l;
            min2=adjacency[a-1][i];
        }
    }
    return min2;
}

// YOU CAN ADD YOUR HELPER FUNCTIONS