#include <iostream>

using namespace std;

void FW(int **l, int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&i!=k&&j!=k){
                    if(l[i][j] > (l[i][k]+l[k][j])){
                        l[i][j] = l[i][k]+l[k][j];
                    }
                }
            }
        }
        cout<<"k = "<<k<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<l[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;

    }
}

int main()
{
    int n = 6;
    int **grf = new int*[n];
    for(int i=0;i<n;i++){
        grf[i] = new int[n];
    }
    cout<<"inserir grafo"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grf[i][j];
        }
    }
    cout<<endl<<endl;
    FW(grf,n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grf[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
