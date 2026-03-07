# Cow Gymnastics

## Problem Source
USACO - [Link to problem](https://usaco.org/index.php?page=viewproblem2&cpid=963)

## Problem Topic
Complete Search

## Problem Difficulty
Bronze - Normal (USACO Guide)

## Solution Info
[CowGymnastics.cpp](CowGymnastics.cpp)
- Language Used: `C++`
- Time Complexity: `O(k * n^3)`
- Space Complexity: `O(k * n)`

## Additional Notes
This could be optimized to `O(k * n^2)` by creating a lookup table instead of calling `getIndex()`.