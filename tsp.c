# include<stdio.h>
# include<conio.h>
 
int Time_matrix[25][25], visited_Pylon_components[10], n_o_py_comp, Time = 0;
 
int tsp(int c)
{
      int count, nearest_components = 1000;
      int num = 1000, temp;
      for(count = 0; count < n_o_py_comp; count++)
      {
            if((Time_matrix[c][count] != 0) && (visited_Pylon_components[count] == 0))
            {
                  if(Time_matrix[c][count] + Time_matrix[count][c] < num)
                  {
                        num = Time_matrix[count][0] + Time_matrix[c][count];
                  		temp = Time_matrix[c][count];
                  		nearest_components = count;
                  }
            }
      }
      if(num != 1000)
      {
            Time = Time + temp;
      }
      return nearest_components;
}
 
void min_Time(int Time)
{
      int nearest_components;
      visited_Pylon_components[Time] = 1;
      printf("%d ", Time + 1);
      nearest_components = tsp(Time);
      if(nearest_components == 1000)
      {
            nearest_components = 0;
            printf("%d", nearest_components + 1);
            Time = Time + Time_matrix[Time][nearest_components];
            return;
      }
      min_Time(nearest_components);
}
 
int main()
{ 
      int i, j;
      printf("Enter Total Number of pylon components:\t");
      scanf("%d", &n_o_py_comp);
      printf("\nEnter Time matrix\n");
      for(i = 0; i < n_o_py_comp; i++)
      {
            printf("\nEnter %d Elements in Row[%d]\n", n_o_py_comp, i + 1);
            for(j = 0; j < n_o_py_comp; j++)
            {
                  scanf("%d", &Time_matrix[i][j]);
            }
            visited_Pylon_components[i] = 0;
      }
      printf("\nEntered Time Matrix that show how much time is reqired to repai the pylon components \n");
      for(i = 0; i < n_o_py_comp; i++)
      {
            printf("\n");
            for(j = 0; j < n_o_py_comp; j++)
            {
                  printf("%d ", Time_matrix[i][j]);
            }
      }
      printf("\n\nRoute for repairing all the plon components:\t");
      min_Time(0);
      printf("\n\nMinimum Time: \t");
      printf("%d hours \n", Time);
      return 0;
}
