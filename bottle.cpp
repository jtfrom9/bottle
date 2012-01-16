#include<iostream>
#include<vector>
#include<sstream>
#include<list>

using namespace std;

class bottle
{
    int _max;
    int _level;
    
public:
    bottle(int max, int level): _max(max), _level(level)
    {
    }
    
    string ToString() const {
        stringstream ss;
        ss << "Bottle[" << _max << "]=" <<_level;
        return move(ss.str());
    }

    int Max() const { return _max; }
    int Level() const { return _level; }

    bool operator==(const bottle& b) {
        return (_max==b.Max()) && (_level==b.Level());
    }
};


template<int Num>
class state
{
    vector<bottle> bottles;

public:
    state(initializer_list<bottle> bs) {
        for(auto b : bs)
            bottles.push_back(b);
    }

    bottle& operator[](int index) {
        return bottles[index];
    }
    
    string ToString() const {
        stringstream ss;
        for(auto b : bottles) ss << b.ToString() << ",";
        return move(ss.str());
    }

    bool operator==(const state<Num>& s) {
        for(int i=0; i<Num; i++) {
            if(bottles[i]!=s.bottles[i])
                return false;
        }
        return true;
    }
};

template<typename Type>
class hash
{
    list<Type> _list;

public:
    void add(Type data) {
        if(contains()) {
            cerr << "already has: " << data.ToString() << endl;
            return;
        }
        _list.insert(data);
    }

    bool contains(Type data) {
        auto iter = find_if(_list.begin(), _list.end(),[&](Type d) { return d==data; });
        return iter!=_list.end();
    }
};


void search(list<state<3>>& states, const state<3>& ans)
{
    auto s = states.pop_front();
    if(s==ans)
}

int main()
{
    state<3> init = { bottle(16,16), bottle(9,0), bottle(7,0) };
    state<3> answer = { bottle(16,8), bottle(9,8), bottle(7,0) };

    list<state<3>> states = { init };
    search(states,answer);
}
