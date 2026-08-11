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

Duration& Duration::operator+=(Duration const& duration){

    m_hours+= duration.getHours();
    m_minutes+= duration.getMinutes();
    m_seconds+= duration.getSeconds();

    normalize();

    return *this ;

}

Duration& Duration::operator+=(int seconds){
    m_seconds+= seconds ;

    normalize();

    return *this ;

}

Duration& Duration::operator-=(Duration const& duration){

    m_hours-= duration.getHours();
    m_minutes-= duration.getMinutes();
    m_seconds-= duration.getSeconds();

    normalize() ;

    return *this ;
}

Duration& Duration::operator-=( int seconds){

    m_seconds-= seconds;

    normalize() ;

    return *this ;
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

Duration operator+(Duration const& duration1, Duration const& duration2){

    int totalSeconds ;

    totalSeconds = duration1.toSeconds() + duration2.toSeconds() ;

    Duration result(0,0,totalSeconds) ;

    return result;

}

Duration operator+(Duration const& duration, int seconds){

    int totalSeconds ;

    totalSeconds = duration.toSeconds() +  seconds ;

    Duration result(0,0,totalSeconds) ;

    return result;

}

Duration operator-(Duration const& duration1, Duration const& duration2){

    int totalSeconds ;

    totalSeconds = duration1.toSeconds() - duration2.toSeconds() ;

    Duration result(0,0,totalSeconds) ;
    
    return result;

}

Duration operator-(Duration const& duration, int seconds){

    int totalSeconds ;

    totalSeconds = duration.toSeconds() -  seconds ;

    Duration result(0,0,totalSeconds) ;

    return result;

}