// To implement sorting algorithms
#include<iostream>
#include<vector>
class Sorting {
private:
    static int partitionThreeWay(std::vector<int>& arr, int left, int right){
        int key = arr[right];
        int i = left;
        int j = right - 1;
        int k = left;
        //
        while(k <= j){
            if(arr[k] > key){
                std::swap(arr[k], arr[j]);
                j--;
            } else {
                if(arr[k] < key){
                    std::swap(arr[i],arr[k]);
                    k++;
                    i++;
                } else {
                    k++;
                }
            }
        }
        std::swap(arr[right],arr[k]);
        return k;
    }
    static int partitionRightPivot(std::vector<int>& arr, int left, int right){
        int key = arr[right];
        int pivot = left;
        for(int i=left; i<right; i++){
            if(arr[i] <= key){
                std::swap(arr[i],arr[pivot]);
                pivot++;
            }
        }
        std::swap(arr[pivot],arr[right]);
        return pivot;
    }
public:
    // quick sort with various partition scheme
    static void quickSort(std::vector<int>& arr, int left, int right){
        if(left > right) return; 
        //
        // int pivot = partitionRightPivot(arr,left,right);
        int pivot = partitionThreeWay(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot+1,right);
    }
};

int main(int argc, char** argv){
    // std::vector<int> arr = {4,7,6,2,5,5,9,1,0};
    // std::vector<int> arr = {0,1,1,2,3,4,5,5,6};
    std::vector<int> arr = {1,2,3,4,4,4,4,4,4,4,4,4,4,4,5,6};
    // std::vector<int> arr = {6,5,4,3,2,1,0};
    //
    Sorting::quickSort(arr,0,arr.size()-1);
    // display
    for(auto a : arr) std::cout << a << ", ";
    std::cout << std::endl;
    return 0;
}