#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...

using namespace std;

#include <climits>
#include <stack>
#define MOD 1000000007
#define ll long long


// Define an infinite value for initial comparison
const int INF = INT_MAX;
#define rep( i,n) for(int i=0;i<n;i++)
class Queue{
    int size;
    int front;
    int * arr;
    int back;
    int cnt;
    public:
        Queue (int n){
            size=n;
            front=0;
            back=0;
            arr = new int[size];
        }
        void Push(int a){
            if(cnt==size){
                return;
            }
            cnt++;
            arr[back]=a;
            back++;
        }
        void Pop(){
            front++;
            cnt--;
        }
        int Top(){
            int t=arr[front%size];
           
            return t;
        }
        

};

class qt {
    stack<int> s;
    public:
    void Push(int a){
        s.push(a);
        int m=s.size();
        for(int i=1;i<=m-1;i++){
            s.push(s.top());
            s.pop();
        }
    }
    void Pop(){
        s.pop();
    }
    int Size(){
        return s.size();
    }
    int Top(){
        return s.top();
    }

};
 



int main(){
   qt q;
   for(int i=0;i<10;i++){
    q.Push(i*1);
   }
   int s=q.Size();
   while(s){
        cout<<q.Top()<<" ";
        q.Pop();
        s--;
   }
   return 0;

}