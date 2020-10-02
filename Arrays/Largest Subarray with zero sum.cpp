//https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1
//https://www.youtube.com/watch?v=xmguZ6GbatA - IMP Concept by TUF

//Done in the GFG pratice link
int maxLen(int A[], int n)
{
    unordered_map<int,int> mp;
    int maxi = 0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + A[i];
        if(sum == 0) maxi = i + 1;
        else {
            if(mp.find(sum) != mp.end()) maxi = max(maxi, i - mp[sum]);
            else mp[sum] = i;
        }
    }
    return maxi;
}
