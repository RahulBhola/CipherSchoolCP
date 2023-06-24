#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int>  &height) {
        int N=height.size();
        vector<int> lMax(N),rMax(N);
        lMax[0]=height[0];
        rMax[N-1]=height[N-1];

        // for(int i=1;i<N;i++){
        //     lMax[i]=max(lMax[i-1],height[i]);
        // }
        // for(int i=N-2;i>=0;i--){
        //     rMax[i]=max(rMax[i+1],height[i]);
        // }

        for(int i=1;i<N;i++){
            lMax[i]=max(lMax[i-1],height[i]);
            rMax[N-i-1]=max(rMax[N-i],height[N-i-1]);
        }
        int water=0;
        for(int i=1;i<N;i++){
            water+=min(lMax[i],rMax[i])-height[i];
        }
        return water;
    }

int main(){
    int t;
    cin>>t;
    while(t-- > 0){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<rainWater(arr)<<endl;
    }
    return 0;
}