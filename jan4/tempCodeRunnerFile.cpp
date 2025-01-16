int sc= 0 ;
    int ans = -1;
    for(int i=0;i<influenceScore.size();i++){
        if(influenceScore[i]>sc){
            sc = influenceScore[i];
            ans = i;
        }
    }
    return ans;