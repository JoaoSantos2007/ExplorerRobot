#include <iostream>
using namespace std;

int main(){
    string name = "seila_255";
    int ander = name.rfind("_");
    int tam = name.length();
    for(int i = ander + 1; i < tam; i++){
        cout<<name[i];
    }

    cout << endl << name.erase(5);
}