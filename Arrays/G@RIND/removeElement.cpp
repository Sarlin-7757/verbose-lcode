class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0; // Pointer to keep track of the next position for a valid element
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[index] = nums[i]; // Place the valid element at the 'index' position
                index++; // Move the pointer to the next position
            }
        }
        
        return index; // 'index' now represents the new size of the array
    }
};

