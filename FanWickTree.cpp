/* Binary Index Tree 
   /Fanwick Tree implementation 
by @prnjl-g*/

#include<bits/stdc++.h>
using namespace std;
int *arr;
void  update(int value,int index,int size)
{
    while(index<size)
    {
        arr[index]+=value;
        index+=(index & (-index));
    }
}
void buildBIT(int size)
{
    arr=new int[size+1];
    for(int i=0;i<size+1;++i)
        arr[i]=0;
    for(int pos=1;pos<size+1;pos++)
    {
        int temp;
        cin>>temp;
        update(temp,pos,size+1);
    }


}
int sum(int range)
{
    int ans=0;
    while(range>0)
    {
        ans+=arr[range];
        range-=(range & (-range));
    }

    return ans;
}
int getsum(int leftrange, int rightrange)
{
    int ans=sum(rightrange)-sum(leftrange-1);
    return ans;
}

int main()
{
    int size,numOfQueries;
    cin>>size;
    buildBIT(size);
    cout<<"Tree Build Successfully"<<endl;
    for(int i=1;i<size+1;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
    cin>>numOfQueries;
    for(int i=0;i<numOfQueries;++i)
    {
        int leftrange,rightrange;
        cin>>leftrange>>rightrange;
        cout<<getsum(leftrange,rightrange)<<endl;
    }
    return 0;

}
