#include <iostream>

class SingletonInside
{
private:
    SingletonInside(){}
public:
    static SingletonInside* getInstance()
    {
        std::cout << "hehe" << std::endl;
        //Lock(); // not needed after C++0x
        static SingletonInside instance;
        //UnLock(); // not needed after C++0x
        return &instance; 
    }
};


int main(){
    SingletonInside* aa = SingletonInside::getInstance();
    SingletonInside* bb = SingletonInside::getInstance();

    std::cout << (aa == bb) << std::endl;
    return 0;
}