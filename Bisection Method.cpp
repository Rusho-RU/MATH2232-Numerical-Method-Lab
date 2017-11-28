#include <bits/stdc++.h>
using namespace std;

class Bisection{
    private : double eps;
    private : double a,b,root;

    public : Bisection(){
         a = 0, b = 0, root = -1, eps = 0.0000000001;
    }

    public : double f(double x){
        return x*x*x + x*x + 3;
    }

    public : void findInterval(){
        do{
            a--, b++;
        }while(f(a) * f(b) > 0);

        if(f(b) < 0)
            swap(a,b);

        return;
    }

    public : double getRoot(){
        return root;
    }

    public : void findRoot(){
        findInterval();
        double mid = (a+b)/2;

        while(abs(f(b) - f(a)) > eps){
            if(f(mid) > 0)
                b = mid;
            else
                a = mid;
            mid = (a+b)/2;
        }

        root = mid;
    }
};

int main(){
    Bisection bisection;
    bisection.findRoot();
    printf("The root of the given equation : %0.10lf\n", bisection.getRoot());
}

