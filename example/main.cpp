#define WINDOW_SIZE  900
#define FIELD_SIZE 20
#define MAX_SIZE 10
#define KEY_EXIT 27

#include "graphics.h"

void load();
void draw_field();
void draw_snake();

int x[MAX_SIZE], y[MAX_SIZE], snake_size;
int x_step, y_step;
int cell_size = WINDOW_SIZE / FIELD_SIZE;
IMAGE *head_up, *head_down, *head_left, *head_right;

int main()
{   
   snake_size = 10;
   for (int i = 0; i < snake_size; i++)
   {
      x[i] = snake_size - i - 1;
      y[i] = 0;
   }
   x_step = 1;
   y_step = 0;
   
   initwindow(WINDOW_SIZE, WINDOW_SIZE);
   load();
   
   while (true)
   {
      cleardevice();
      draw_field();
      draw_snake();
      
      if (kbhit())
      {
         char key = getch();
         switch (key)
         {
            case KEY_DOWN:
               x_step = 0;
               y_step = 1;
               break;
            case KEY_UP:
               x_step = 0;
               y_step = -1;
               break;
            case KEY_LEFT:
               x_step = -1;
               y_step = 0;
               break;
            case KEY_RIGHT:
               x_step = 1;
               y_step = 0;
               break;
            case KEY_EXIT:
               closegraph();
               return 0;
         }
      }

      for (int i = snake_size - 1; i > 0; i--)
      {
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
      delay(100);
   }

   return 0;
}

void load()
{
   head_up = loadBMP("head_up.bmp");
   head_down = loadBMP("head_down.bmp");
   head_left = loadBMP("head_left.bmp");
   head_right = loadBMP("head_right.bmp");
}

void draw_field()
{
   setcolor(WHITE);
   for (int i = 0; i < FIELD_SIZE; i++)
   {
      line(0, i * cell_size, WINDOW_SIZE, i * cell_size);
      line(i * cell_size, 0, i * cell_size, WINDOW_SIZE);
   }
}

void draw_snake()
{
   if (x_step == -1)
   {
      putimage(x[0] * cell_size + 1, y[0] * cell_size + 1, head_left, COPY_PUT);
   }
   if (x_step == 1)
   {
      putimage(x[0] * cell_size + 1, y[0] * cell_size + 1, head_right, COPY_PUT);
   }
   if (y_step == 1)
   {
      putimage(x[0] * cell_size + 1, y[0] * cell_size + 1, head_down, COPY_PUT);
   }
   if (y_step == -1)
   {
      putimage(x[0] * cell_size + 1, y[0] * cell_size + 1, head_up, COPY_PUT);
   }
   
   setcolor(LIGHTGREEN);
   setfillstyle(SOLID_FILL, LIGHTGREEN);
   for (int i = 1; i < snake_size; i++)
   {
      bar(x[i] * cell_size + 1, y[i] * cell_size + 1,
          (x[i] + 1) * cell_size - 1, (y[i] + 1) * cell_size - 1);
   }

}