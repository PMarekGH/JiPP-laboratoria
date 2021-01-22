#include <array>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>

struct fork
{
   std::mutex mutex; // zablokowany, gdy filozof je
};

struct table
{
   std::atomic<bool> ready{false};
   std::array<fork, 5> forks; // stol z widelcami
};

class philosopher
{
private:
   std::string const name;
   table const &dinnertable;
   fork &left_fork;
   fork &right_fork;
   std::thread lifethread;
   std::mt19937 rng{std::random_device{}()}; // generator liczb losowych

public:
   philosopher(std::string n, table const &t, fork &l, fork &r);

   ~philosopher();

   void dine();

   void printMsg(std::string text);

   void eat();

   void think();
};
