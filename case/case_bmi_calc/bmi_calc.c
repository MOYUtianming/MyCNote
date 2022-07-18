/**
 * @file bmiCalc.c
 * @brief function for calc BMI
 * @version 0.1
 * @author LvHui (mccflv@gmail.com)
 * @date 2022-06-12
 * Copyright © 2022 - 2022 lvhui, All Rights Reserved
 */
#include "main.h"

#define HOURS_A_DAY 24
#define AVG_METABOLIC_RATE 37.9
/**
 * @brief
 *
 * @param height cm
 * @param weight kg
 * @return int
 * @date 2022-06-12
 */
int BasicMetaBolicCalc(const double height, const double weight)
{
    double bodySurfaceArea = 0.00607 * height + 0.0127 * weight -0.0698;
    double answer = AVG_METABOLIC_RATE * bodySurfaceArea * HOURS_A_DAY;
    printf("average metabolic rate of me (1d):\t %lf\n",answer);
    return answer;
}

/**
 * @brief
 *
 * @param argv
 * @param argc
 * @return int
 * @date 2022-06-12
 */
int main(int argv, char** argc)
{
    const double height = 169;//cm
    const double weight = 100;//kg
    BasicMetaBolicCalc(height, weight);
    return 0;
}
