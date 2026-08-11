#include<iostream>
#include<string>
#include"../../Include/core/Duration.h"

using namespace std ;

Duration::Duration(): m_hours(0), m_minutes(0), m_seconds(0) {

}

Duration::Duration (int hours): m_hours(hours), m_minutes(0), m_seconds(0){

}

Duration::Duration (int hours, int minutes) : m_hours(hours), m_minutes(minutes), m_seconds(0){
    normalize();
}

Duration::Duration(int hours, int minutes, int seconds): m_hours(hours), m_minutes(minutes), m_seconds(seconds) {
    normalize();
}

void Duration::normalize(){

    if(m_seconds >= 60){
        m_minutes += m_seconds/60 ;
        m_seconds %= 60 ;
    }

    if(m_minutes >= 60 ){
        m_hours += m_minutes/60 ;
        m_minutes %= 60 ;
    }

}

void Duration::display_HMS_format() const{

    cout << m_hours <<"h "<< m_minutes <<"min " << m_seconds << "s "<< endl;

}

int Duration::toSeconds( Duration duration) {

    return ( m_hours*3600 + m_minutes*60 + m_seconds );
    
}