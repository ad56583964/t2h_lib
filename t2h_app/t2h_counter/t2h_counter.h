/*
 * t2h_counter.h
 *
 *  Created on: Jul 26, 2021
 *      Author: ad565
 */

#ifndef T2H_APP_T2H_COUNTER_T2H_COUNTER_H_
#define T2H_APP_T2H_COUNTER_T2H_COUNTER_H_

enum {
    ONCE_CNT,
    LOOP_CNT,
    ROUND_CNT
};


int t2h_cnt_update(int count,char cnt_mode,char division);



#endif /* T2H_APP_T2H_COUNTER_T2H_COUNTER_H_ */
