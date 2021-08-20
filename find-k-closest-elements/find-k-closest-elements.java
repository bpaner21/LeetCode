class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        
        int left = 0, right = arr.length - k, mid;
        
        while (left < right) {
            
            mid = left + ((right - left) / 2);
            
            if (x - arr[mid] > arr[mid + k] - x) { left = mid + 1;}
            
            else { right = mid;}
        }
        
        return Arrays.stream(arr, left, left + k).boxed().collect(Collectors.toList());
    }
}

/*

This is a sliding window problem, 

where k is the size of the window

because of the constraint [[ a is closer to x than an integer b if |a - x| == |b - x| and a < b ]], smaller integers are preferred

Ex. if x = 3, arr = [1,2,3,4,5], then 1 and 2 are closer to x than 4 and 5

Run a binary search with a window of size k using this comparison: if (x - arr[mid] > arr[mid + k] - x)

this will eventually narrow down until it reaches the optimal window around the k integers closest to x

---

int[] to List<Integer> conversion found on: https://www.techiedelight.com/convert-int-array-list-integer/

*/