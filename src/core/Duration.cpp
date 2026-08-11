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

    // seconds should not be over 59

    if(m_seconds >= 60){
        m_minutes += m_seconds/60 ;
        m_seconds %= 60 ;
    }
    // minutes should not be over 59
    if(m_minutes >= 60 ){
        m_hours += m_minutes/60 ;
        m_minutes %= 60 ;
    }

}

string Duration::toHMS () const{
    
    return to_string(m_hours)+"h "+to_string(m_minutes)+"min "+to_string(m_seconds)+"s " ;

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

