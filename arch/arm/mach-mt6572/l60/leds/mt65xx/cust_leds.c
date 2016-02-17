#include <cust_leds.h>
#include <cust_leds_def.h>
#include <mach/mt_pwm.h>
#include <linux/kernel.h>
#include <linux/leds.h>
#include <mach/pmic_mt6329_hw_bank1.h> 
#include <mach/pmic_mt6329_sw_bank1.h> 
#include <mach/pmic_mt6329_hw.h>
#include <mach/pmic_mt6329_sw.h>
#include <mach/upmu_common_sw.h>
#include <mach/upmu_hw.h>

extern int disp_bls_set_backlight(unsigned int level);

unsigned int brightness_mapping(unsigned int level)
{
    unsigned int mapped_level;
    
    mapped_level = level;
       
	return mapped_level;
}

unsigned int brightness_remap( unsigned int level )
{
unsigned int mapped_level;
unsigned int  tmp_map;

#if defined( LED_INCREASE_LED_LEVEL_MTKPATCH )
  tmp_map = ( level * 255 ) / 1023;
#else
  tmp_map = level;
#endif
  if( tmp_map > 255 )
    mapped_level = 255;
  else
    mapped_level = tmp_map;

	return mapped_level;
}

unsigned int Cust_SetBrightness(int level)
{
    disp_bls_set_backlight( brightness_remap( level ));
    return 0;
}

unsigned int Cust_SetBacklight(int level, int div)
{
  //mtkfb_set_backlight_pwm(div);
  //mtkfb_set_backlight_level(brightness_mapping(level));
    disp_bls_set_backlight(brightness_mapping(level));
    return 0;
}


static struct cust_mt65xx_led cust_led_list[MT65XX_LED_TYPE_TOTAL] = {
	{"red",               MT65XX_LED_MODE_NONE, -1, {0}},
	{"green",             MT65XX_LED_MODE_NONE, -1, {0}},
	{"blue",              MT65XX_LED_MODE_NONE, -1, {0}},
	{"jogball-backlight", MT65XX_LED_MODE_NONE, -1, {0}},
	{"keyboard-backlight",MT65XX_LED_MODE_NONE, -1, {0}},
	{"button-backlight",  MT65XX_LED_MODE_NONE, -1, {0}},
	//{"lcd-backlight",     MT65XX_LED_MODE_PWM, PWM1, {0,0,0,0,0}},
	//{"lcd-backlight",     MT65XX_LED_MODE_CUST_LCM, (int)Cust_SetBacklight, {0,0,0,0,0}},  /* PWM_BL */
	//{"lcd-backlight",     MT65XX_LED_MODE_CUST_BLS_PWM, (int)disp_bls_set_backlight, {0,0,0,0,0}}
	{"lcd-backlight",     MT65XX_LED_MODE_CUST_BLS_PWM, (int)Cust_SetBrightness, {0,0,0,0,0}}
};

struct cust_mt65xx_led *get_cust_led_list(void)
{
	return cust_led_list;
}

