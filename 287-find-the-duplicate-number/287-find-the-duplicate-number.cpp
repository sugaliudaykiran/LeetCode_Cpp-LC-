class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        int slow = nums[0];          // Both slow and fast were starts from first element
        int fast = nums[0];          //  In this we move based on value..
        do{
            slow = nums[slow];              //  slow move one step ahead..
            fast = nums[nums[fast]];        //  Fast moves two steps ahead..
        }while (slow != fast);
        
        fast = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];      //  Both pointers are moved one step..
        }
        return slow;
    }
};

/*  
                                    Navie Approach :- 
    1) First sort the vector and check each item with next item, if condition is true then there is a  duplicate number..
    2) TC -> O(n logn).. using merge sort or any sort function..     SC -> O(1)
    
        sort(nums.begin(), nums.end());     
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] == nums[i+1])
            {
                return nums[i];
            }
        }
        return 0;
                                    
                                    Using HashTable :-
    1) Create a frequency (or) count vector of size 'n' and initialize the value as zero..
    2) Traverse the nums and increment the value count by '1', in the count vector of that [nums as that index]..
    3) Check any count has more than 2 (or) equal to 2.. then return the Index of count vector.. which is an element has duplicate..
    4)  TC -> O(n)..    SC -> O(n).. Using additional vector..
        
        int n = nums.size();
        vector <int> hash(n, 0);
        for (int i=0; i<n; i++)
        {
            hash[nums[i]]++;
 
            if (hash[i] >= 2)
            {
                return i;
            }
        }    
        return 0;
                                    Using Two Pointers :-   [Slow and Fast Pointers..]
                                    
        
    
*/             