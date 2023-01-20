#define WINDOW_SIZE  900
#define FIELD_SIZE 20
#define MAX_SIZE 50
#define KEY_EXIT 27
#include <ctime>
#include <cstdlib>
#include "graphics.h"

void food(int, int);
void draw_snake();

int x[MAX_SIZE], y[MAX_SIZE], snake_size;
int x_step, y_step;
int cell_size = WINDOW_SIZE / FIELD_SIZE;

int main(){  
   int x_1, y_1;
   srand(time(0));
   x_1 = rand() % FIELD_SIZE;
   y_1 = rand() % FIELD_SIZE;
   snake_size = 1;
   for (int i = 0; i < snake_size; i++){
      x[i] = snake_size - i - 1;
      y[i] = 0;
   }
   x_step = 1;
   y_step = 0;
   initwindow(WINDOW_SIZE, WINDOW_SIZE, "Snake!");
   
   while (true){
      setbkcolor(WHITE);
      cleardevice();
      draw_snake();
      food(x_1, y_1);
      
      if (kbhit()){
         char key = getch();
         if(key == 83 || key == 115 || key == KEY_DOWN){
            x_step = 0;
            y_step = 1;
         }
         else if(key == 87 || key == 119 || key == KEY_UP){
            x_step = 0;
            y_step = -1;
         }
         else if(key == 65 || key == 97 || key == KEY_LEFT){
            x_step = -1;
            y_step = 0;
         }
         else if(key == 68 || key == 100 || key == KEY_RIGHT){
            x_step = 1;
            y_step = 0;
         }
         else if(key == KEY_EXIT){
            closegraph();
            return 0;
         }
      }
      if((x[0] + x_step == x_1 && y[0] + y_step == y_1) || (x[0]  == x_1 && y[0] == y_1) ){
         snake_size++;
         x_1 = rand() % FIELD_SIZE;
         y_1 = rand() % FIELD_SIZE;
         for(int i = 0;i < snake_size;i++){
            for(int j = 0;j < snake_size;j++){
               while(x[i] == x_1 && y[j] == y_1){
                  x_1 = rand() % FIELD_SIZE;
                  y_1 = rand() % FIELD_SIZE;
               }
            }
         }
      }

      for (int i = snake_size - 1; i > 0; i--){
         x[i] = x[i - 1];
         y[i] = y[i - 1];
      }
      x[0] += x_step;
      y[0] += y_step;
      
      for (int i = snake_size - 1; i > 0; i--)
      {
         if (x[i] == x[0] && y[i] == y[0])
         {
            x_step = 0;
            y_step = 0;
         }
      }
      
      if (x_step == 0 && y_step == 0)
      {
         swapbuffers();
         getch();
         break;
      }
      
      if (x[0] == FIELD_SIZE)
      {
         x[0] = 0;
      }
      if (x[0] == -1)
      {
         x[0] = FIELD_SIZE - 1;
      }
      if (y[0] == FIELD_SIZE)
      {
         y[0] = 0;
      }
      if (y[0] == -1)
      {
         y[0] = FIELD_SIZE - 1;
      }
      
      swapbuffers();
      delay(70);
   }

   return 0;
}
void draw_snake()
{
   setcolor(GREEN);
   setfillstyle(SOLID_FILL, GREEN);
   for (int i = 0; i < snake_size; i++)
   {
      bar(x[i] * cell_size + 1, y[i] * cell_size + 1,
          (x[i] + 1) * cell_size - 1, (y[i] + 1) * cell_size - 1);
   }

}
void food(int x_1, int y_1){
   setcolor(LIGHTRED);
   setfillstyle(SOLID_FILL, LIGHTRED);
   bar(x_1 * cell_size + 1, y_1 * cell_size + 1, (x_1 + 1) * cell_size - 1, (y_1 + 1) * cell_size - 1);
}