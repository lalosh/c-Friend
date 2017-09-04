#include <iostream>

using namespace std;

class f2;

class f1{
private:
    float av1;
public:
    void call1(float* x, int size){

        float total = 0;
        for(int i = 0 ;i < size; i++){
            total = total + *(x+i);
        }
        
        av1 = total / size;
    }
    friend void fr(f1 x, f2 y);

};

class f2{
private:
    float av2;
public:
    void call2(float* x, int size){

        float total = 0;
        for(int i = 0 ;i < size; i++){
            total = total + *(x+i);
        }
        
        av2 = total / size;
    }
    friend void fr(f1 x, f2 y);
};

void fr(f1 x, f2 y){
    
    cout << "av1 = " << x.av1 << endl;
    cout << "av2 = " << y.av2 << endl;
    
    if(x.av1  > y.av2) 
        cout << "x.av1 > y.av2" << endl;
    else if(x.av1  < y.av2)
            cout << "x.av1 < y.av2" << endl;
         else 
            cout << "x.av1 = y.av2" << endl;
        
}

int main(){

    float myArray[10] = { 88.8765,14,1.2 , 4.1 , 5,7,54,2,5,67 };
    float* m;
    m = myArray;

    f1 obj;
    obj.call1(m, 10);

    ////////

    float myArray2[10] = { 988.8765,114,1.2 , 4.1 , -5,7,54,2,5,67 };
    float* m2;
    m2 = myArray2;

    f2 obj2;
    obj2.call2(m2, 10);

    ///////

   fr( obj, obj2);

}

