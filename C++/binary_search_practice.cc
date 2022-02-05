#include <vector>
using namespace std;
class binarySearch{
public:
    int binary_search_recursive(vector<int>& sorted_array, int begin, int end, int target){
        if(begin>end)   return -1;
        int mid = (end-begin)/2 + begin;
        if(target == sorted_array[mid]){
            return mid;
        }
        else if(target > sorted_array[mid]){
            return binary_search_recursive(sorted_array, mid+1, end, target);
        }
        else{
            return binary_search_recursive(sorted_array, begin, mid-1, target);
        }
    }

    int binary_search_iterative(vector<int>& sorted_array, int target){
        int begin = 0;
        int end = sorted_array.size()-1;
        while(begin<=end){
            int mid = (end-begin)/2 + begin;
            if(target == sorted_array[mid]){
                return mid;
            }
            else if(target > sorted_array[mid]){
                begin = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};
