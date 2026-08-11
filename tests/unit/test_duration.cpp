#include<iostream>

#include "../../Include/core/Duration.h"

using namespace std ;

void displayTest(){

    Duration d1(4) ;
    d1.display_HMS_format();
    Duration d2(3, 10, 46 );
    d2.display_HMS_format();

}

void normalizeTest(){

    Duration d1(2,72,60);

    int h = d1.getHours() ;
    int min = d1.getMinutes() ;
    int sec = d1.getSeconds() ;


    assert(h==3);
    assert(min==12);
    assert(sec==0);
    
    // Check we have the excepted result '2h72min60 -> 3h12min0'

    d1.display_HMS_format();
}

int main(){
    
    displayTest();
    normalizeTest();

    return 0 ;
}