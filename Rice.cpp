#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

void merge(vector<pair<int,int>>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<pair<int,int>> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i].first * R[j].second < R[j].first * L[i].second ) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(vector<pair<int,int>>& arr, int left, int right){

    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    int k;
    cin >> k;

    vector<pair<int,int>> rice_type;

    for(int i = 0; i < k; i++){
        int p,q;
        cin >> p >> q;
        rice_type.push_back({p,q});
    }

    merge_sort(rice_type, 0, rice_type.size() - 1);

    int m; cin >> m;
    vector<int> seller;
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        seller.push_back(b);
    }

    int count = 0;
    int amount = rice_type[0].second;

    cout << fixed << setprecision(3);

    for (int i = 0; i < m; i++){
        float cost = 0.0;
        int need = seller[i];

        while (need > 0) {
            if (amount >= need) {
                cost += (float)rice_type[count].first / rice_type[count].second * need;
                amount -= need;
                need = 0;
            } else {
                cost += (float)rice_type[count].first / rice_type[count].second * amount;
                need -= amount;
                count++;
                amount = rice_type[count].second;
            }
        }

        cout << cost << "\n";
    }


    return 0;
}