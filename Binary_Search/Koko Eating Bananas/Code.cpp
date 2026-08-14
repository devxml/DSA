class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());

        int start = 1;
        int end = maxi;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long hours = 0;

            for (int i = 0; i < piles.size(); i++) {
                int temp = mid;

                if (piles[i] <= temp) {
                    hours++;
                }
                else {
                    hours += (piles[i] + mid - 1) / mid;
                }
            }

            if (hours <= h) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return start;
    }
};