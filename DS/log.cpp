#include "log.hpp"

#include <exception>
#include <stdexcept>
#include <array>
#include <iostream>
using namespace std;

namespace s4prc
{
    Log::Log(int in_day, int in_month, int in_year)
    : Log()
    {   

        // setting day
        if (in_day>=0)
        {   int limit = 32000;
            if (month_ == 2) //fevrier
            {
                const int limit = 28;
            }
            else if (month_%2==0 && month_ != 2) // pair month
            {
                const int limit = 31;
            }
            else // odd month
            {
                const int limit = 30;
            }
            limit = 32000;
            if (in_day > limit)
            {
                throw runtime_error{"The day you provided does not fit the invariant conditions (off month limit)\n"};
            }
            else
            {
                day_ = in_day;
            }
        }

        //setting month
        if (in_month > 0)
        {
            if (in_month >=13)
            {
                throw runtime_error{"The month you provided does not fit the invariant conditions (sup 12)\n"};
            }
            else
            {
                month_ = in_month;
            }
            
        }
        else
        {
            throw runtime_error{"The month you provided does not fit the invariant conditions (inf 0)\n"};
        }

        //setting year
        if (in_year > 0)
        {
            year_ = in_year;
            
        }
        else
        {
            throw runtime_error{"The year you provided does not fit the invariant conditions (inf 0)\n"};
        }

        
    }

    void Log::set_DAY(int const in_day)
    {
        if (in_day>=0)
        {   int limit = 32000;
            if (month_ == 2) //fevrier
            {
                const int limit = 28;
            }
            else if (month_%2==0 && month_ != 2) // pair month
            {
                const int limit = 31;
            }
            else // odd month
            {
                const int limit = 30;
            }
            limit = 32000;
            if (in_day > limit)
            {
                throw runtime_error{"The day you provided does not fit the invariant conditions (off month limit)\n"};
            }
            else
            {
                day_ = move(in_day);
            }
            


            
        }
        else
        {
            throw runtime_error{"The day you provided does not fit the invariant conditions (inf 0)\n"};
        }
    }
    void Log::set_MONTH(const int in_month)
    {
        if (in_month > 0)
        {
            if (in_month >=13)
            {
                throw runtime_error{"The month you provided does not fit the invariant conditions (sup 12)\n"};
            }
            else
            {
                month_ = in_month;
            }
            
        }
        else
        {
            throw runtime_error{"The month you provided does not fit the invariant conditions (inf 0)\n"};
        }
    }
    void Log::set_YEAR(const int in_year)
    {
        if (in_year > 0)
        {
            year_ = in_year;
            
        }
        else
        {
            throw runtime_error{"The year you provided does not fit the invariant conditions (inf 0)\n"};
        }
    }
    
    void Log::set_DATA(const vector<string> v)
    {
        data_ = v;
    }

    string Log::month_str() const { return month_str_data[month_]; }

   string Log::preview_data()
   const
    {
        return "First element : " + data_.front() + "Last element" + data_.back();
    }

    void Log::show() const
    {
        cout << " day :" << day_ << " month :" << month_ << " year :" << year_ << " first word of data : " << data_.front() << "\n";
       
    }

    string gen_random(const int len) 
    {
        static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";

        string result;
        for (int i = 0; i < len; ++i) {
            result += alphanum[rand() % (sizeof(alphanum) - 1)];
        }

        return result;
    }




    vector<string> populate(const int number, const int len)
    {
        vector<string> result;
        
        for (int i= 0; i<number; ++i)
        {
           result.push_back(gen_random(len));
        }

       return result;
    }


} // namespace s4prc


