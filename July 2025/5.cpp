// LEETCODE 1394. Find Lucky Integer in an Array
// easy

//Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
//Return the largest lucky integer in the array. If there is no lucky integer return -1.

// 1st solution with a map to count frequencies
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxi=-1;
        map<int, int> mp;

        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }

        for(auto i:mp) {
            if(i.second==i.first) {
                maxi=i.first;
            }
        }

        return maxi;
    }
};
// here map was taking space 
// TC = O(n) SC = O(n)


// 2nd optimal solution. frequency counting + linear scan
class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int cnt=1;
        int maxi=-1;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i]==arr[i-1]) {
                cnt++;
            }
            else {
                if(cnt==arr[i-1]) {
                    maxi=cnt;
                }
                cnt=1;
            }
        }

        if(cnt==arr[arr.size()-1]) {
            maxi=cnt;
        }
        return maxi;
    }
};
// TC = O(nLogn) SC = O(1)
