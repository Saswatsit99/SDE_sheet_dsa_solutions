#include<iostream>
#include<vector>
using namespace std;
/*
Problem statement
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

and this has to be done in-palce

example:

INUPT MATRIX:
0 1 2 0 
3 4 5 2 
1 3 1 5

OUTPUT MATRIX:
0 0 0 0
0 4 5 0
0 3 1 0

*/
// writing the function which will take in the vector and set
// the row and columns to zero accordin to the problem statement
void setZeroes(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        int rz=1,cz=1;                           // SETTING THE PARAM FOR FIRST ROW AND FIRST COLUMN
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
		//IF FIRST ROW OR COULMN HAS TO BE SET TO ZERO SET THE PARAMS TO ZERO
                if(i==0&&a[i][j]==0)
                {
                    rz=0;
                }
                if(j==0&&a[i][j]==0)
                {
                    cz=0;
                }

		//IF ROW OR COLUMN WITH INDEX>0 HAS TO BE SET TO ZERO SET THE FIRST ELEMENT OF THE SAME TO ZERO
                if(i!=0&&j!=0&&a[i][j]==0)
                {
                    a[i][0]=a[0][j]=0;
                }

            }
        }
	
	//TRAVESE THE FIRST ROW AND COL. AND SET ZEROES ALL THE ELEMENTS EXCEPT THE ONES ON FIRST ROW AND COL.
        for(int j=1;j<n;j++)
        {
            if(a[0][j]==0){
                for(int i=1;i<m;i++)
                {
                    a[i][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            if(a[i][0]==0){
                for(int j=1;j<n;j++)
                {
                    a[i][j]=0;
                }
            }
        }
        
	// IF FIRST ROW OR COL. HAS TO BE SET TO ZERO DO IT BY READ THE PARAMS
        if(rz==0)
        {
            int i=0;
            while(i<n)
            a[0][i++]=0;
        }
        if(cz==0)
        {
            int i=0;
            while(i<m)
            a[i++][0]=0;
        }
    }
int main()
{
	int m,n,x;

	//DEFINE ARRAY SIZE
	cin>>m>>n;
	
	vector<vector<int>>v;

	//FILL THE ARRAY
	for(int i=0;i<m;i++)
	{
		vector<int>temp;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}

	//CALL THE FUCTION TO SET THE ROW ANDS COLUMNS ZERO AS PER PROBLEM STATEMENT
	setZeroes(v);

	//PRINT THE RESULT
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		
		}
		cout<<"\n";
	}
	return 0;
}
