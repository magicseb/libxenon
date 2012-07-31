#ifndef __drivers_time_time_h
#define __drivers_time_time_h

#ifdef __cplusplus
extern "C" {
#endif

extern void udelay(int);
extern void mdelay(int);
extern void delay(int);
extern void tsleep(uint64_t u);
extern void usleep(int u);
extern void msleep(int u);
extern void sleep(int u);


#ifdef __cplusplus
};
#endif

#endif
