#include <linux/types.h>
#include <cust_acc.h>
#include <mach/mt_pm_ldo.h>


/*---------------------------------------------------------------------------*/
static struct acc_hw cust_acc_hw = {
    .i2c_num = 1,//0,
    .direction = 5,//7,//6,//0,//3,
    .power_id = MT6323_POWER_LDO_VIO18,//MT65XX_POWER_NONE,  /*!< LDO is not used */
    .power_vol= VOL_1800,//VOL_DEFAULT,        /*!< LDO is not used */
    .firlen = 0, //old value 16                /*!< don't enable low pass fileter */
};
/*---------------------------------------------------------------------------*/
struct acc_hw* get_cust_acc_hw(void) 
{
    return &cust_acc_hw;
}
