#include <lab8/philosopher.hpp>

philosopher::philosopher(std::string n, table const &t, fork &l, fork &r) : name(n), dinnertable(t), left_fork(l), right_fork(r), lifethread(&philosopher::dine, this)
{
}

philosopher::~philosopher()
{
   lifethread.join();
}

void philosopher::dine() // funkcja, ktora wykonuje watek
{
   while (!dinnertable.ready)
      ;

   do
   {
      think();
      eat();
   } while (dinnertable.ready);
}

void philosopher::printMsg(std::string text)
{
   std::cout
       << std::left << std::setw(10) << std::setfill(' ')
       << name << text << std::endl;
}

void philosopher::eat()
{
   std::lock(left_fork.mutex, right_fork.mutex); // zablokuj widelce

   std::lock_guard<std::mutex> left_lock(left_fork.mutex, std::adopt_lock); // odblokuj mutexy na koncu scope'a
   std::lock_guard<std::mutex> right_lock(right_fork.mutex, std::adopt_lock);

   printMsg(" je.");

   std::uniform_int_distribution<> dist(1, 6); // losowe liczby calkowite pomiedzy 1 i 6
   std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) * 50));

   printMsg(" skonczyl jesc");
}

void philosopher::think() // myslenie
{
   std::uniform_int_distribution<> dist(1, 6); // losowe liczby calkowite pomiedzy 1 i 6
   std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) * 150));

   printMsg(" mysli.");
}