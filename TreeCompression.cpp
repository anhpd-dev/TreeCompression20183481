#include <iostream>
using namespace std;
int main()
{
	int n, i, min, j, m, x;
	cout<<"Nhap vao so dinh cua cay (n < 100000): ";
	cin>>n;
	x = n;
	int edge[n-1][2], deg[n] = {0};
	cout<<'\n';
	cout<<"Nhap vao danh sach "<<n-1<<" canh: ";
	cout<<'\n';
	for(i=0; i<n-1; i++)
	{
		cin>>edge[i][0]>>edge[i][1];
	    deg[edge[i][0]]++;
	    deg[edge[i][1]]++;
	}
    cout<<"Ma Prufer code tuong ung voi cay da cho la: ";
    for(i=1; i<n-1; i++)
    {
    	// Tim la nho nhat co nhan khac 0
		min = 100000;
    	for(j=0; j<x-1; j++)
        {
        	if(deg[edge[j][0]] == 1)
			{
				if(min > edge[j][0])
				{
					if(edge[j][0] != 0)
					{
						min = edge[j][0];
						m = j;
					}	
				}
			}
			if(deg[edge[j][1]] == 1)
			{
				if(min > edge[j][1])
				{
					if(edge[j][1] != 0)
					{
						min = edge[j][1];
						m = j;
					}	
				}
			}
	    }
	    // Xoa canh khoi cay
        deg[edge[m][0]]--;
        deg[edge[m][1]]--;
        if(deg[edge[m][0]] == 0)
        	cout<<edge[m][1]<<" ";
        else
        	cout<<edge[m][0]<<" ";
        for(j=m; j<x-1; j++)               
        {
        	edge[j][0] = edge[j+1][0];
        	edge[j][1] = edge[j+1][1];
		}
		x--;
    }
	return 0;
}
