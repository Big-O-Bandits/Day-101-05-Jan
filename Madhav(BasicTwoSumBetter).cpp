Better Approach using hasing 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> mp;
        for(int i = 0; i< nums.size(); i++){
            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end()){
                return{mp[remaining], i};
            } 
            mp[nums[i]] = i;
        }

        return {-1,-1};
        
    }
};



Let's perform a dry run of the code using a larger array to demonstrate how the algorithm works.

### Input:
```cpp
nums = [1, 4, 5, 6, 9, 12, 15], target = 10
```

### Initialization:
```cpp
unordered_map<int, int> mp; // The hashmap that will store numbers and their indices.
```

### Iteration 1 (`i = 0`):
- `nums[i] = 1`
- `remaining = target - nums[i] = 10 - 1 = 9`
- Check if `remaining = 9` exists in the map: `mp.find(9) != mp.end()` → `mp` is empty, so it does not find `9`.
- Store `nums[i] = 1` in the map with index `i = 0`: `mp[1] = 0`

Now, the map looks like:
```cpp
mp = {1: 0}
```

### Iteration 2 (`i = 1`):
- `nums[i] = 4`
- `remaining = target - nums[i] = 10 - 4 = 6`
- Check if `remaining = 6` exists in the map: `mp.find(6) != mp.end()` → `mp` does not contain `6`.
- Store `nums[i] = 4` in the map with index `i = 1`: `mp[4] = 1`

Now, the map looks like:
```cpp
mp = {1: 0, 4: 1}
```

### Iteration 3 (`i = 2`):
- `nums[i] = 5`
- `remaining = target - nums[i] = 10 - 5 = 5`
- Check if `remaining = 5` exists in the map: `mp.find(5) != mp.end()` → `mp` does not contain `5`.
- Store `nums[i] = 5` in the map with index `i = 2`: `mp[5] = 2`

Now, the map looks like:
```cpp
mp = {1: 0, 4: 1, 5: 2}
```

### Iteration 4 (`i = 3`):
- `nums[i] = 6`
- `remaining = target - nums[i] = 10 - 6 = 4`
- Check if `remaining = 4` exists in the map: `mp.find(4) != mp.end()` → `mp` contains `{4: 1}`, so it finds `4`.
- Since we found `4`, return `{mp[4], i}` → `{1, 3}`.

The result is `{1, 3}` because `nums[1] + nums[3] = 4 + 6 = 10`, which equals the target.

### Output:
```cpp
{1, 3}
```

### Final state of the map:
```cpp
mp = {1: 0, 4: 1, 5: 2, 6: 3}
```

### Summary:
- The algorithm checks for the complement (i.e., `target - nums[i]`) for each element in the array.
- Once the complement is found in the map, the function returns the indices of the two numbers that sum to the target.
- In this case, it finds that `nums[1] = 4` and `nums[3] = 6` sum up to `10`, so the result is `{1, 3}`.
