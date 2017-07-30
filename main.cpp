#include <iostream>
#include <vector>

using namespace std;


//47% 12ms
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i=0;
        int j=0;
        int sum=nums[0];
        int length = int(nums.size());
        while(j<nums.size()){
            if(sum<s){
                j++;
                if(j<nums.size()) {
                    sum += nums[j];
                    cout << "j:" << j << endl;
                }
            }else{
                length=min(length,j-i+1);
                sum-=nums[i];
                i++;
                cout<<"i:"<<i<<endl;
            }
        }

        if(i==0)
            return 0;
        return length;
    }
};


int main() {
    int nums[] = {5,1,3,5,10,7,4,9,2,8};
    vector<int> nums_vec = vector<int>( nums , nums + sizeof(nums)/sizeof(int));

    int s = 15;

    cout<<Solution().minSubArrayLen( s, nums_vec )<<endl;

    return 0;

}