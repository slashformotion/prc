#ifndef ROLLINGMEAN_HPP
#define ROLLINGMEAN_HPP

#include <vector>
#include <stdexcept>
#include <iostream>

namespace moy
{
    class RollingMean
    {
        public:

        
        
        RollingMean(const std::vector<double> &d)
        : tableau_{d}, position_{0}
        {
            if (int(size(d)) == 0)
            {
                throw std::runtime_error{"trest"};
            }
        }

        RollingMean(const int number)
        : RollingMean(std::vector<double>(number))
        {
            //nothing
        }

        /// METHODS
        int count() const { return int(size(tableau_)); }
        double mean() const;

        void sample(const double e);
        void fill(const double e);
        

        /// GET
        std::vector<double> tableau() const { return tableau_; }
        int position() const { return position_; }
        /// SET
        

        private:
            double total() const;
            std::vector<double> tableau_;
            int position_;
    };

    std::ostream& operator<<(std::ostream &output, RollingMean const &r);
    

} // namespace moy


#endif