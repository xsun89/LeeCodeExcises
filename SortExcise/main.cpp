#include <iostream>


using namespace std;

void maopaosortArray(int* arr, int length){
    int temp;
    for (int i = 0; i < length-1; ++i) {
        for (int j = i+1; j < length; ++j) {
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void gueibinMerge(int* arr, int low, int high)
{

}

void gueibinSort(int* arr, int low, int high)
{
    int mid = (low + high)/2;
    if(mid >= high){
        return;
    }

    gueibinSort(arr, low, mid);
    gueibinSort(arr, mid+1, high);
    gueibinMerge(arr, low, high);

}


int main() {
    int arr[] = {10, 23, 56, 43, 25, 12, 5, 29, 41, 2};
    int len = sizeof(arr)/sizeof(*arr);
    maopaosortArray(arr, len);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << endl;
    }

    return 0;
}