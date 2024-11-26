class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>container;
        for(int num : nums){
            container.insert(num);
        }
        int longestConsecutive = 0;
      
        for(int num : nums){
            if(container.find(num - 1) == container.end()){
                int current = num;
                int currConsecutiveLength = 1;

                while(container.find(current + 1) != container.end()){
                    current++;
                    currConsecutiveLength++;
                }        
                longestConsecutive = max(longestConsecutive , currConsecutiveLength);   
            }
        }
        return longestConsecutive;
    }
};
