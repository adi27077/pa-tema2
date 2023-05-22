#include <bits/stdc++.h>
using namespace std;

class Curse {
 public:
    void solve() {
        read_input();
        get_result();
        print_results();
    }

 private:
    static constexpr int MMAX = (int)1e4+5;  // nr maxim de noduri (masini)
    /*
    m - nr de masini (nodurile din graf)
    n - nr de piste
    a - nr de antrenamente
    */
    int m, n, a;

    // adj[node] = lista de adiacenta a nodului node
    // exemplu: daca adj[node] = {..., neigh, ...} => exista arcul (node, neigh)
    vector<int> adj[MMAX];

    vector<int> topsort;

    void get_result() {
        solve_dfs();
    }

    void solve_dfs() {
        // vectorul rezultat (in final contine o permutare pentru 1, 2, ..., m)
        topsort.reserve(m + 1);

        // used[node] = 1 daca node a fost deja vizitat, 0 altfel
        vector<int> used(m + 1, 0);

        // pentru fiecare nod
        for (int node = 1; node <= m; ++node) {
            // daca nodul este nevizitat, pornim o parcurgere
            if (!used[node]) {
                dfs(node, used, topsort);
            }
        }

        // rezultatul a fost obtinut in ordine inversa
        reverse(topsort.begin(), topsort.end());
    }

    void dfs(int node, vector<int> &used, vector<int> &topsort) {
        used[node] = 1;  // marcheze nodul ca fiind vizitat

        // parcurg vecinii
        for (auto &neigh : adj[node]) {
            if (!used[neigh]) {
                dfs(neigh, used, topsort);
            }
        }

        // dupa ce am vizitat recursiv toti vecinii, adaugam
        // nodul la sortare
        topsort.push_back(node);
    }

    void read_input() {
        ifstream fin("curse.in");
        fin >> n >> m >> a;
        vector<int> current(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for (int j = 1; j <= n; j++) {
            fin >> prev[j];
        }

        for (int i = 1; i < a; i++) {
            for (int j = 1; j <= n; j++) {
                fin >> current[j];
            }

            for (int j = 1; j <= n; j++) {
                if (current[j] != prev[j]) {
                    adj[prev[j]].push_back(current[j]);
                    break;
                }
            }

            prev = current;
        }

        fin.close();
    }

    void print_results() {
        ofstream fout("curse.out");
        for (const auto &node : topsort) {
            fout << node << ' ';
        }
        fout << '\n';
        fout.close();
    }
};

int main() {
    auto* curse = new (nothrow) Curse();
    if (!curse) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    curse->solve();
    delete curse;

    return 0;
}
