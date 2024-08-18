#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// Include other necessary headers...

using namespace std;

#include <climits>
#define MOD 1000000007
#define ll long long


// Define an infinite value for initial comparison
const int INF = INT_MAX;
#define rep( i,n) for(int i=0;i<n;i++)


int main(){
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> applicants,apartments;
    for(int i=0;i<a;i++){
        int x;
        cin>>x;
        applicants.push_back(x);
    }
    for(int i=0;i<b;i++){
        int x;
        cin>>x;
        apartments.push_back(x);
    }
    sort(apartments.begin(),apartments.end());
    sort(applicants.begin(),applicants.end());
    int cnt = 0;

    int Applicant = 0;
    int Apartment = 0;
    while(Apartment < b && Applicant < a){
        if(
        apartments[Apartment]>=applicants[Applicant]-c &&
        apartments[Apartment]<=applicants[Applicant]+c ){
            cnt++;
            Apartment++;
            Applicant++;
        }
        if(apartments[Apartment]<applicants[Applicant]-c){
            Apartment++;
        }
        if(apartments[Apartment]>applicants[Applicant]+c){
            Applicant++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}