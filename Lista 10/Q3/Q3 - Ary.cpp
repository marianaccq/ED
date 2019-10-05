#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr[]. N is size of heap
void descer(int arr[], int n, int i)
{
    int largest = i; // começamos pela raiz
    int l = 2 * i + 1; // obtem o filho esquerdo de i
    int r = 2 * i + 2; // obtem o filho direito de i
    // se o filho esqurdo for maior que a raiz
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // se o filho esquedo tem prioridade maior que a raiz ou o filho esquerdo
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // se o de maior prioridade não for a raiz
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // realiza o procedimento recursivamente
        descer(arr, n, largest);
    }
}


void print(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout<<""<<endl;

}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        descer(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        descer(arr, i, 0);
    }
}
int main()
{
    // Array representando a maxheap
    // 10
    //    /  \
    // 5    3
    //  / \
    // 2   4
    int arr[] = { 10, 5, 3, 2, 4, 6, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);
    cout<<"Ordenado pelo heapSort"<<endl;
    heapSort(arr, n);
    print(arr, n);
    return 0;
}
