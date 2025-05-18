#include<iostream>
using namespace std;


int partitionn(int A[], int l, int h){

int pivot=A[l];
int i=l;
int j=h;

while(i<j){
    while(A[i]<=pivot){
        i++;
    }
    while(A[j]>pivot){
        j--;
    }
    if(i<j){
        swap(A[i], A[j]);
    }
}
swap(A[l], A[j]);
return j;

}



void Quicksort(int A[],int l,int h){
if(l<h){

int j = partitionn(A, l, h);
Quicksort(A, l, j-1);
Quicksort(A, j+1, h);

}
}



int main(){

int A[]={3,4,11,6,7,9,8};

int n=sizeof(A)/sizeof(A[0]);

Quicksort(A,0,n-1);

for(int i=0; i<n; i++){
    cout<<A[i]<<" ";
}
return 0;
}

