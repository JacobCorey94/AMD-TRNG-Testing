// g++ main.cpp -o randTest -ltestu01 -lprobdist -lmylib -lm -mrdrnd -mrdseed
// or
// g++ main.cpp -o randTest -ltestu01 -lprobdist -lmylib -lm -march=[your cpu architecture]
// or, with the makefile:
// make

// if testu01 is installed to /usr/local/, include this:
// export LD_LIBRARY_PATH=/usr/local/lib
// export LIBRARY_PATH=/usr/local/lib
// export C_INCLUDE_PATH=/usr/local/include
// export CPLUS_INCLUDE_PATH=/usr/local/include

// You can set these automatically using:
// . config.sh
// Make sure the INSTALLDIRECTORY in config.sh is set correctly

#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <immintrin.h>
#include <x86intrin.h>

extern "C"{
    #include "TestU01.h"
}

using namespace std;


bool testRDRANDGen();
bool testRDSEEDGen();

uint32_t mersenneGen32();
uint32_t RDRANDGen32();
uint32_t RDSEEDGen32();

int menu1();
int menu2();

int main(){

    int choice = menu1();

    string generatorName;
    unif01_Gen * generator;
    bool error = false;

    if(choice == 1){

        generatorName += "Mersenne Twister";
        generator = unif01_CreateExternGenBits((char*) generatorName.c_str(), mersenneGen32);

    }
    else if(choice == 2){

        generatorName = "RDRAND 32";

        if(testRDRANDGen()){
            generator = unif01_CreateExternGenBits((char*) generatorName.c_str(), RDRANDGen32);
        }
        else
        {
            error = true;
        }

    }
    else if(choice == 3){

        generatorName += "RDSEED 32";

        if(testRDSEEDGen()){
            generator = unif01_CreateExternGenBits((char*) generatorName.c_str(), RDSEEDGen32);
        }
        else{
            error = true;
        }

    }

    if(choice != 4){

        if(!error){

            choice = menu2();

            if(choice == 1)
                bbattery_SmallCrush(generator);
            else if(choice == 2)
                bbattery_Crush(generator);
            else if(choice == 3)
                bbattery_BigCrush(generator);

        }
        else{
            cerr << "ERROR! No RDRAND Generator could be found!\n";
        }

    }

    return 0;
}

//Tests to see if _rdrand32_step can find the hardware
//On the CPU. Returns true if so, false if not.
bool testRDRANDGen(){

    uint32_t val = 0;
    if(_rdrand32_step(&val)){
        return 1;
    }

    return 0;
}

bool testRDSEEDGen(){

    uint32_t val = 0;
    if(_rdseed32_step(&val)){
        return 1;
    }

    return  0;
}

//Wrapper function for rdrand32
uint32_t RDRANDGen32(){

    uint32_t val = 0;
    if(_rdrand32_step(&val))
        return val;

    cerr << "ERROR: COULDN'T CALL _RDRAND32_STEP\n";
    return 0;
}

//Wrapper function for rdseed32
//For some reason, it fails when
//Testu01 takes it? Why?
uint32_t RDSEEDGen32(){

    uint32_t val = 0;
    if(_rdseed32_step(&val))
        return val;
    else if(_rdrand32_step(&val))
        return val;
    cerr << "ERROR: COULDN'T CALL _RDSEED32_STEP\n";
    return 0;
}

//Wrapper for Mersenne Twister
uint32_t mersenneGen32(){

    mt19937 mtRand(time(0));

    return mtRand();
}

//Gives the user the choice of what generator to test
int menu1(){

    int choice = 0;

    while(choice < 1 || choice > 4){

        cout << "Please Select a Generator to Test:\n"
             << "1. Mersenne Twister (Slow)\n"
             << "2. RDRANDGen32\n"
             << "3. RDSEEDGen32\n"
             << "4. Quit\n"
             << "Your Choice: ";
        cin >> choice;

        if(!cin){
            cout << "\nNot an Integer. Try Again.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else if(choice < 1 || choice > 4)
            cout << "\nInvalid Option. Try Again.\n\n" << endl;

    }

    return choice;
}

//Gives the user the choice of test
int menu2(){

    int choice = 0;

    while(choice < 1 || choice > 4){

        cout << "Please Select a Test Suite:\n"
             << "1. smallCrush\n"
             << "2. Crush\n"
             << "3. bigCrush\n"
             << "4. Quit\n"
             << "Your Choice: ";
        cin >> choice;

        if(!cin){
            cout << "\nNot an Integer. Try Again.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else if(choice < 1 || choice > 4)
            cout << "\nInvalid Option. Try Again.\n\n" << endl;

    }

    return choice;
}
