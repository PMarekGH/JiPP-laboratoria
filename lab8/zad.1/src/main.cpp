#include <array>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <random>
#include <iomanip>

// https://mariusbancila.ro/blog/2017/01/16/dining-philosophers-in-cpp11/
 
struct fork
{
   std::mutex mutex; // zablokowany, gdy filozof je
};
 
struct table
{
   std::atomic<bool>                    ready{ false };
   std::array<fork, 5> forks; // stol z widelcami
};
 
struct philosopher
{
private:
   std::string const name;
   table const &     dinnertable;
   fork&             left_fork;
   fork&             right_fork;
   std::thread       lifethread;
   std::mt19937      rng{ std::random_device{}() };
public:
   philosopher(std::string n, table const & t, fork & l, fork & r) :
      name(n), dinnertable(t), left_fork(l), right_fork(r), lifethread(&philosopher::dine, this)
   {
   }
 
   ~philosopher()
   {
      lifethread.join();
   }
 
   void dine() // funkcja, ktora wykonuje watek
   {
      while (!dinnertable.ready);
 
      do
      {
         think();
         eat();
      } while (dinnertable.ready);
   }
 
   void print(std::string text)
   {
      std::cout
         << std::left << std::setw(10) << std::setfill(' ')
         << name << text << std::endl;
   }
 
   void eat()
   {
      std::lock(left_fork.mutex, right_fork.mutex);
 
      std::lock_guard<std::mutex> left_lock(left_fork.mutex,   std::adopt_lock);
      std::lock_guard<std::mutex> right_lock(right_fork.mutex, std::adopt_lock);
 
      print(" started eating.");
 
      static thread_local std::uniform_int_distribution<> dist(1, 6);
      std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) * 50));
 
      print(" finished eating.");
   }
 
   void think() // myslenie
   {
      std::this_thread::sleep_for(std::chrono::milliseconds((rand() % 6) + 1) * 150));
 
      print(" is thinking ");
   }
};
 
void dine()
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << "Dinner started!" << std::endl;
 
   {
      table table;
      std::array<philosopher, 5> philosophers
      {
         {
            { "Aristotle", table, table.forks[0], table.forks[1] },
            { "Platon",    table, table.forks[1], table.forks[2] },
            { "Descartes", table, table.forks[2], table.forks[3] },
            { "Kant",      table, table.forks[3], table.forks[4] },
            { "Nietzsche", table, table.forks[4], table.forks[0] },
         }
      };
 
      table.ready = true;
      std::this_thread::sleep_for(std::chrono::seconds(5));
      table.ready = false;
   }
 
   std::cout << "Dinner done!" << std::endl;
}
 
int main()
{   
   dine();
 
   return 0;
}