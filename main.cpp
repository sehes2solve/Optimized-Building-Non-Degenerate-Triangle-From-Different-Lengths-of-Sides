#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canFormTriangle_BruteForce( vector<int>& sides) {
    for (int i = 0; i < sides.size(); i++) {
        int S1 = sides[i];
        for (int j = 0; j < sides.size(); j++) {
            int S2 = sides[j];
            if (S2 == S1) { continue; }
            for (int k = 0; k < sides.size(); k++) {
                int S3 = sides[k];
                if (S3 == S2 || S3 == S1) { continue; }
                if (S1 + S2 > S3 &&
                    S2 + S3 > S1 &&
                    S3 + S1 > S2) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool canFormTriangle_lessComplex(vector<int>& sides) {
    sort(sides.begin(), sides.end());
    int f = sides.size() - 1;
    while (f > 0) {
        int i = 0, j = f - 1;
        while (i < j) {
            if (sides[i] + sides[j] > sides[f]) {
                return true;
            }
            else {
                i++;
            }
        }
        f--;
    }
    return false;
}

int main() {
    vector<int> set_1;
    set_1.push_back(1);
    set_1.push_back(2);

    cout << canFormTriangle_BruteForce(set_1) << endl;
    cout << canFormTriangle_lessComplex(set_1) << endl;

    vector<int> set_2;
    set_2.push_back(5);
    set_2.push_back(4);
    set_2.push_back(3);
    set_2.push_back(1);
    set_2.push_back(2);

    cout << canFormTriangle_BruteForce(set_2) << endl;
    cout << canFormTriangle_lessComplex(set_2) << endl;

    return 0;
}
