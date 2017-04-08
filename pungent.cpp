/*
	Input number of vertices by adjusting the MACRO value
	eg:
	#define NODES 5
		or
	#define NODES 6
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define NODES 5    // No of vertices
using namespace std;

bool hamiltonian_path(bool adj[][NODES]);
void Print(const vector<int>& v);
vector <int> v;
vector <int>::iterator i;

int main(void) {
	bool adj[NODES][NODES];
	cout << "Feed the graph:" << endl;
	for(int i = 0; i < NODES; i++) {
		for(int j = 0; j < NODES; j++) {
			cin >> adj[i][j];
		}
	}

	if(hamiltonian_path(adj)) {
		cout << "Yes" << endl;
		cout << "Path:" << endl;
		Print(v);
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}

bool hamiltonian_path(bool adj[][NODES]) {
	for(int i = 0; i < NODES; i++) {
		v.push_back(i);
	}
	do {
		bool valid=true;
            for(int i = 0; i < v.size() - 1; i++){
                if(adj[v[i]][v[i+1]] == false){
                    valid=false;
                    break;
                }
							}
            if(valid)
              return true;
  } while(next_permutation(v.begin(), v.end()));
  return false;
}

void Print (const vector<int>& v){
  for (int i=0; i<v.size();i++){
    cout << v[i] << endl;
  }
}