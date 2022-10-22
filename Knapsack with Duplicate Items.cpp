/*

Given a set of N items, each with a weight and a value, represented by the array w[] and val[] respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

*/

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        int t[N+1][W+1];
        
        for (int i=0;i<N+1;i++)
        {
            for(int j=0;j<W+1;j++)
            {
                if(i==0 or j==0) t[i][j]=0;
            }
        }
        
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<W+1;j++)
            {
                if(wt[i-1]<=j)
                {
                    t[i][j]=max(val[i-1]+t[i][j-wt[i-1]] ,t[i-1][j]);
                }
                else
                {
                    t[i][j]= t[i-1][j];
                }
            }
        }
        
        return t[N][W];
        
    }
};
