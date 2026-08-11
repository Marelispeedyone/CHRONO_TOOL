#ifndef DURATION_H
#define DURATION_H


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

        void normalize() ;
        void display_HMS_format () const ;
        int toSeconds() const;

        int getHours() const ;
        int getMinutes() const ;
        int getSeconds() const ;
};

// inline only into .h file in order to have the same function definition everywhere and compile without a hitch.

inline bool operator==(Duration const& duration1, Duration const& duration2) ;

inline bool operator!=(Duration const& duration1, Duration const& duration2 );

inline bool operator>(Duration const& duration1, Duration const& duration2 );

inline bool operator<(Duration const& duration1, Duration const& duration2 );

inline bool operator>=(Duration const& duration1, Duration const& duration2 );

inline bool operator<=(Duration const& duration1, Duration const& duration2 );

#endif // DURATION_H