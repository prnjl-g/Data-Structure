/*
Disjoint Set 
Implementation 
by prnjl-g
*/



#include<bits/stdc++.h>
using namespace std;





struct node{
    long data;
    long rank;
    node* parent;
};

unordered_map<long,node*>mp;
void make_set(long Data)
{
    node* n=(node*)malloc(sizeof(node*));
    n->data=Data;
    n->rank=0;
    n->parent=n;
    mp.insert({Data,n});
    return;
}
node* findset1(node* n)
{
    node* parent=n->parent;
    if(parent->data==n->data)
        return parent;
    n->parent=findset1(parent);
    return n->parent;
}
long findset(long d)
{
    return findset1(mp[d])->data;
}

bool union1(long d1,long d2)
{
    node* n1=findset1(mp[d1]);
    node* n2=findset1(mp[d2]);
    if(n1->data==n2->data)
        return false;
    if(n1->rank>=n2->rank)
    {
         n1->rank=(n1->rank==n2->rank)?n1->rank+1:n1->rank;
         n2->parent=n1;
    }
    else
        n1->parent=n2;
    return true;
}
/*
int main()
{

    make_set(1);
    make_set(2);
    make_set(3);
    make_set(4);
    make_set(5);
    make_set(6);
    make_set(7);
    union1(1,2);
    union1(2,3);
    union1(3,4);
    union1(4,5);
    union1(5,6);
    union1(6,7);
    union1(5,6);
    union1(6,7);
    cout<<findset(1)<<endl;
    cout<<findset(2)<<endl;
    cout<<findset(3)<<endl;
    cout<<findset(4)<<endl;
    cout<<findset(5)<<endl;
    cout<<findset(6)<<endl;
    cout<<findset(7)<<endl;


}
*/
