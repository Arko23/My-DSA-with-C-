#include <iostream>
using namespace std;

void Tower_Hanoi(int n, string s, string midt, string f)
{
    if (n == 1)
    {
        cout << "plate transfered " << n << " from  : " << s << " -> " << f << endl;
        return;
    }
    Tower_Hanoi(n - 1, s, f, midt);

    cout << "plates transferd " << n << " from  : " << s << " -> " << f << endl;

    Tower_Hanoi(n - 1, midt, s, f);
}

int main()
{
    int n;
    cout << "take input : ";
    cin >> n;

    Tower_Hanoi(n, "start tower", "mid tower", "final tower");
}
