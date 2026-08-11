#include<iostream>
#include<cassert>

#include "../../Include/core/Duration.h"

using namespace std ;

void displayTest(){

    Duration d1(4) ;
    cout << d1.toHMS() << endl ;
    Duration d2(3, 10, 46 );
    cout << d2.toHMS() << endl ;

}

void normalizeTest(){

    Duration d1(2,72,60);


    int h = d1.getHours() ;
    int min = d1.getMinutes() ;
    int sec = d1.getSeconds() ;


    assert(h==3);
    assert(min==13);
    assert(sec==0);
    
    // Check we have the excepted result '2h72min60 -> 3h13min0'

    cout << d1.toHMS() << endl ;

    

    
}

int main(){

    displayTest();
    normalizeTest();

    return 0 ;
}