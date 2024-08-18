#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...
#include<set>
using namespace std;

#include <climits>
#define MOD 1000000007
#define ll long long


// Define an infinite value for initial comparison
const int INF = INT_MAX;
#define rep( i,n) for(int i=0;i<n;i++)

struct Node{
    int val;
    Node* next;
    Node(int a){
        val=a;
        next=NULL;
    }
};

Node* insertHead(Node* h,int val){
    Node* a = new Node(val);
    a->next=h;
    return a;
}
Node* insertMiddle(Node* h,int v,int k){
    Node* t=h;
    while(t!=NULL){
        if(t->next->val == k){
            Node*  f = new Node(v);
            f->next=t->next;
            t->next=f;
            break;
            
        }
        t=t->next;
    }
    return h;
}
Node*  rev(Node* h){
    if(h==NULL || h->next==NULL){
        return h;
    }
    Node* r = rev(h->next);
    Node* f = h->next;
    f->next=h;
    h->next=NULL;
    return r;
}
Node* REV(Node* h){
    if(h==NULL || h->next==NULL){
        return h;
    }
    Node* p = NULL;
    Node* c=h;
    while(c!=NULL){
        Node* f= c->next;
        c->next=p;
        p=c;
        c=f;
        
    }
    return p;
}

Node* del(Node* h,int v){
    if(h->val==v){
        Node* a = h->next;
        delete(h);
        return a;
        
    }
    Node* t=h;
    while(t!=NULL){
        if(t->next->val==v){
            Node* d = t->next;
            t->next=t->next->next;
            delete(d);
            break;
        }
        t=t->next;
    }
    return h;
}
Node* remove(Node* h){
    Node* t = h;
    set<int> st;
    st.insert(t->val);
    
    while(t->next!=NULL){
        if(st.find(t->next->val)!=st.end()){
            Node* d = t->next;
            t->next = t->next->next;
            
        }
        else{
            st.insert(t->next->val);
            t=t->next;
        }
    }
    return h;
    
}
int main(){
    Node* h = new Node(5);
    Node* t=h;
    for(int i=1;i<=5;i++){
        Node* a = new Node(10);
        t->next = a;
     
        t=t->next;
    }
    t=h;
    while(t!=NULL){
        cout<<t->val<<" ";
        t=t->next;
    }
    cout<<endl;
    Node* a = remove(h);
    while(a!=NULL){
        cout<<a->val<<" ";
        a=a->next;

    }
    // Node* y = insertHead(h,45);
    // Node* y = REV(h);
    // while(y!=NULL){
    //     cout<<y->val<<"->";
    //     y=y->next;
    // }
 

}