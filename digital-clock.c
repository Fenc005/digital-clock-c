//----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------Digital Clock------------------------------------------------------
//-----------------------------------------------Author: Ferenc Simon---------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define ROWS 7

/// @brief This ist the whole digital clock
/// @return 0 but, but it won't ever be reached, because it is infintely looping, because it is a clock.
int main(void)
{
  printf("\033[2J");
  printf("\n\n\n\n\n\n");
  char *one[7] = {"   ##   ", " ####   ", "   ##   ", "   ##   ", "   ##   ", "   ##   ", " ###### ",};
  char *two[7] = {" #######  ", "##     ## ", "       ## ", " #######  ", "##        ", "##        ", "######### ",};
  char *three[7] ={" #######  ", "##     ## ", "       ## ", " #######  ", "       ## ", "##     ## ", " #######  ",};
  char *four[7] = {"##        ", "##    ##  ", "##    ##  ", "##    ##  ", "######### ", "      ##  ", "      ##  ",};
  char *five[7] ={"######## ", "##       ", "##       ", "#######  ", "      ## ", "##    ## ", " ######  ",};
  char *six[7] = {" #######  ", "##     ## ", "##        ", "########  ", "##     ## ", "##     ## ", " #######  ",};
  char *seven[7] = {"######## ", "##    ## ", "    ##   ", "   ##    ", "  ##     ", "  ##     ", "  ##     ",};
  char *eight[7] = {" #######  ", "##     ## ", "##     ## ", " #######  ", "##     ## ", "##     ## ", " #######  ",};
  char *nine[7] = {" #######  ", "##     ## ", "##     ## ", " ######## ", "       ## ", "##     ## ", " #######  ",};
  char *zero[7] ={"  #####   ", " ##   ##  ", "##     ## ", "##     ## ", "##     ## ", " ##   ##  ", "  #####   ",};
  char *dots[7] = {"          ", "   ####   ", "   ####   ", "          ", "   ####   ", "   ####   ", "          ",};
  char **digits[11] = {zero, one, two, three, four, five, six, seven, eight, nine, dots};
  
  time_t now = time(NULL);
  struct tm *old_time = localtime(&now);
  char hour[3] = "";
  char minute[3] = "";
  sprintf(hour,"%02d", old_time->tm_hour);
  sprintf(minute,"%02d", old_time->tm_min);
  int hour_p1 = hour[0] - '0';
  int hour_p2 = hour[1] - '0';
  int min_p1 = minute[0] - '0';
  int min_p2 = minute[1] - '0';
  
  for(int i = 0; i < ROWS; i++)
  {
    printf("\t\t%s %s %s %s %s\n", digits[hour_p1][i], digits[hour_p2][i], 
          digits[10][i], digits[min_p1][i], digits[min_p2][i]);
  }
  fflush(stdout);

  while(1)
  {
    while(1)
    {
      time_t current = time(NULL);
      struct tm *ct = localtime(&current);
      char cur_minute[3] = "";
      char cur_hour[3] = "";
      sprintf(cur_hour,"%02d", ct->tm_hour);
      sprintf(cur_minute,"%02d", ct->tm_min);
      
      if(strcmp(minute, cur_minute) != 0)
      {
        strcpy(hour, cur_hour);
        strcpy(minute, cur_minute);
        hour_p1 = cur_hour[0] - '0';
        hour_p2 = cur_hour[1] - '0';
        min_p1 = cur_minute[0] - '0';
        min_p2 = cur_minute[1] - '0';
        break;
      }
      int sleep_value = 59 - ct->tm_sec;
      sleep(sleep_value);
    }

    for(int i = 0; i < ROWS; i++)
    {
      printf("\033[1A");
      printf("\033[2K");
    }
    for(int i = 0; i < ROWS; i++)
    {
      printf("\t\t%s %s %s %s %s\n", digits[hour_p1][i], digits[hour_p2][i], 
            digits[10][i], digits[min_p1][i], digits[min_p2][i]);
    }
    fflush(stdout);
  }

  return 0;
}
