#include<string>
#include<cctype>
#include<iostream>

class Car{
public:
    //void myCar(std::string, std::string);
    //void myCar(std::string, std::string, int);
    Car(std::string make_in, std::string model_in,int ye=2011){
        year=ye;
        make=make_in;
        model=model_in;
        speed=0;
    }

    void Set(std::string make, std::string model, int ye=2011){
        year=ye;
        make=make;
        model=model;
        speed=0;
    }

    std::string GetMake(){return make;}

    std::string GetModel(){return model;}

    int GetYear(){return year;}

    int GetSpeed(){return speed;}

    void Display(){
        std::cout<<"Your car is a" <<year<<' ';
        std::cout<<make<<' '<<model<<' '<<"And it is currently going "<<speed<<" MPH\n";
    }

    bool Accelerate(char c){
        c=tolower(c);
        if(c=='h')speed+=10;
        else if(c=='m')speed+=5;
        else if(c=='l')speed+=1;
        else return false;
        return true;
    }

    bool Brake(char c){
        c=tolower(c);

        if(speed==0)return false;

        if(c=='h')speed-=10;
        else if(c=='m')speed-=5;
        else if(c=='l')speed-=1;
        else return false;

        if(speed<0)speed=0;

        return true;
    }

private:
    std::string make, model;
    int year;
    int speed;
};
