#include <iostream>
using namespace std;

int main()
{
   int array[] = {1, 3, 5, 7, 9};
   int size = 5;
   int target = 10;
   int found = 0;

   for (int i = 0; i < size; i++)
   {
      for (int j = i + 1; j < size; j++)
      {
         if (array[i] + array[j + 1] == target)
         {
            found++;
         }
      }
   }

   cout << found << endl;
}