#include<iostream>
using namspace std;

int rotateImage(int matrix[3][3], int n){
    int ans[3][3];
    for(int i =0; i<n; i++){
        for(int j = 0; j<n; j++){
            ans[j][n-1-i]=matrix[i][j];
        }
    }
    return ans;
}

int main(){ 
    int matrix[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    rotateImage(matrix, 3);
    for(int i =0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<matrix[i][j]<<" ";
        }
    }
}