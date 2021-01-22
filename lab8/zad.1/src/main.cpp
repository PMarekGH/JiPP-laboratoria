#include <lab8/philosopher.hpp>

void uczta()
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << "Obiad się rozpoczyna" << std::endl;
 
   {
      table table;
      std::array<philosopher, 5> philosophers
      {
         {
            { "Filozof 1", table, table.forks[0], table.forks[1] },
            { "Filozof 2", table, table.forks[1], table.forks[2] },
            { "Filozof 3", table, table.forks[2], table.forks[3] },
            { "Filozof 4", table, table.forks[3], table.forks[4] },
            { "Filozof 5", table, table.forks[4], table.forks[0] },
         }
      };
 
      table.ready = true;
      std::this_thread::sleep_for(std::chrono::seconds(5)); // przez ile czasu filozofowie maja ucztowac
      table.ready = false;
   }
 
   std::cout << "Obiad zakończony!" << std::endl;
}
 
int main()
{   
   uczta();
 
   return 0;
}