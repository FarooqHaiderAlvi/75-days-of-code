class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int min1 = nums[0];
        int min2 = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] <= min1) {
                min1 = nums[i];
            } else if (nums[i] <= min2) {
                min2 = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
	Solution obj;
	vector<int> vec = { 20,100,10,12,5,13 };
	cout << obj.increasingTriplet(vec);
}