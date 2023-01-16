#include<iostream>
#include<time.h>
using namespace std;
void merge(int arr[], int low, int mid, int high){
    int temp[high-low+1];
    int li=low;//left index
    int ri=mid+1;//right index
    int ti=0;//temp index
    while((li<=mid)&&(ri<=high)){
        if (arr[li]<arr[ri]){//elements are from arr[low] to arr[high]
            temp[ti]=arr[li];
            ti++;
            li++;
        }
        else{
            temp[ti]=arr[ri];
            ti++;
            ri++;
        }
    }
    while (li <= mid){//filling rest of temp
        temp[ti] = arr[li];
        ti++;
        li++;
    }
    while (ri<=high){
        temp[ti] = arr[ri];
        ti++;
        ri++;
    }
    for (int i=low;i<=high;i++){//replacing arr[low] to arr[high] with sorted values
        arr[i]=temp[i-low];
    } 
}
void sort(int arr[],int low, int high){
    int mid=(low+high)/2;
    if(low<high){
        sort(arr,low,mid);//sorting left half
        sort(arr,mid+1,high);//sorting right half
        merge(arr,low,mid,high);
    }
}
int main(){
    srand(time(0));
    int arr[500];
    for(int i=0;i<500;i++){
        arr[i]=rand()%1001;
    }
    cout << endl;
    sort(arr,0,499);
    for(int i=0;i<500;i++){
        cout << arr[i] << "\t";
    }
}