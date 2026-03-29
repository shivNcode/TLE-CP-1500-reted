#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Solve()
{
    int lx = 0, rx = 1e9, ly = 0, ry = 1e9;

    while(true) {

        int midx = lx + (rx - lx) / 2;
        int midy = ly + (ry - ly) / 2;


        cout << "? " << midx << " " << midy << endl;

        string str;
        cin >> str;

        if (str == "LEFT") {
            rx = midx - 1;
            ly = ry = midy;
        }
        else if (str == "RIGHT") {
            lx = midx + 1;
            ly = ry = midy;
        }
        else if (str == "UP") {
            ly = midy + 1;
            lx = rx = midx;
        }
        else if (str == "DOWN") {
            ry = midy - 1;
            lx = rx = midx;
        }
        else if (str == "LEFT_DOWN") {
            rx = midx - 1;
            ry = midy - 1;
        }
        else if (str == "LEFT_UP") {
            rx = midx - 1;
            ly = midy + 1;
        }
        else if (str == "RIGHT_DOWN") {
            lx = midx + 1;
            ry = midy - 1;
        }
        else if (str == "RIGHT_UP") {
            lx = midx + 1;
            ly = midy + 1;
        }
        else if (str == "HERE") {

            cout << "! " << midx << " " << midy << endl;
            return;
        }
        else {

            break;
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    Solve();

    return 0;
}