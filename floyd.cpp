#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <math.h>       

using namespace std;

typedef vector<vector<double>> Grafo;


bool floydWarshall (Grafo G, uint n);

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

	vector<double> div;
	cout << floydWarshall(G,n) << endl;
	return 0;
}


bool floydWarshall (Grafo G, uint n)
{
	double dist[n][n][n];
	double path[n][n][n] = {0};
  

    for (uint i = 0; i < n; i++)  
    {
        for (uint j = 0; j < n; j++)  
        {   
            dist[i][j][0] = log(G[i][j]); 
        	cout<<dist[i][j][0]<<"     "; 
        	path[i][j][0] = i;
        }
        cout<<endl;
    }
    cout << endl; 

    for (int s = 1; s < n; ++s)
    {
     
        for (uint k = 0; k < n; k++)  
        {  
            for (uint i = 0; i < n; i++)  
            {  
            
                for (uint j = 0; j < n; j++)  
                {  
            
                    double d = dist[i][k][s-1] + dist[k][j][0];
                    if (dist[i][j][s] < d){ 
               		   dist[i][j][s] = d;
               		   path[i][j][s] = k; 
                    } 
           
                }  
            }
           /* cout << "k: " << k <<endl;
            for (uint i = 0; i < n; i++)  
   		   { 
        	   for (uint j = 0; j < n; j++)  
        	   {  
        		  cout<<path[i][j][s]<<"     ";  
        	   }  
        	   cout<<endl;  
    	   }
    	   cout << endl;*/    
        }
    }
    
    for (int s = 0; s < n; ++s)
    {
        cout << "s: " << s << endl; 
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << "("<< dist[i][j][s] << ", "<< path[i][j][s] << ") ";
            }
            cout << endl;
        }
    }

    return dist[0][0][2] > 0;    
}
