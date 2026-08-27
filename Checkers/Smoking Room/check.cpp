#include "testlib.h"
#include <string>

using namespace std;

const string YES = "YES";
const string NO = "NO";

int main(int argc, char * argv[])
{
    setName((YES + " or " + NO + " (case insensetive)").c_str());
    registerTestlibCmd(argc, argv);

    std::string ja = upperCase(ans.readWord());
    std::string pa = upperCase(ouf.readWord());

    if (ja != YES && ja != NO)
        quitf(_fail, "答案應該要是 %s 或 %s ，但你的程式輸出了莫名其妙的東西", YES.c_str(), NO.c_str());

    if (pa != YES && pa != NO)
        quitf(_pe, "答案應該要是 %s 或 %s ，但你的程式輸出了莫名其妙的東西", YES.c_str(), NO.c_str());

    if (ja != pa)
        quitf(_wa, "答案錯誤");

    quitf(_ok, "答案正確，答案是 %s", ja.c_str());
}
