#include<iostream>
using namespace std;

void InsertionSort (int A[], int n){

for(int i=1; i<n; i++){
    int temp=A[i];
    int j=i-1;

    while(j>=0 && A[j]>temp){
        A[j+1]=A[j];
        j--;
    }
    A[j+1]=temp;
}
}




int main(){

int A[]={4,3,2,5,9,11,10,8};
int n = sizeof(A)/sizeof(A[0]);


InsertionSort(A, n);

for(int i=0; i<n; i++){
    cout<<A[i]<<" ";
}



return 0;
}
