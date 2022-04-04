#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> SelectionSort(vector<int> a){
    for (int i = 0; i < a.size() - 1; i++){
        for (int j = i + 1; j < a.size(); j++){
            if (a[j] < a[i]){
                swap(a[i], a[j]);
            }
        }
    }
    return a;
}

vector<int> InsertSort(vector<int> a){
    for (int i = 1; i < a.size(); i++){
        int new_elem = a[i];
        int j = i - 1;
        while ((j >= 0) and(a[j] > new_elem)){
            a[j + 1] = a[j];
            j -= 1;
        }
        a[j + 1] = new_elem;
    }
    return a;
}

vector<int> SugarSort(vector<int> a){
    vector<int> ans;
    for (int i = 0; i < a.size(); i++){
        int imax = 0;
        for (int j = 0; j < a.size() - i; j++){
            if (a[j] > a[imax]){
                imax = j;
            }
        }
        a.push_back(a[imax]);
        a.erase(a.begin() + imax);
    }
    reverse(a.begin(), a.end());
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector <int> A;
    for (int i = 0; i < n; i++){
        int X;
        cin >> X;
        A.push_back(X);
    }
    for (auto x: SelectionSort(A)){
        cout << x << " ";
    }
    cout << "\n";
    for (auto x: InsertSort(A)){
        cout << x << " ";
    }
    cout << "\n";
    ///сортировка из домашнего задания на 06.04
    for (auto x: SugarSort(A)){
        cout << x << " ";
    }
}
