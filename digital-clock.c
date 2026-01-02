//----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------Digital Clock------------------------------------------------------
//-----------------------------------------------Author: Ferenc Simon---------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define ROWS 7

const char *one[7] = {"   ##   ", " ####   ", "   ##   ", "   ##   ", "   ##   ", "   ##   ", " ###### "};
const char *two[7] = {" #######  ", "##     ## ", "       ## ", " #######  ", "##        ", "##        ", "######### "};
const char *three[7] ={" #######  ", "##     ## ", "       ## ", " #######  ", "       ## ", "##     ## ", " #######  "};
const char *four[7] = {"##        ", "##    ##  ", "##    ##  ", "##    ##  ", "######### ", "      ##  ", "      ##  "};
const char *five[7] ={"######## ", "##       ", "##       ", "#######  ", "      ## ", "##    ## ", " ######  "};
const char *six[7] = {" #######  ", "##     ## ", "##        ", "########  ", "##     ## ", "##     ## ", " #######  "};
const char *seven[7] = {"######## ", "##    ## ", "    ##   ", "   ##    ", "  ##     ", "  ##     ", "  ##     "};
const char *eight[7] = {" #######  ", "##     ## ", "##     ## ", " #######  ", "##     ## ", "##     ## ", " #######  "};
const char *nine[7] = {" #######  ", "##     ## ", "##     ## ", " ######## ", "       ## ", "##     ## ", " #######  "};
const char *zero[7] ={"  #####   ", " ##   ##  ", "##     ## ", "##     ## ", "##     ## ", " ##   ##  ", "  #####   "};
const char *dots[7] = {"          ", "   ####   ", "   ####   ", "          ", "   ####   ", "   ####   ", "          "};
const char **digits[11] = {zero, one, two, three, four, five, six, seven, eight, nine, dots};

const char *mini_one[7] = {"       ", "       ", "   ##  ", "  ###  ", "   ##  ", "   ##  ", "   ##  "};
const char *mini_two[7] = {"       ", "       ", " ##### ", "    ## ", " ##### ", " ##    ", " ##### "};
const char *mini_three[7] = {"       ", "       ", " ##### ", "    ## ", " ##### ", "    ## ", " ##### "};
const char *mini_four[7] = {"       ", "       ", " #   # ", " #   # ", " ##### ", "     # ", "     # "};
const char *mini_five[7] = {"       ", "       ", " ##### ", " #     ", " ##### ", "     # ", " ##### "};
const char *mini_six[7] = {"       ", "       ", " ##### ", " #     ", " ##### ", " #   # ", " ##### "};
const char *mini_seven[7] = {"       ", "       ", " ##### ", "     # ", "    #  ", "   #   ", "  #    "};
const char *mini_eight[7] = {"       ", "       ", " ##### ", " #   # ", " ##### ", " #   # ", " ##### "};
const char *mini_nine[7] = {"       ", "       ", " ##### ", " #   # ", " ##### ", "     # ", " ##### "};
const char *mini_zero[7] = {"       ", "       ", " ##### ", " #   # ", " #   # ", " #   # ", " ##### "};
const char **mini_digits[10] = {mini_zero, mini_one, mini_two, mini_three, mini_four, mini_five, mini_six,
                                mini_seven, mini_eight, mini_nine};

void drawClock(int *hour_p1, int *hour_p2, int *min_p1, int *min_p2, int *sec_p1, int *sec_p2);

/// @brief This is the whole digital clock
/// @return 0 but, but it won't ever be reached, because it is infinitely looping, because it is a clock.
int main(void)
{
  printf("\033[H");
  printf("\033[2J");

  while(1)
  {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    char hour[3] = "";
    char minute[3] = "";
    char seconds[3] = "";
    sprintf(hour,"%02d", current_time->tm_hour);
    sprintf(minute,"%02d", current_time->tm_min);
    sprintf(seconds,"%02d", current_time->tm_sec);

    int hour_p1 = hour[0] - '0';
    int hour_p2 = hour[1] - '0';
    int min_p1 = minute[0] - '0';
    int min_p2 = minute[1] - '0';
    int sec_p1 = seconds[0] - '0';
    int sec_p2 = seconds[1] - '0';

    drawClock(&hour_p1, &hour_p2, &min_p1, &min_p2, &sec_p1, &sec_p2);
    sleep(1);
  }

  return 0;
}

void drawClock(int *hour_p1, int *hour_p2, int *min_p1, int *min_p2, int *sec_p1, int *sec_p2)
{
  for(int i = 0; i < ROWS; i++)
  {
    printf("\033[38;2;255;150;0m%s %s %s %s %s\033[0m \033[38;2;255;50;0m%s%s\033[0m\n", digits[*hour_p1][i], digits[*hour_p2][i], 
          digits[10][i], digits[*min_p1][i], digits[*min_p2][i], mini_digits[*sec_p1][i], mini_digits[*sec_p2][i]);
  }
  fflush(stdout);
  printf("\033[H");
  printf("\033[J");
  printf("\033[3J");
}
