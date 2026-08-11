#include"../../Include/core/Duration.h"

#include<iostream>
#include<string>


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

int Duration::toSeconds() const {

    return ( m_hours*3600 + m_minutes*60 + m_seconds );

}

int Duration::getHours() const {

    return m_hours ;

}

int Duration::getMinutes() const {

    return m_minutes ;

}

int Duration::getSeconds() const {

    return m_seconds ;
}



bool operator==(Duration const& duration1, Duration const& duration2){

    return duration1.toSeconds() == duration2.toSeconds() ;

}

bool operator!=(Duration const& duration1, Duration const& duration2){

    return duration1.toSeconds() != duration2.toSeconds() ;

}

bool operator>(Duration const& duration1, Duration const& duration2){

    return duration1.toSeconds() > duration2.toSeconds() ;

}

bool operator<(Duration const& duration1, Duration const& duration2){

    return duration1.toSeconds() < duration2.toSeconds() ;

}

bool operator>=(Duration const& duration1, Duration const& duration2){

    return duration1.toSeconds() >= duration2.toSeconds() ;

}

bool operator<=(Duration const& duration1, Duration const& duration2){

    return duration1.toSeconds() <= duration2.toSeconds() ;

}

