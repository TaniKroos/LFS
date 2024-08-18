#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...
#include <queue>
using namespace std;

#include <climits>
#define MOD 1000000007
#define ll long long


// Define an infinite value for initial comparison
const int INF = INT_MAX;
#define rep( i,n) for(int i=0;i<n;i++)

class Stack{
    /* data */
    int size;
    int top;
    int * arr;
    public:
        Stack (int n){
            top=-1;
            

            size=n;
            arr = new int[size];
        }

        void push(int a){
            top++;
            
            arr[top]=a;
        }
        int pop(){
            int a=arr[top];
            top--;
            return a;
        }
        int Size(){
            return top+1;
        }
        int Top(){
            return arr[top];
        }
        bool isempty(){
            if(top==-1){
                return true;
                
            }
            return false;
        }

};


class ST{
    queue<int> q;
    public:
    void Push(int a){
        q.push(a);
        int s=q.size();
        for(int i=1;i<=s-1;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void Pop(){
        q.pop();
    }
    int Top(){
      return  q.front();
    }
    int size(){
        return q.size();
    }


};


int main(){
    ST s;
    for(int i=0;i<10;i++){
        s.Push(i*1);
    }
    int a=s.size();
    while(a){
        cout<<s.Top()<<" ";
        s.Pop();
        a--;
    }
}