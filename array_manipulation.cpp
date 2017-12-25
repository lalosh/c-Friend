#include <iostream>
#include <sstream>
#define integer_to_string( x ) static_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

void print_array(int example_array[],int length){
    for(int i=0;i<length;i++){
        cout << example_array[i] << " ";
    }
    cout << endl;
}

void print_2d_array(string example_array[][5], int length){
    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            cout << example_array[i][j] << " ";

            if(j == 4) cout << endl;
        }
    cout << endl;
}

void print_2d_array(int example_array[][5], int length){
    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            cout << example_array[i][j] << " ";

            if(j == 4) cout << endl;
        }
    cout << endl;
}

bool is_prime(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

void string_to_int_array(string string_array[][5],int integer_array[][5], int length){

    int temp_integer = 0;

    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            istringstream(string_array[i][j]) >> temp_integer;
            integer_array[i][j] = temp_integer;
        }
}

void string_to_ascii(string string_array[][5], int ascii_array[][5], int length){

    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            ascii_array[i][j] = (  int( string_array[i][j][0] ) + int( string_array[i][j][1] )  );
        }
}

void integer_to_prime(int integer_array[][5],int prime_array[][5], int length){

    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            if(is_prime(integer_array[i][j]))
                prime_array[i][j] = integer_array[i][j];
            else
                prime_array[i][j] = 0;
        }

}

void integer_to_odd_array(int integer_array[][5], int length, int odd_array[], int length_odd){

    int odd_counter = 0;
    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            if(integer_array[i][j] % 2 != 0)
                if(odd_counter < length_odd)
                    odd_array[odd_counter++] = integer_array[i][j];
        }

}

void integer_to_even_array(int integer_array[][5], int length, int even_array[], int length_even){

    int even_counter = 0;
    for(int i=0; i < length; i++)
        for(int j=0; j < 5; j++){
            if(integer_array[i][j] % 2 == 0)
                if(even_counter < length_even)
                    even_array[even_counter++] = integer_array[i][j];
        }

}

int main()
{
    string string_array[5][5];
    int integer_counter = 1;

    //fill + int to string
    for(int i=0; i < 5; i++)
        for(int j=0; j < 5; j++){
            string_array[i][j] = integer_to_string(integer_counter);
            integer_counter++;
        }

    cout << "string array:" << endl;
    print_2d_array(string_array,5);

    /////////////////////////////////
    //string to int
    int integer_array[5][5];

    string_to_int_array(string_array, integer_array, 5);

    cout << "integer array:" << endl;
    print_2d_array(integer_array,5);

    //////////////////////////////
    //integer_array to ascii
    int ascii_array[5][5];

    string_to_ascii(string_array, ascii_array, 5);

    cout << "ascii array" << endl;
    print_2d_array(ascii_array,5);

    //////////////////////////////

    int prime_array[5][5];
    integer_to_prime(integer_array, prime_array, 5);

    cout << "prime array: "<<endl;
    print_2d_array(prime_array,5);

    ///////////////////////////////
    int odd_array[13];
    int even_array[12];

    integer_to_even_array(integer_array,5, even_array, 12);
    cout << "even array:" << endl;
    print_array(even_array, 12);

    integer_to_odd_array(integer_array,5, odd_array, 13);
    cout << "odd array:" << endl;
    print_array(odd_array, 13);

    return 0;
}
