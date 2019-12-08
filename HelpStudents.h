#ifndef CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#define CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class HelpStudents{

public:
    vector<bool> visit;
    vector<int> vertexes;
    vector<int> lastOne;
    vector<long int> bestDistance;
    vector<vector<int>> adjacency;
    vector<vector<int>> adjList;
    vector<int>maxEdge;
    HelpStudents(int  N, int  M, int K, vector < pair< pair <int,int> , int > > ways);
    long long int firstStudent();
    long long int secondStudent();
    long long int thirdStudent();
    long long int fourthStudent();
    long long int fifthStudent();

    // YOU CAN ADD YOUR HELPER FUNCTIONS AND MEMBER FIELDS
    long long int getEdgeW(int a , int b);
    long long int getMinAdj(int a);

};

#endif //CMPE250_ASSIGNMENT3_HELPSTUDENTS_H
