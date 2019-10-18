#include <iostream>
using namespace std;

void unionn(int x, int y, int v[], int n){
    int rep = v[y];
    for(int i = 0; i < n; i++){
        if(v[i] == rep){
            v[y] = v[x];
        }
    }
}

bool same_set(int x, int y, int v[]){
    if(v[x] == v[y]){
        return true;
    }else{
        return false;
    }
}
int main(){
    int v [7] = {0,1,2,3,4,5,6};
    unionn(2, 4, v, 7);
    for(int i = 0; i < 7; i++){
        cout<<v[i]<<" ";
    }
}
