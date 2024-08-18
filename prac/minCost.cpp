#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>,greater<int> > minHeap;
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(4);
    minHeap.push(6);
    int ans=0;
   
    while(minHeap.size()>1){
        int a=minHeap.top();
       
        minHeap.pop();
        int c=minHeap.top();
        minHeap.pop();
        
        int t=a+c;
        ans+=t;
        minHeap.push(t);

    }
    cout<<ans<<endl;

    return 0;
}