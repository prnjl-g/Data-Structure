/*
Implementation of
Min Heap
by @prnjl-g

*/


#include<bits/stdc++.h>
using namespace std;

int *minheap;
int capacity;
int heap_size;

//To get Position of parent
int parent(int i)
{
    return ((i-1)/2);
}

//to get position of left child
int leftChild(int i)
{
    return (2*i+1);
}

//to get position of right child
int rightChild(int i)
{
    return (2*i+2);
}
//function to build create space for MinHeap of given capacity
void createHeap(int cap)
{
    minheap=new int[cap];
    heap_size=0;
    capacity=cap;
}


//Function to insert values into minHeap
void insertVal(int val)
{
    if(heap_size==capacity)    //if heap is full
    {
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Oops!! Heap is full"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        return ;
    }
    minheap[heap_size]=val;
    int i=heap_size;
    heap_size++;
    while(i!=0 && minheap[i]<minheap[parent(i)])     //if minHeap property is violate
    {
        swap(minheap[i],minheap[parent(i)]);
        i=parent(i);
    }
}


//function to perform heapify operation
void minHeapify(int pos)
{
    int l=leftChild(pos);
    int r=rightChild(pos);
    int small=pos;
    if(l<heap_size&&minheap[l]<minheap[pos])
        small=l;
    if(r<heap_size&&minheap[r]<minheap[small])
        small=r;
    if(small!=pos)
    {
        swap(minheap[pos],minheap[small]);
        minHeapify(small);
    }
}
//function to get/remove the minimum element from the heap;
int extractMin()
{
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1)
    {
        return minheap[0];
        heap_size--;
    }
    int temp=minheap[0];
    minheap[0]=minheap[heap_size-1];
    heap_size--;
    minHeapify(0);
    return temp;

}


// Function to change or update the value at given position
void decreaseKey(int i,int new_val)
{
    minheap[i]=new_val;
    while(i!=0 && minheap[i]<minheap[parent(i)])
    {
        swap(minheap[i],minheap[parent(i)]);
        i=parent(i);
    }

}


//function to delete a value of given position
void deleteVal(int pos)
{
    decreaseKey(pos,INT_MIN);
    extractMin();
}


//function to get minimum value present in heap
int getMin()
{
    if(heap_size<=0)
        return -1;
    else
        return minheap[0];
}
//main function
/*int main()
{
    int soh;
    cin>>soh;
    createHeap(soh);
    for(int i=0;i<soh;i++)
    {
        int val;
        cin>>val;
        insertVal(val);
    }
    cout<<getMin()<<endl;
    cout<<extractMin()<<endl;
    deleteVal(3);
    cout<<getMin()<<endl;
    decreaseKey(3,0);
    cout<<getMin()<<endl;
    return 0;
}*/










