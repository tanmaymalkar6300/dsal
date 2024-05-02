// Graph representation using adjacency matrix.(find the flight distances between different cities and show in adjacency matrix.)

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    string city[20];
    int matrix[50][50];
    cout<< " Enter the no of the city = ";
    cin >>n;

    for(int i=0; i<n; i++){
        cout << " \nEnter the name of the city = ";
        cin >>city[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            cout <<" \nEnter time required to travel form city "<<city[i]<<" to " << city[j] <<endl;
            cin>>matrix[i][j];
            matrix[j][i]=matrix[i][j];

        }
    }
    for(int i=0; i<n; i++){
        cout <<"\t"<<city[i]<<"\t";

    }

    for(int i=0; i<n; i++){
        cout << "\n"<<city[i];
        for(int j=0; j<n; j++){
            cout <<"\t"<<matrix[i][j]<<"\t";
        }
    }
}
