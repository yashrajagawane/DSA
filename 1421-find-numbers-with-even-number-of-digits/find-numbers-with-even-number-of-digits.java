class Solution {
    int findNumbers(int[] nums) {
        if(nums.length==0)
        return -1;
        int count = 0;
        for(int i=0;i<nums.length;i++){
            if(even(nums[i])){
                count++;
            }
        }
        return count;
    }

    boolean even(int num){
        int NOD = digit(num);
        if(NOD % 2 == 0)
        {
            return true;
        }
        return false;
    }

    int digit(int num){
        if(num < 0){
            num = num*-1;
        }

        if(num==0){
            return 1;
        }
        int count = 0;
        while(num > 0){
            count++;
            num = num/10;
        }
        return count;
    }
};