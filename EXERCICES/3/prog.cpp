#include "sensors.hpp"
#include "rollingMean.hpp"


#include <iostream>


void test_rollingMean()
{
     std::cout <<"~~~ begin : " << __func__ << "() ~~~\n";
     int number = 50;
     moy::RollingMean test{number};

     std::cout <<"~~~ end : " << __func__ << "() ~~~\n";

}


void test_sensor()
{
     std::cout <<"~~~ begin : " << __func__ << "() ~~~\n";
     sens::Sensor test{"device_A"};
     auto se=test;
     bool available=true;

     double value;
     while(available)
     {
          tie(available, value) = se.extract();
          cout << "value : " << value <<"   available : "<< available << "\n";
     }

     std::cout <<"~~~ end : " << __func__ << "() ~~~\n";

}



int main(void){
     //test_rollingMean();
     test_sensor();
     return 0;
}