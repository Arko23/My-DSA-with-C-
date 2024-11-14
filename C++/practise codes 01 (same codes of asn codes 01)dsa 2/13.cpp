#include <iostream>
using namespace std;
void even(int s, int e)
{
    if (s > e)

        return;
    if (s % 2 == 0)
        cout << s << " ";
    even(s + 1, e);
}
int main()
{
    int n, m;
    cout << "starting number = ";
    cin >> n;
    cout << "ending number = ";
    cin >> m;
    cout << "outputs between starting and ending range are =" ;
    even(n, m);
}