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
    int n;
    cin >> n;
    int size = 2 * n - 1;
    vector<ll> v(size);
    for (auto &it: v)
        cin >> it;

    if (n == 1) {
        cout << "Case #" << tc << ": " << 1 << "\n";
        return;
    }

    sort(all(v));

    ll ans = -1;
    map<ll, int>connection;
    map<ll, int>mp;
    int back = v.size() - 1;
    for(int i = 1; i <= v.size() / 2; i++){
        connection[i] = back;
        connection[back] = i;
        mp[v[i] + v[back]]++;
        back--;
    }
    ll x = 0;
    if (mp.size() == 1){
        x = mp.begin()->first - v[0];
        if (x > 0)
            ans = x;
    }

    for(int i = 1; i < v.size(); i++){
        // remove old connection
        ll tmp = v[i] + v[connection[i]];
        mp[tmp]--;
        if (!mp[tmp])
            mp.erase(tmp);

        // create new connection
        int start = i , end = connection[i];
        connection[i - 1] = end;
        connection[end] = i - 1;
        mp[v[i - 1] + v[end]]++;

        // update ans
        if (mp.size() == 1){
            x = mp.begin()->first - v[i];
            if (x > 0){
                if (ans == -1)
                    ans = x;
                else{
                    if (x < ans)
                        ans = x;
                }
            }
        }
    }
    cout << "Case #" << tc << ": " << ans << "\n";
}
//*************
int main(){
    Go();
    int t = 1;
    cin >> t;
    for(int tc = 1; tc <= t; tc++)
        doIt(tc);
}