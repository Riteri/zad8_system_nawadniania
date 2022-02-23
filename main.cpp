#include <iostream>
#include <vector>
#define GORNY_PRZEDZIAL 1999999999

using namespace std;

int n;
int answer = GORNY_PRZEDZIAL;
vector < pair < int , int > > a;




void go(int ind, int est, int cena)
{
    cena += a[ind].second;
    est += a[ind].first;
    if (cena  > answer) return;
    if (est == 0 )
    {
        if (cena < answer)
        {
            answer = cena;
        }
        return;
    }
    for (int i = ind + 1; i < n; i++)
    {
        go(i, est , cena);
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        a.clear();
        answer = GORNY_PRZEDZIAL;
        cin >> n;
        for (int h = 0; h < n; h++)
        {
            int x , y;
            cin >> x >> y;
            a.push_back({x,y});
        }
        for (int j = 0; j < n; j++)
        {
            go(j , 0 , 0);
        }
        if (answer == GORNY_PRZEDZIAL)
        {
            cout << "NIE" <<endl;
        } else cout << answer<<endl;
    }
    return 0;
}

