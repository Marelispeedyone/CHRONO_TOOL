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
        int toSeconds(Duration duration);
};


#endif // DURATION_H