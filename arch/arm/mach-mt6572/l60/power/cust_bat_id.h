#ifndef _BAT_ID_H_
#define _BAT_ID_H_

#define GPIO_BATTERY_DATA_PIN         GPIO20
#define GPIO_BATTERY_DATA_PIN_M_GPIO  GPIO_MODE_00

#define CHK_BATTERY_ID
#define BATTERY_PACK_ERROR    0
#define BATTERY_PACK_BL_44JH  1 //1700mAh
#define BATTERY_PACK_BL_44JN  2 //1540mAh

extern kal_uint8 battery_pack_id;

extern void bat_id_init_pin(void);
extern void bat_id_deinit_pin(void);
#endif //ifndef _BAT_ID_H_
