#include <iostream>

using namespace std;

class engineer{
public:
    int mark;
    
public:
    engineer(){
        mark = 0;
    }
    ~engineer(){

    }
    engineer(int m){
        mark = m;
    }
    engineer(float array[],int size){
        mark = 0;
        for(int i = 0; i < size; i++){
            if(array[i] >= 60)
                mark++;
        }
    }
    int getMark(){
        return mark;
    }
    engineer operator-(engineer outside){
        engineer t;
        t.mark = mark - outside.getMark();
        return t;
    }

    engineer operator+(engineer outside){
        engineer t;
        t.mark = mark + outside.getMark();
        return t;
    }
    engineer operator++(int){
        return engineer(++mark);
    }
    engineer operator--(int){
        return engineer(--mark);
    }
};

int counter(engineer e){
    int t = e.getMark();
    return t;
}

int main(){

    float array1[] = {1,255,3,24,5,655};
    float array2[] = {14,200,37,4,51,65,100};
    
    engineer e(array1, 6);
    engineer m(array2, 7);

    engineer t;
    
    t = e + m;

    cout << e.getMark() << endl;
    cout << m.getMark() << endl;   
    cout << t.getMark() << endl;

    t--;
    cout << t.getMark() << endl;
    

    
}
