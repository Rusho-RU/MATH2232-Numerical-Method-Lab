#include <bits/stdc++.h>
using namespace std;

class NewtonRaphson{
    private : double eps;
    private : double root;

    public : NewtonRaphson(){
         eps = 0.0000000001;
         root = 3;
    }

    public : double f(double x){
        return x*x*x + x*x + 3;
    }

    public : double ddxf(double x){
        return 3*x*x + 2*x;
    }

    public : double getRoot(){
        return root;
    }

    public : void findRoot(){
        while(abs(f(root)) > eps)
            root = root - (f(root)/ddxf(root));
    }
};

int main(){
    NewtonRaphson newtonRaphson;
    newtonRaphson.findRoot();
    printf("The root of the given equation : %0.10lf\n", newtonRaphson.getRoot());
}

