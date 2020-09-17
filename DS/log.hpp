#ifndef Log_S4PRC_HPP
#define Log_S4PRC_HPP

#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;

namespace s4prc
{
    
    class Log
    {
        /* 
        Cette classe représente un type structuré de type Log.
        L'invariant est le suivant : toute instance de Log doit correspondre à un jour
        d'une année non bissextile du calendrier grégorien.
        Cette structure se charge donc de vérifier cet invariant via l'implémentation de setter et détient un 
        membre data_ qui est la donnée que l'on veut logger.
        */


        public:
            const array<string,12> month_str_data{{"Janvier", "Février", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Décembre"}};


            //// Spécification des constructeurs par recopie et déplacement
            /* on va interdire la recopie car le membre data est 
            potentiellement couteux en mémoire*/
            
            // recopie
             Log(const Log &)= delete;
              Log & operator=(const Log &)= delete;
            
            // déplacement
             Log(Log &&) = default;
              Log & operator=(Log &&)= default;


            // destructeur
             ~Log()= default;

            Log()
            : day_{-1}, month_{-1}, year_{-1}, data_{ {}}
            {
                //nothing
            }
            
            Log(int in_day, int in_month, int in_year);



            void populate(const int number, const int len = 20);
            void show() const;
        
        
            // GET METHODS
            int day() const { return day_; }
            int month() const { return month_; }
            string month_str() const;
            int year() const { return year_; }
            
            string preview_data() const;

            // SET METHODS
            void set_DAY(int const in_day);
            void set_MONTH(const int in_month);
            void set_YEAR(const int in_year);
            void set_DATA(const vector<string> v);


        private:
            int day_;
            int month_;
            int year_;
            vector<string> data_; 
            



    }; // class Log

    
    string gen_random(const int len);
    vector<string> populate(const int number, const int len = 20);
    

} // namespace s4prc


#endif // Log_S4PRC_HPP