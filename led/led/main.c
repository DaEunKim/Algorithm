//
//  main.c
//  led
//
//  Created by 김다은 on 2016. 11. 24..
//  Copyright © 2016년 김다은. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


const char *PATH_GPIO_EXPORT = "/sys/class/gpio/export";
const char *PATH_GPIO_UNEXPORT = "/sys/class/gpio/unexport";
const char *PATH_GPIO_17_DIRECTION = "/sys/class/gpio/gpio17/direction";
const char *PATH_GPIO_17_VALUE = "/sys/class/gpio/gpio17/value";


#define GPIO_NUM 17


typedef enum {
    OFF = 0,
    ON
} gpio_state ;


void gpio_init();
void gpio_exit();
void set_gpio_state(gpio_state state);


FILE *GPIO_EXPORT;
FILE *GPIO_17_DIRECTION;
FILE *GPIO_17_VALUE;


int main()
{
    int time = 0;
    gpio_state state = OFF;
    
    
    gpio_init();
    
    
    /**************** insert your code here ******************/
    
    int i;
    for(i=0; i<5000;i++){
        set_gpio_state(1);
        usleep(5000-i);
        
        set_gpio_state(0);
        usleep(1000-i);
        
    }
    
    
    /*********************************************************/
    
    
    gpio_exit();
}


void gpio_init()
{
    if ((GPIO_EXPORT = fopen(PATH_GPIO_EXPORT, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_EXPORT);
        exit(0);
    }
    
    
    fprintf(GPIO_EXPORT, "%d", GPIO_NUM);
    fclose(GPIO_EXPORT);
    
    
    if ((GPIO_17_DIRECTION = fopen(PATH_GPIO_17_DIRECTION, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_17_DIRECTION);
        exit(0);
    }
    fprintf(GPIO_17_DIRECTION, "out");
    fclose(GPIO_17_DIRECTION);
    
    
    if ((GPIO_17_VALUE = fopen(PATH_GPIO_17_VALUE, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_17_VALUE);
        exit(0);
    }
}
void gpio_exit()
{
    FILE *GPIO_UNEXPORT;
    
    
    fclose(GPIO_17_VALUE);
    
    if ((GPIO_UNEXPORT = fopen(PATH_GPIO_UNEXPORT, "w")) == NULL) {
        printf("%s open failed\n", PATH_GPIO_UNEXPORT);
        exit(0);
    }
    fprintf(GPIO_UNEXPORT, "%d", GPIO_NUM);
    close(GPIO_UNEXPORT);
}




void set_gpio_state(gpio_state state) 
{
    fprintf(GPIO_17_VALUE, "%d", state);
    fflush(GPIO_17_VALUE);
}
