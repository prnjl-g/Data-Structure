/*
Implementation of
Min Heap
by @prnjl-g
*/





#include<bits/stdc++.h>
using namespace std;

int *maxheap;
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
//function to build create space for MaxHeap of given capacity
void createHeap(int cap)
{
    maxheap=new int[cap];
    heap_size=0;
    capacity=cap;
}


//Function to insert values into MaxHeap
void insertVal(int val)
{
    if(heap_size==capacity)    //if heap is full
    {
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Oops!! Heap is full"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        return ;
    }
    maxheap[heap_size]=val;
    int i=heap_size;
    heap_size++;
    while(i!=0 && maxheap[i]>maxheap[parent(i)])     //if MaxHeap property is violate
    {
        swap(maxheap[i],maxheap[parent(i)]);
        i=parent(i);
    }
}


//function to perform heapify operation
void maxHeapify(int pos)
{
    int l=leftChild(pos);
    int r=rightChild(pos);
    int big=pos;
    if(l<heap_size&&maxheap[l]>maxheap[pos])
        big=l;
    if(r<heap_size&&maxheap[r]>maxheap[big])
        big=r;
    if(big!=pos)
    {
        swap(maxheap[pos],maxheap[big]);
        maxHeapify(big);
    }
}
//function to get/remove the maximum element from the heap;
int extractMax()
{
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1)
    {
        heap_size--;
        return maxheap[0];

    }
    int temp=maxheap[0];
    maxheap[0]=maxheap[heap_size-1];
    heap_size--;
    maxHeapify(0);
    return temp;

}


// Function to change or update the value at given position
void decreaseKey(int i,int new_val)
{
    maxheap[i]=new_val;
    while(i!=0 && maxheap[i]>maxheap[parent(i)])
    {
        swap(maxheap[i],maxheap[parent(i)]);
        i=parent(i);
    }

}


//function to delete a value of given position
void deleteVal(int pos)
{
    decreaseKey(pos,INT_MAX);
    extractMax();
}


//function to get maximum value present in heap
int getMax()
{
    if(heap_size<=0)
        return -1;
    else
        return maxheap[0];
}
//main function
/*
int main()
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
    for(int i=0;i<heap_size;i++)
        cout<<maxheap[i]<<" ";
    cout<<endl;
    cout<<getMax()<<endl;
    cout<<extractMax()<<endl;

            for(int i=0;i<heap_size;i++)
        cout<<maxheap[i]<<" ";
    cout<<endl;


    
    deleteVal(2);
        for(int i=0;i<heap_size;i++)
        cout<<maxheap[i]<<" ";
    cout<<endl;
    cout<<getMax()<<endl;
    decreaseKey(3,0);
    cout<<getMax()<<endl;
    return 0;
}

*/
