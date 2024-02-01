#include <iostream>
using namespace std;

#define ll  long long
#define all(v) v.begin(),v.end()
void Go() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
//*************
void doIt(int tc) {
    ll r, c, a, b;
    cin >> r >> c >> a >> b;
    cout << "Case #" << tc << ": ";
    cout << (c < r ? "YES\n" : "NO\n");
}
//*************
int main(){
    Go();
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
        doIt(tc);
}