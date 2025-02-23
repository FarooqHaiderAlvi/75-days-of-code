#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:

	vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
		vector<vector<int>> result(2);
		unordered_set<int> set1;
		for (int i = 0;i < nums1.size();i++) {
			set1.insert(nums1[i]);
		}
		unordered_set<int> set2;
		for (int i = 0;i < nums2.size();i++) {
			set2.insert(nums2[i]);
		}

		for (auto it = set1.begin(); it != set1.end(); ++it) {
			if (set2.find(*it) == set2.end()) {
				result[0].push_back(*it);
			}
		}

		for (auto it = set2.begin(); it != set2.end(); ++it) {
			if (set1.find(*it) == set2.end()) {
				result[1].push_back(*it);
			}
		}
		return result;
	}
};

int main() {
	vector<int> v1 = { 1,2,3 };
	vector<int> v2 = { 2,4,6 };
	Solution obj;
	obj.findDifference(v1, v2);
}