/*#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; if(!(cin>>n) || n<=0) return 0;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i; // original index
    }
    sort(v.begin(), v.end()); // sorts by value, keeping original index
    int target; cin >> target;

    int left = 0, right = n - 1, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (v[mid].first == target) { ans = v[mid].second; break; }
        else if (v[mid].first < target) left = mid + 1;
        else right = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
    

#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    size_t n;
    cin >> n;
    vector<size_t> vec(n);
    for(auto& x : vec) cin >> x;
    size_t element;
    cin >> element;
auto it = std::find(vec.begin(), vec.end(), element);
if (it != vec.end()) {
    int index = std::distance(vec.begin(), it); // Or (it - vec.begin())
    std::cout << "Index: " << index << std::endl; 
}
}
*/


/*
Question: Given a sorted array of size N find the index of the number in the array which is just greater than x and as close as possible to x.
--> Upper Bound(x) = return index of the number which is just greater tha x and as close as possible to x.



#include <bits/stdc++.h>
using namespace std;

void upperbound(vector<int>& arr, int x) {
    int left = 0, right = arr.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left < arr.size()) {
        cout << left << " \n" << arr[left] << '\n';
    } else {
        cout <<  x << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int x; cin >> x;

    upperbound(arr, x);

    return 0;
}


//Optimized Code using STL
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t upper_bound_index(const vector<int>& arr, int x) {
    auto it = upper_bound(arr.begin(), arr.end(), x);
    return static_cast<size_t>(distance(arr.begin(), it)); // returns arr.size() if not found
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int x; cin >> x;

    // Ensure array is sorted before calling upper_bound (if not guaranteed)
    // sort(arr.begin(), arr.end());

    size_t idx = upper_bound_index(arr, x);
    if (idx < arr.size()) {
        cout << idx << '\n' << arr[idx] << '\n';
    } else {
        cout << -1 << '\n'; // or any sentinel/message you prefer
    }
    return 0;
}

*/

/*
Question: Search in a rotated sorted array
There is an integer array nums sorted in ascending order with distinct values.
Prior to being passed to your function, nums is possibly rotated at an unknown pivot 
index k ( 0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1],
..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].





#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(const vector<int>& nums, int target) {
    const int n = static_cast<int>(nums.size());
    if (n == 0) return -1;

    // 1) find pivot: index of smallest element
    int l = 0, r = n - 1;
    while (l < r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] > nums[r]) l = m + 1;
        else r = m;
    }
    int pivot = l;

    // 2) choose which half to binary search
    int left, right;
    if (target >= nums[pivot] && target <= nums[n - 1]) {
        left = pivot;
        right = n - 1;
    } else {
        left = 0;
        right = pivot - 1;
    }

    // 3) standard binary search on chosen interval
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int target; cin >> target;

    cout << searchInRotatedSortedArray(nums, target) << '\n';
    return 0;
}

*/