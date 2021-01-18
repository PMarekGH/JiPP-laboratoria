#include <thread>
#include <string>

class Philosopher
{
    public:
    Philosopher();
    philosopher(std::string n) :
      name(n), dinnertable(t), left_fork(l), right_fork(r), lifethread(&philosopher::dine, this);
      
    start();
    eat();

    private:
    std::thread lifethread;
}