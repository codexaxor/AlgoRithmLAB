#include<bits/stdc++.h>
using namespace std;

int matrix_chain_multiplication_cost(int array[],int i,int j)
{
    if(i==j)
    {
        return 0;
    }
    else
    {
        int buffer = INT_MAX;
        for(int a=i;a<j;a++)
        {

            int temp = matrix_chain_multiplication_cost(array,i,a);
            temp += matrix_chain_multiplication_cost(array,i+1,j);
            temp += array[i-1]*array[a]*array[j];
            if(temp < buffer)
            {
                buffer = temp;
            }
        }
        return buffer;
    }
}

int main()
{
    int n;

    cin>>n;
    int array[n];

    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<"MCM : "<<matrix_chain_multiplication_cost(array,0,n-1)<<endl;
}