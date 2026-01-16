class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int number;
        for( int i = 0;i<nums.size();i++){
            if(cnt == 0){
                number = nums[i];
            }

            if(nums[i] == number){
                cnt++;
            }
            else{
                cnt--;
            }
        }
            return number;
    }
};