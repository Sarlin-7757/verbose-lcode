class Solution {
public:
     bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false; 
    }
    
    sort(hand.begin(), hand.end());
    
    map<int, int> freq;
    for (int card : hand) {
        freq[card]++;
    }
    
    for (int card : hand) {
        if (freq[card] == 0) {
            continue;
        }
        for (int i = 0; i < groupSize; i++) {
            if (freq[card + i] == 0) {
                return false; 
            }
            freq[card + i]--; 
        }
    }  
    return true;
}
};

``
grousize = 3 hand  = [1 , 2 ,3 ,6 ,2 ,3 , 4, 7 , 8]

{1 -> 2 -> 3}  // correct 
{1 -> 5 -> 2}  // incorrect
