#include <iostream>
#include <vector>
using namespace std;

int main(){
    int l, h; 
    cin >> l >> h;

    vector<vector<char>> map(l, vector<char>(h));

    for (int i = 0; i < h; i++){
        string input; 
        cin >> input;

        for (int j = 0; j < l; j++){
            map[i][j] = input[j];
        }
    }

    vector<string> checking_word;

    string word;
    while (cin >> word){
        checking_word.push_back(word);
    }


    

    
    // for (int i = 0; i < l; i++){
    //     cout << "{ ";
    //     for (int j = 0; j < h; j++){
    //         cout << map[i][j];
    //     }
    //     cout << " }" << endl;
    // }

    // for (int i = 0; i < checking_word.size(); i++){
    //     cout << "{ ";
    //     cout << checking_word[i];
    //     cout << " }" << endl;
    // }

    return 0;
}