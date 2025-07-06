// LEETCODE QUES 1865. Finding Pairs With a Certain Sum
// medium

// You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

// Add a positive integer to an element of a given index in the array nums2.
// Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
// Implement the FindSumPairs class:

// FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
// void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
// int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

class FindSumPairs {
  // here we have created map so that we can use two sum in count. but in 
  // count map will be called repeatedly => thus giving us tle. so to avoid that we will use map in starting of class itself
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for(int nums:nums2) {
            freq[nums]++;
        }
    }
    
    void add(int index, int val) {
        int old=nums2[index];
        nums2[index]+=val;

        freq[old]--;
        if(freq[old]==0) {
            freq.erase(old);
        }

        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int result=0;
        for(int i=0; i<nums1.size(); i++) {
            int temp=tot-nums1[i];
            if(freq.count(temp)) {
                result+=freq[temp];
            }
        }
        return result;
    }
};
