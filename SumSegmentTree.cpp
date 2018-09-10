/*
Implementation of Segment Tree
to find sum of the given range
in an array  by
@prnjl-g*/



int segTree[100000];
int getMid(int starting_index,int ending_index)
{
    return (starting_index+((ending_index-starting_index)/2.0));
}
void BuildSegmentTree(int arr[],int starting_index,int ending_index,int node)
{
    if(starting_index==ending_index)
    {
        segTree[node]=arr[starting_index];
        return;
    }
    int mid=getMid(starting_index,ending_index);
    BuildSegmentTree(arr,starting_index,mid,(2*node)+1);
    BuildSegmentTree(arr,mid+1,ending_index,(2*node)+2);
    segTree[node]=segTree[(2*node)+1]+segTree[(2*node)+2];
}
void PointUpdate(int starting_index,int ending_index,int index, int node,int value)
{
    if(starting_index>index||index>ending_index)
        return ;
    if(starting_index==index&&ending_index==index)
        {
            segTree[node]=value;
            return;
        }
    int mid=getMid(starting_index,ending_index);
    PointUpdate(starting_index,mid,index,2*node+1,value);
    PointUpdate(mid+1,ending_index,index,2*node+2,value);
    segTree[node]=segTree[(2*node)+1]+segTree[(2*node)+2];
}
int Query(int starting_index,int ending_index,int query_starting_index,int query_ending_index, int node)
{
    if(query_ending_index<starting_index||query_starting_index>ending_index)
        return 0;
    if(query_starting_index<=starting_index&&query_ending_index>=ending_index)
        return segTree[node];
    int mid=getMid(starting_index,ending_index);
    int ele1=Query(starting_index,mid,query_starting_index,query_ending_index,2*node+1);
    int ele2=Query(mid+1,ending_index,query_starting_index,query_ending_index,2*node+2);
    return ele1+ele2;
}
