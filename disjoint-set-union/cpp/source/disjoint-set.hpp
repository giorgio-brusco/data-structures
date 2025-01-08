#include <vector>

using namespace std;

class dsu{
       
    vector<int> parent;
    vector<int> size;
    int max_size;

  public:
  
    dsu(int n);
    dsu(const vector<int>& parent_init);
    int find(int x);
    void unite(int x, int y);
    int maxSize();

    // function to access parent for unit test
    const vector<int>& getParent();

};