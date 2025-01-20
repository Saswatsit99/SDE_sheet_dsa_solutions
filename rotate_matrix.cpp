#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
Problem statement
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation.

example:

INUPT MATRIX:
[1,2,3]
[4,5,6]
[7,8,9]

OUTPUT MATRIX:
[7,4,1]
[8,5,2]
[9,6,3]

*/
// writing the function which will take in the vector and 
// rotate the matrix accordin to the problem statement
void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(),matrix.end());          // reverse the matrix row order(r1,r2,r3)->(r3,r2,r1)
        int n=matrix.size();
        int i,j;
        
        
        //get matrix transpose
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
int main()
{
	int n,x;

	//DEFINE ARRAY SIZE
	cin>>n;
	
	vector<vector<int>>v;

	//FILL THE ARRAY
	for(int i=0;i<n;i++)
	{
		vector<int>temp;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}

	//CALL THE FUCTION TO SET ROTATE THE MATRIX BY 90 DEGREE
	rotate(v);

	//PRINT THE RESULT
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<v[i][j]<<" ";
		
		}
		cout<<"\n";
	}
	return 0;
}

