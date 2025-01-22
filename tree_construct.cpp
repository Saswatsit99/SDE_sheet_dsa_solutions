#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/*
Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the
inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Writing the function to constuct the tree

TreeNode* buildTree(vector<int>& pr, vector<int>& in, int s=0,int e=-2, int b=0,int f=-2) // SET END INDEX DEFAULT TO -2 AS ARRAY SIZE CANNOT BE ESTIMATED HERE
 {
        if(e==-2)                                      // NOW IF END INEDXES ARE -2 SET TO LAST INDEX
            e=pr.size()-1;
        if(f==-2)
            f=pr.size()-1;
            
        if(s>e)                                        // IF START INDEX >LAST INDEX RETURN NULL DUE TO INVALID ARRAY INDEXES
        return nullptr;
        
        TreeNode * temp= new TreeNode;                 // CREATE NEW NODE AND ASSIGN VALUE
        temp->val=pr[s];
        if(s==e)									   // IF SINGLE ELEMENT JUST CREATE A LEAF NODE
        {
            temp->left=nullptr;temp->right=nullptr;
            return temp;
        }
        
        int i;
        for(i=b;i<=f;i++)							   // FIND WHERE THE FIRST ELEMENT IN PR(PREORDER) LIES IN in(INORDER) SAY iTH INDEX
        {
            if(pr[s]==in[i])
            break;
        }
        int d1=i-b,d2=f-i;
        temp->left=buildTree(pr,in,s+1,s+d1,b,i-1);    // FIND THE LEFT SUBTREE INORDER AND PRE ORDER
        temp->right=buildTree(pr,in,s+d1+1,e,i+1,f);   // FIND THE RIGHT SUBTREE INORDER AND PRE ORDER
        
        return temp;
    }
    
    
int main()
{
	int n,x;

	//DEFINE ARRAY SIZE
	cin>>n;
	
	vector<int>pr,in;

	//FILL THE ARRAYS
	for(int j=0;j<n;j++)
	{
		cin>>x;
		pr.push_back(x);
	}
	for(int j=0;j<n;j++)
	{
		cin>>x;
		in.push_back(x);
	}
	

	//CALL THE FUCTION TO CONSTRUCT THE BINARY TREE
	TreeNode * root = buildTree(pr,in);

	//PRINT THE RESULT BY PERFORMING BFS
	vector<int>v;
	queue<pair<TreeNode* ,int>>q;
	q.push({root,0});
	while(!q.empty())
	{
		auto p=q.front();
		if(v.size()==p.second)
		v.push_back(p.first->val);
		else
		{int x=v.size();
			while(x!=p.second)
			{
				v.push_back(INT_MIN);    // JUST ENTER INT_MIN FOR NULL VALUES
				x++;  
			}
			v.push_back(p.first->val);
		}
		if(p.first->left)
		q.push({p.first->left,p.second*2+1});
		if(p.first->right)
		q.push({p.first->right,p.second*2+2});
		q.pop();
	}
	for(auto x:v)
	cout<<x<<" ";
	cout<<"\n";
}

