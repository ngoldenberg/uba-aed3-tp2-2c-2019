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
	double dist[n][n];
  

    for (uint i = 0; i < n; i++)  
    {
        for (uint j = 0; j < n; j++)  
        {   
        	dist[i][j] = log(G[i][j]); 
        	cout<<dist[i][j]<<"     "; 
        }
        cout<<endl;
    }
    cout << endl; 

    for (uint k = 0; k < n; k++)  
    {  
        // Pick all vertices as source one by one  
        for (uint i = 0; i < n; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source 
           /*if(dist[i][k] + dist[k][i] < 0)
            {	cout << dist[i][k] + dist[k][i] <<endl; 
            	return false;
            }*/
            for (uint j = 0; j < n; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
               /* double d = dist[i][k] + dist[k][j];
                if (dist[i][j] > d){ 
                    dist[i][j] = d;

                    } */
            	dist[i][j] = max(dist[i][j], dist[i][k] + dist[k][j]);
            }  
        }
        cout << "k: " << k <<endl;
        for (uint i = 0; i < n; i++)  
   		{ 
        	for (uint j = 0; j < n; j++)  
        	{  
        		cout<<dist[i][j]<<"     ";  
        	}  
        	cout<<endl;  
    	}
    	cout << endl;    
    }

    

    return dist[0][0] > 0;    
}
