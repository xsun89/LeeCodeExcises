#include <iostream>


using namespace std;
int temp[100];

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

void gueibinMerge(int* arr, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int size = 0;
    for(;i<=mid && j<=high; size++){
        if(arr[i] < arr[j]){
            temp[size] = arr[i++];
        }else{
            temp[size] = arr[j++];
        }
    }
    while(i<=mid){
        temp[size++] = arr[i++];
    }
    while(j<=high){
        temp[size++] = arr[j++];
    }

    for(i=0; i<size; i++){
        arr[low+i] = temp[i];
    }
}

void gueibinSort(int* arr, int low, int high)
{
    int mid = (low + high)/2;
    if(mid >= high){
        return;
    }

    gueibinSort(arr, low, mid);
    gueibinSort(arr, mid+1, high);
    gueibinMerge(arr, low, mid, high);

}


int main()
{
    int arr[] = {10, 23, 56, 43, 25, 12, 5, 29, 41, 2};
    int len = sizeof(arr)/sizeof(*arr);
    //maopaosortArray(arr, len);
    gueibinSort(arr, 0, 9);
    for (int i = 0; i < len; ++i) {
        cout << arr[i] << endl;
    }

    return 0;
}