#include <bits/stdc++.h>

using namespace std;

class QuizAttempt 
{
protected:
    char ID[7];
public:
    QuizAttempt(char *id)
    {
        strcpy(this->ID, id);
    }
    virtual void print() = 0;
    virtual double score() = 0;
    bool operator >= (QuizAttempt &attempt)
    {
        return this->score() >= attempt.score();
    }
};

class MCQuizAttempt : public QuizAttempt
{
private:
    char ok[11];
    char ans[11];
public:
    MCQuizAttempt(char *id, char *ok, char *ans) : QuizAttempt(id)
    {
        strcpy(this->ok, ok);
        strcpy(this->ans, ans);
    }
    void print()
    {
        for(int i=0;i<10;i++)
        {
            cout<<i+1<<". "<<"ok: "<<ok[i]<<" Answer: "<<ans[i]<<" Points: "<<(ok[i] == ans[i] ? 1 : -0.25)<<endl;
        }
        cout<<"Total score: "<<score()<<endl;
    }
    double score()
    {
        double cnt=0;
        for(int i=0;i<10;i++)
        {
            if(ok[i]==ans[i])
            {
                cnt+=1;
            }
            else
            {
                cnt-=0.25;
            }
        }
        return cnt;
    }
};

class TFQuizAttempt : public QuizAttempt
{
private:
    bool ok[10];
    bool ans[10];
public:
    TFQuizAttempt(char *id, bool *ok, bool *ans) : QuizAttempt(id)
    {
        for(int i=0;i<10;i++)
        {
            this->ok[i]=ok[i];
            this->ans[i]=ans[i];
        }
    }
    void print()
    {
        for(int i=0;i<10;i++)
        {
            cout<<i + 1<<". "<<"ok: "<<(ok[i] ? "True" : "False")<<" Answer: "<<(ans[i] ? "ok" : "False")<<" Points: "<<(ok[i] == ans[i] ? 1 : -0.5)<<endl;
        }
        cout<<"Total score: "<<score()<<endl;
    }
    double score()
    {
        double cnt=0;
        for(int i=0;i<10;i++)
        {
            if(ok[i]==ans[i])
            {
                cnt+=1;
            }
            else
            {
                cnt-=0.5;
            }
        }
        return cnt;
    }
};

double averagePointsOfPassedStudents(QuizAttempt **attempts, int n)
{
    double sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(attempts[i]->score()>=5.0)
        {
            sum+=attempts[i]->score();
            cnt++;
        }
    }
    return sum/cnt;
}

QuizAttempt *readMCQuizAttempt()
{
    char ID[7];
    char ok[11];
    char ans[11];
    cin>>ID>>ok>>ans;
    return new MCQuizAttempt(ID, ok, ans);
}

QuizAttempt *readTFQuizAttempt()
{
    char ID[7];
    bool ok[10];
    bool ans[10];
    cin>>ID;
    for(int i=0;i<10;i++)
    {
        cin>>ok[i];
    }
    for(int i=0;i<10;i++)
    {
        cin>>ans[i];
    }
    return new TFQuizAttempt(ID, ok, ans);
}

signed main() ///kopiram test input od zadacata
{
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "Test MCQuizAttempt" << endl;
        QuizAttempt *attempt = readMCQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 2) {
        cout << "Test TFQuizAttempt" << endl;
        QuizAttempt *attempt = readTFQuizAttempt();
        cout << "Score: " << attempt->score() << endl;
        attempt->print();
    } else if (testCase == 3) {
        cout << "Test operator >=" << endl;
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*attempts[i]) >= (*attempts[j])) {
                        cout << i << " >= " << j << endl;
                    } else {
                        cout << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        cin >> n;
        QuizAttempt **attempts = new QuizAttempt *[n];
        for (int i = 0; i < n; i++) {
            int type;
            cin >> type;
            if (type == 1) {
                attempts[i] = readMCQuizAttempt();
            } else {
                attempts[i] = readTFQuizAttempt();
            }
            attempts[i]->print();
            cout << endl;
        }

        cout << "Average score of passed students is: " << averagePointsOfPassedStudents(attempts, n) << endl;
    }

    return 0;
}
