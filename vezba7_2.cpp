#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User
{
    string username;
    string company;
    int level;

    void copy(const User &u)
    {
        this->username = u.username;
        this->company = u.company;
        this->level = u.level;
    }

public:
    User(const string& username="", const string& company="", int level=1)
    {
        this->username = username;
        this->company = company;
        this->level = level;
    }

    User(const User& u)
    {
        copy(u);
    }

    User& operator=(const User& u)
    {
        if(&u!=this)
        {
            copy(u);
        }
        return *this;
    }

    const string& getUsername() const{return username;}
    const string& getCompany() const{return company;}
    int getLevel() const{return level;}

    void setUsername(const string& username){this->username = username;}
    void setCompany(const string& company){this->company = company;}
    void setLevel(int level){ if(level>=1&&level<=10) this->level = level;}

    friend ostream& operator<<(ostream& out, const User& u)
    {
        out << u.username << " " << u.company << " " << u.level;
        return out;
    }
    friend istream& operator >>(istream& in, User& u)
    {
        in>>u.username>>u.company>>u.level;
        return in;
    }

    bool operator==(const User& u) const
    {
        return this->username == u.username;
    }

};


class Group
{
protected:
    vector<User> user;
    int n;
    string name;

    void copy(const Group& u)
    {
        this->name = u.name;
        this->user = u.user;
        this->n = u.n;
    }

public:
    Group(const string& name="")
    {
        this->name = name;
        this->n = 0;
    }

    Group(const Group&u)
    {
        copy(u);
    }

    Group& operator=(const Group& u)
    {
        if(this!=&u) copy(u);
        return *this;
    }

    virtual void addMember(const User& u)
    {
        for(int i=0;i<n;i++)
        {
            if(user[i]==u)return;
        }
        user.push_back(u);
        n++;
    }

    double getavg() const
    {
        if(n==0)return 0;
        int sum=0;
        for(auto &u:user)sum+=u.getLevel();
        return static_cast<double>(sum)/n;
    }

    virtual double rating() const
    {
        double avg=getavg();
        return (10.0-avg)*n/100;
    }

    friend ostream &operator<<(ostream &out, const Group &g)
    {
        out << "Group: " << g.name << endl;
        out << "Members: " << g.n << endl;
        out << "Rating: " << g.rating() << endl;
        out << "Members list: " << endl;
        if (g.n == 0) {
            out << "EMPTY" << endl;
        } else {
            for (int i = 0; i < g.n; i++) {
                out << i + 1 << ". " << g.user[i] << endl;
            }
        }

        return out;
    }

};

class PrivateGroup : public Group
{
protected:
    static int capacity;
    static const float coefficient;

public:
    PrivateGroup(const string& name=""): Group(name){}
    PrivateGroup(const PrivateGroup& u): Group(u){}
    PrivateGroup& operator=(const PrivateGroup& u)
    {
        if(this!=&u)
        {
            Group::operator=(u);
        }
        return *this;
    }

    static void setcapacity(int c)
    {
        capacity = c;
    }

    virtual void addMember(const User& u)
    {
        if(n<capacity)
        {
            Group::addMember(u);
        }
    }

    virtual double rating() const
    {
        double avg=getavg();
        return (10.0-avg)*(static_cast<double>(n)/capacity)*coefficient;
    }

    friend ostream& operator<<(ostream& out,const PrivateGroup& u)
    {
        Group g=static_cast<Group>(u);
        out<<g;
        return out;
    }
};

int PrivateGroup::capacity=10;
const float PrivateGroup::coefficient = 0.8;

int main()
{
    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) {
            groups[i] = new Group(name);
        } else { 
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);

        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setcapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
}