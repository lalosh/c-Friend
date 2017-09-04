#include <iostream>

using namespace std;


class Array{
private:
    int min;
    int max;
    
public:
    Array(){
        min = 0;
        max = 0;
        cout << "hello i am array class " << endl;
    }

    ~Array(){
        cout << "bye bye" << endl;
    }

    Array(int myArray[]){
        
        min = myArray[0];
        max = myArray[0];

        int i;
        for(i = 0; i < 20; i++ ){
            if( myArray[i] < min )
                min = myArray[i];

            if( myArray[i] > max )
                max = myArray[i];
        }
    }


    Array(int myArray[], int size){
        
        min = myArray[0];
        max = myArray[0];

        int i;
        for(i = 0; i < size; i++ ){
            if( myArray[i] < min )
                min = myArray[i];

            if( myArray[i] > max )
                max = myArray[i];
        }
    }

    void setMin(int x){
        min = x;
    }
    
    int getMin(){
        return min;
    }

    void setMax(int x){
        max = x;
    }

    int getMax(){
        return max;
    }
    
    void print(){
        
        cout << "min = " << min << endl;
        cout << "max = " << max << endl;
    }


};


int main(){

    int m;
    int someArray[20];

    cout << "أدخل الأرقام" << endl;
    
    for(int i = 0; i < 20; i++){
        cin >> m;
        someArray[i] = m;
    }

    Array array1(someArray);

    array1.print();

    /////////////////////////

    int someArray2[4] = {4,3,1,5};

    Array array2(someArray2, 4);
    
    array2.print();

}

