#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    registerTestlibCmd(argc, argv);

    vector<string> input;

    while (!inf.seekEof()) {
        input.push_back(inf.readLine());
    }

    if (input.empty()) {
        quitf(_fail, "Invalid empty input.");
    }

    int n = (int)input.size();

    if (n < 1 || n > 1000) {
        quitf(_fail, "Invalid number of input lines.");
    }

    int rows = 0;

    for (const string &s : input) {
        rows = max(rows, (int)s.size());
    }

    for (int i = 0; i < rows; ++i) {
        string expected = ans.readLine();
        string contestant = ouf.readLine();

        if (expected != contestant) {
            quitf(
                _wa,
                "Wrong answer on output line %d.",
                i + 1
            );
        }
    }

    ans.readEof();
    ouf.readEof();

    quitf(_ok, "Correct.");
}