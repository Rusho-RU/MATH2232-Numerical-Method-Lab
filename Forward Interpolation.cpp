#include <bits/stdc++.h>
using namespace std;

class ForwardInterpolation{
    private : double table[12][12], factorial[13], reverseFactorial[13];
    private : vector<double>x,y;

    public : ForwardInterpolation(){
        memset(table, 0, sizeof table);
        factorial[0] = 1;
        for(int i=1; i<13; i++)
            factorial[i] = factorial[i-1] * i;
    }

    public : void addXY(int a, int b){
        x.push_back(a);
        y.push_back(b);
        table[y.size()-1][0] = b;
    }

    private : void makeDifferenceTable(){
        for(int i=1; i<y.size(); i++)
            for(int j=i; j<y.size(); j++)
                table[j][i] = table[j][i-1] - table[j-1][i-1];
    }

    public : void getDifferenceTable(){
        for(int i=0; i<y.size(); i++){
            for(int j=0; j<=i; j++){
                printf("%3lf ",table[i][j]);
            }
            puts("");
        }
    }

    private : void countReverseFactorial(double p){
        reverseFactorial[0] = 1;
        for(int i=1; i<y.size(); i++)
            reverseFactorial[i] = reverseFactorial[i-1]*(p-i+1);
    }

    public : double f(double value){
        makeDifferenceTable();
        double ans = 0;
        double p = (value-x[0])/(x[1]-x[0]);
        countReverseFactorial(p);

        for(int i=0; i<y.size(); i++){
            ans += reverseFactorial[i] * table[i][i] / factorial[i];
        }
        return ans;
    }
};

int main(){
    ForwardInterpolation obj;
    double x,y;

    printf("Enter the tabulated points in the format x y:\n");

    while(scanf("%lf%lf",&x,&y) == 2){
        obj.addXY(x, y);
    }

    double point;
    printf("Enter the expected value:\n");
    scanf("%lf",&point);
    printf("%0.10lf\n",obj.f(point));
    obj.getDifferenceTable();
    return 0;
}
