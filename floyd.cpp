#include <cmath>
#include <iostream>
#include <vector>
#include <math.h> 
#include <string>      
#include <cstring>    

using namespace std;

typedef vector<vector<double>> Grafo;


void floydWarshall (Grafo G, uint n);

int main()
{
	uint n;

    cin >> n;
    Grafo G(n, vector<double>(n, 1));

    for(uint i = 0; i < n; i++)
    {
        for (uint j = 0; j < n; ++j)
        {
            double c;
            cin >> c;
            if(i != j)
            {
                G[i][j] = c;
            }
        }
    }

    floydWarshall(G,n);
    return 0;
}


void floydWarshall (Grafo G, uint n)
{
  
    double dist[n][n] = {0};
    int pred[n][n];
    memset(pred,0,sizeof(pred));
  

    for (uint i = 0; i < n; i++)  
    {
        for (uint j = 0; j < n; j++)  
        {   
            dist[i][j] = log(G[i][j]); 
         //   cout<< dist[i][j] <<"     "; 
            pred[i][j] = i;
        }
       // cout<<endl;
    }
//    cout << endl; 
    

    for (uint k = 0; k < n; k++)  
    {  
        for (uint i = 0; i < n; i++)  
        {  
            for (uint j = 0; j < n; j++)  
            {        
                double d = dist[i][k] + dist[k][j];
                if (d > dist[i][j]){ 
                    dist[i][j] = d;
                    pred[i][j] = pred[k][j]; 
                } 
           
            }  
        }    
    }

    if(dist[0][0] <= 0)
    {
        cout << "NO" << endl;
        return;
    }
    
    cout << "SI";    
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
        {
          if (i == pred[0][j])
            cout << " " << G[i][j];
        }
    } 
        
    cout  << endl;
  
}
