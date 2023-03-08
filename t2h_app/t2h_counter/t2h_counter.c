/*
 * t2h_counter.c
 *
 *  Created on: Jul 26, 2021
 *      Author: ad565
 */
#include "t2h_counter.h"



int t2h_cnt_update(int count,char cnt_mode,char division)
{
    static int cnt_clock;
    static char cnt_direction;
	static char is_cnt_enable = 1;
	static int cnt_out;

    if(is_cnt_enable == 1) {
        if (cnt_direction == 0)
        {
            cnt_clock++;
        }
        else
        {
            cnt_clock--;
        }

        if (cnt_clock == (int)count*division || cnt_clock == 0)
		{
			if (cnt_mode == ONCE_CNT)
			{
				is_cnt_enable = 0;
			}
			else if (cnt_mode == ROUND_CNT)
			{
				cnt_direction = !cnt_direction;
			}
			else if (cnt_mode == LOOP_CNT)
			{
				cnt_clock = 0;
			}
        }
    }

    //分频器
    return cnt_out = (int)cnt_clock/division;
}

