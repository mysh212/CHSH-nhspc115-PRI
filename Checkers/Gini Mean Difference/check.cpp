#include "testlib.h"

using namespace std;

int main(int argc, char * argv[])
{
    setName("compare sequences of tokens");
    registerTestlibCmd(argc, argv);

    int n = 0;
    string j, p;

    while (!ans.seekEof() && !ouf.seekEof()) 
    {
        n++;

        ans.readWordTo(j);
        ouf.readWordTo(p);
        
        if (j != p)
            quitf(_wa, "第 %d 組答案不正確", n);
    }

    if (ans.seekEof() && ouf.seekEof())
    {
        if (n == 1)
            quitf(_ok, "答案是 \"%s\"", compress(j).c_str());
        else
            quitf(_ok, "共有 %d 組答案", n);
    }
    else
    {
        if (ans.seekEof())
            quitf(_wa, "你的程式輸出了多餘的東西?_?");
        else
            quitf(_wa, "你的程式莫名其妙終止了");
    }
}
