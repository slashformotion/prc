#include "rollingMean.hpp"


namespace moy
{
    double RollingMean::total() const
    {   
        double result=0;
        for (auto &elem: tableau_)
        {
            result+=elem;
        }
        return result;
    }

    double RollingMean::mean() const 
    {
        return (total() / double(count()));
    }

    void RollingMean::sample(const double e)
    {
        tableau_[position_] = e;
        position_ = (position_+1)%count();
    }

    void RollingMean::fill(const double e)
    {
        for (auto &elem: tableau_)
        {
            elem = e;
        }
    }

    std::ostream& operator<<(std::ostream &output, RollingMean const &r)
    {
        output << "{ "<< r.count() << "with mean" << r.mean() << "}";
        return output; 
    }

} // namespace moy
