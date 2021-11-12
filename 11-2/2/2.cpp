#include<iostream>
#include<string>
#include<map>
using namespace std;

class TestProblem {
    private:
        map<string, int> subScore;
        int problemScore;
        static int totalScore;
    public:
        TestProblem():problemScore(0) { }
        TestProblem(const TestProblem& testProblem) //write copy constructor
        {
            subScore=testProblem.subScore;
            problemScore=testProblem.problemScore;
        }
        void setSubScore(string key,int _score) 
        {
            if(subScore.find(key) != subScore.end()) totalScore-=subScore[key], problemScore-=subScore[key];
            totalScore+=subScore[key]=_score, problemScore+=_score;
        }
        int getProblemScore()
        {
            return problemScore;
        }
        void show()
        {
            for(auto it : subScore)
                cout << it.first << " : " << it.second << '\n';
        }
        static void showTotalScore() 
        {
            cout <<"total score : "<< totalScore << endl;
        }
};

int TestProblem::totalScore=0;

int main() {
    TestProblem problem1;
    TestProblem problem2 = problem1;
    problem1.setSubScore("subScore1", 30);
    problem1.setSubScore("subScore2", 40);
    problem2.setSubScore("subScore1", 20);
    problem2.setSubScore("subScore2", 40);
    problem1.show();
    cout << "problem1 score : " << problem1.getProblemScore() << endl;
    problem2.show();
    cout << "problem2 score : " << problem2.getProblemScore() << endl;;
    problem1.showTotalScore();
    return 0;
}