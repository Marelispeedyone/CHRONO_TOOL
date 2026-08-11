#ifndef DURATION_H
#define DURATION_H

#include<string>

class Duration {
    
    private :
        
        int m_hours ;
        int m_minutes ;
        int m_seconds ;

    public :

        Duration (); // default constructor
        Duration(int hours);
        Duration(int hours, int minutes);
        Duration(int hours, int minutes, int seconds);
        /* Duration(Duration const& duration); Copy constructor */

        void normalize() ;

        std::string toHMS () const ;
        int toSeconds() const;

        int getHours() const ;
        int getMinutes() const ;
        int getSeconds() const ;

        // Duration& and *this must be in uniry operators
        Duration& operator+=(Duration const& duration);
        Duration& operator+=(int seconds);

        Duration& operator-=(Duration const& duration);
        Duration& operator-=(int seconds);
};

// inline only into .h file in order to have the same function definition everywhere and compile without a hitch.

inline bool operator==(Duration const& duration1, Duration const& duration2) ;

inline bool operator!=(Duration const& duration1, Duration const& duration2 );

inline bool operator>(Duration const& duration1, Duration const& duration2 );

inline bool operator<(Duration const& duration1, Duration const& duration2 );

inline bool operator>=(Duration const& duration1, Duration const& duration2 );

inline bool operator<=(Duration const& duration1, Duration const& duration2 );

inline Duration operator+(Duration const& duration1, Duration const& duration2);

inline Duration operator+(Duration const& duration, int seconds);

inline Duration operator-(Duration const& duration1, Duration const& duration2);

inline Duration operator-(Duration const& duration, int secondes);
#endif // DURATION_H