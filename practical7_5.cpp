#include <iostream>
#include <vector>
using namespace std;

class Grading {
protected:
    float marks;
public:
    virtual void input() = 0;
    virtual void computeGrade() = 0;
    virtual ~Grading() {}
};

class Undergraduate : public Grading {
public:
    void input() {
        cin >> marks;
    }
    void computeGrade() {
        if (marks >= 85) cout << "Grade: A\n";
        else if (marks >= 70) cout << "Grade: B\n";
        else if (marks >= 55) cout << "Grade: C\n";
        else if (marks >= 40) cout << "Grade: D\n";
        else cout << "Grade: F\n";
    }
};

class Postgraduate : public Grading {
public:
    void input() {
        cin >> marks;
    }
    void computeGrade() {
        if (marks >= 90) cout << "Grade: A\n";
        else if (marks >= 75) cout << "Grade: B\n";
        else if (marks >= 60) cout << "Grade: C\n";
        else if (marks >= 50) cout << "Grade: D\n";
        else cout << "Grade: F\n";
    }
};

int main() {
    int n, type;
    cin >> n;
    vector<Grading*> students;
    for (int i = 0; i < n; i++) {
        cin >> type;
        Grading* g;

        if (type == 1)
            g = new Undergraduate();
        else
            g = new Postgraduate();

        g->input();
        students.push_back(g);
    }
    for (auto s : students) {
        s->computeGrade();
    }
    for (auto s : students) {
        delete s;
    }
    return 0;
}