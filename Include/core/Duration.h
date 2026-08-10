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

        void display () const ;
        void normalize() ;

};


#endif // DURATION_H