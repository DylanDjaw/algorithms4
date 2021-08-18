#include <iostream>
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //必须为有序数组
        int lo = 0, hi = nums.size() - 1;
        int mid = (lo + hi) / 2;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            if(target < nums[mid])
                hi = mid - 1;
            else if(target > nums[mid])
                lo = mid + 1;
            else
                return mid;
        }
        return -1;
    }
};