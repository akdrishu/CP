#include <bits/stdc++.h>

using namespace std;
#define debug(...) cout<< " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] " ;
class heap {
public:
    int sz, cap;
    int *a;

    heap(int capacity) {
        this->cap = capacity;
        sz = 0;
        a = new int[capacity];
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void build(int ind) {
        int par = parent(ind);
        while (a[par] > a[ind]) {
            swap(a[par], a[ind]);
            ind = par;
            par = parent(ind);
        }
    }

    void heapify(int ind, int siz) {
        if (left(ind) >= siz and right(ind) >= siz) return;
        if (right(ind) >= siz) {
            if (a[ind] > a[left(ind)]) {
                swap(a[ind], a[left(ind)]);
                heapify(left(ind), siz);
                return;
            } else return;
        }
        if (a[left(ind)] >= a[ind] && a[right(ind)] >= a[ind]) return;
        else {
            (a[right(ind)] <= a[left(ind)] && a[right(ind)] < a[ind] ? swap(a[ind], a[right(ind)]), heapify(right(ind),
                                                                                                            siz)
                                                                     : swap(a[ind], a[left(ind)]), heapify(left(ind),
                                                                                                           siz));
        }
    }

    void insert(int val) {
        if (sz >= cap) return;
        a[sz] = val;
        build(sz);
        sz++;
    }

    int find_max() {
        if (sz == 0) return -1;
        int xx = a[0];
        a[0] = a[sz - 1];
        sz--;
        heapify(0, sz);
        return xx;
    }

    void del(int x) {
        a[x] = a[sz - 1];
        sz--;
        heapify(x, sz);
    }

    void print() {
        for (int i = 0; i < sz; i++) cout << a[i] << " ";
        cout << endl;
    }
};

string rearrangeString(string str){
    auto cmp= [&](pair<char,int> &a, pair<char,int> &b){
        if(a.second==b.second)    return a.first<b.first;
        return a.second<b.second;
    };
    priority_queue<pair<char, int>, vector<pair<char,int>>, decltype(cmp)> temp(cmp);
    unordered_map<char,int> fre;
    for(auto &x:str)    fre[x]++;

    for(auto &x: fre)   temp.push(x);
    string ans="";
    while(!temp.empty()){
        char curr= temp.top().first;
        ans+=curr;
        pair<char,int> now= temp.top();
        now.second()--;
        if(now.second!=0)  {
            temp.push(a);
        }
    }
    cout<<ans<<endl;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    heap tar(10);
    tar.insert(5);
    tar.insert(4);
    tar.insert(3);
    tar.insert(2);
    tar.insert(1);
    tar.print();

    tar.print();
}