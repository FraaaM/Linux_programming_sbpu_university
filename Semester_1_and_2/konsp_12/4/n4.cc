#include <iostream>
#include <climits>

using namespace std;

void fn(int* X) {
        cout << *X << " # ";

        unsigned char* unit = reinterpret_cast<unsigned char*>(X);

        for (int i = 3; i >= 0; i--) cout << (unsigned int) * (unit + i) << " ";
        cout << '\n';
}

int main() {
        int x = INT_MAX;
        int* X = &x;
        fn(X);
        x = -x;
        fn(X);
        return 0;
}
