/*
 * Realtek Semiconductor Corp.
 *
 * libs/rtsisp/rtsisp_cmdcode.h
 *
 * Copyright (C) 2014      Ming Qian<ming_qian@realsil.com.cn>
 */
#ifndef _LIBS_RTSISP_RTSISP_CMDCODE_H
#define _LIBS_RTSISP_RTSISP_CMDCODE_H

#define RTS_ISP_CMD_XMEM_R			((0x00 << 8) | 0x81)
#define RTS_ISP_CMD_XMEM_W			((0x00 << 8) | 0x01)
#define RTS_ISP_CMD_I2C_R			((0x00 << 8) | 0x82)
#define RTS_ISP_CMD_I2C_W			((0x00 << 8) | 0x02)
#define RTS_ISP_CMD_READ_SENSOR_REG		((0x00 << 8) | 0x83)
#define RTS_ISP_CMD_WRITE_SENSOR_REG		((0x00 << 8) | 0x03)

#define RTS_ISP_CMD_GET_DEVICE_DES		((0x01 << 8) | 0x81)
#define RTS_ISP_CMD_GET_FW_VERSION		((0x01 << 8) | 0x88)
#define RTS_ISP_CMD_GET_API_VERSION		((0x01 << 8) | 0x8a)

#define RTS_ISP_CMD_SET_OUTPUT_FMT		((0x02 << 8) | 0x04)
#define RTS_ISP_CMD_SET_CROP_WINDOW		((0x02 << 8) | 0x08)

#define RTS_ISP_CMD_GET_SNR_FMT			((0x06 << 8) | 0x81)
#define RTS_ISP_CMD_GET_SCALE_COEFF		((0x06 << 8) | 0x82)
#define RTS_ISP_CMD_GET_ZOOM_START		((0x06 << 8) | 0x83)
#define RTS_ISP_CMD_SET_MTD_ENABLE		((0x07 << 8) | 0x01)
#define RTS_ISP_CMD_GET_MTD_ENABLE		((0x07 << 8) | 0x81)
#define RTS_ISP_CMD_SET_MTD_DAT_FMT		((0x07 << 8) | 0x02)
#define RTS_ISP_CMD_GET_MTD_DAT_FMT		((0x07 << 8) | 0x82)
#define RTS_ISP_CMD_SET_MTD_GRID_MASK		((0x07 << 8) | 0x03)
#define RTS_ISP_CMD_GET_MTD_GRID_MASK		((0x07 << 8) | 0x83)
#define RTS_ISP_CMD_SET_MTD_GRID		((0x07 << 8) | 0x04)
#define RTS_ISP_CMD_GET_MTD_GRID		((0x07 << 8) | 0x84)
#define RTS_ISP_CMD_SET_MTD_RECT		((0x07 << 8) | 0x05)
#define RTS_ISP_CMD_GET_MTD_RECT		((0x07 << 8) | 0x85)
#define RTS_ISP_CMD_SET_MTD_GRID_ABS		((0x07 << 8) | 0x06)
#define RTS_ISP_CMD_GET_MTD_GRID_ABS		((0x07 << 8) | 0x86)
#define RTS_ISP_CMD_SET_MTD_RECT_ABS		((0x07 << 8) | 0x07)
#define RTS_ISP_CMD_GET_MTD_RECT_ABS		((0x07 << 8) | 0x87)
#define RTS_ISP_CMD_SET_MTD_SENSITIVITY		((0x07 << 8) | 0x08)
#define RTS_ISP_CMD_GET_MTD_SENSITIVITY		((0x07 << 8) | 0x88)
#define RTS_ISP_CMD_SET_MTD_PERCENTAGE		((0x07 << 8) | 0x09)
#define RTS_ISP_CMD_GET_MTD_PERCENTAGE		((0x07 << 8) | 0x89)
#define RTS_ISP_CMD_SET_MTD_FRM_INTVAL		((0x07 << 8) | 0x0a)
#define RTS_ISP_CMD_GET_MTD_FRM_INTVAL		((0x07 << 8) | 0x8a)
#define RTS_ISP_CMD_SET_MTD_GRID_RES		((0x07 << 8) | 0x0b)
#define RTS_ISP_CMD_GET_MTD_GRID_RES		((0x07 << 8) | 0x8b)
#define RTS_ISP_CMD_SET_MTD_RECT_RES		((0x07 << 8) | 0x0c)
#define RTS_ISP_CMD_GET_MTD_RECT_RES		((0x07 << 8) | 0x8c)
#define RTS_ISP_CMD_GET_MTD_RESULT		((0x07 << 8) | 0x8d)

#define RTS_ISP_CMD_SET_OSD_LIB_CHAR_ATTR	((0x08 << 8) | 0x01)
#define RTS_ISP_CMD_GET_OSD_LIB_CHAR_ATTR	((0x08 << 8) | 0x81)
#define RTS_ISP_CMD_SET_OSD_CHINESE_ADDR	((0x08 << 8) | 0x02)
#define RTS_ISP_CMD_GET_OSD_CHINESE_ADDR	((0x08 << 8) | 0x82)
#define RTS_ISP_CMD_SET_OSD_TIME_DATE_EN	((0x08 << 8) | 0x03)
#define RTS_ISP_CMD_GET_OSD_TIME_DATE_EN	((0x08 << 8) | 0x83)
#define RTS_ISP_CMD_SET_OSD_TIME_DATE_DISP_CFG	((0x08 << 8) | 0x04)
#define RTS_ISP_CMD_GET_OSD_TIME_DATE_DISP_CFG	((0x08 << 8) | 0x84)
#define RTS_ISP_CMD_SET_OSD_TIME_FMT		((0x08 << 8) | 0x05)
#define RTS_ISP_CMD_GET_OSD_TIME_FMT		((0x08 << 8) | 0x85)
#define RTS_ISP_CMD_SET_OSD_CUR_TIME		((0x08 << 8) | 0x06)
#define RTS_ISP_CMD_SET_OSD_CUR_DATE		((0x08 << 8) | 0x07)
#define RTS_ISP_CMD_SET_OSD_NEXT_DATE		((0x08 << 8) | 0x08)
#define RTS_ISP_CMD_SET_OSD_BLK_EN		((0x08 << 8) | 0x09)
#define RTS_ISP_CMD_GET_OSD_BLK_EN		((0x08 << 8) | 0x89)
#define RTS_ISP_CMD_SET_OSD_BLK_ATTR		((0x08 << 8) | 0x0a)
#define RTS_ISP_CMD_GET_OSD_BLK_ATTR		((0x08 << 8) | 0x8a)
#define RTS_ISP_CMD_WRITE_OSD_MEM		((0x08 << 8) | 0x0b)
#define RTS_ISP_CMD_READ_OSD_MEM		((0x08 << 8) | 0x8b)
#define RTS_ISP_CMD_GET_OSD_MEM_SIZE		((0x08 << 8) | 0x8c)

#define RTS_ISP_CMD_SET_MASK_ENABLE		((0x09 << 8) | 0x01)
#define RTS_ISP_CMD_GET_MASK_ENABLE		((0x09 << 8) | 0x81)
#define RTS_ISP_CMD_SET_MASK_COLOR		((0x09 << 8) | 0x02)
#define RTS_ISP_CMD_GET_MASK_COLOR		((0x09 << 8) | 0x82)
#define RTS_ISP_CMD_SET_MASK_GRID_BITMAP	((0x09 << 8) | 0x03)
#define RTS_ISP_CMD_GET_MASK_GRID_BITMAP	((0x09 << 8) | 0x83)
#define RTS_ISP_CMD_SET_MASK_GRID		((0x09 << 8) | 0x04)
#define RTS_ISP_CMD_GET_MASK_GRID		((0x09 << 8) | 0x84)
#define RTS_ISP_CMD_SET_MASK_RECT		((0x09 << 8) | 0x05)
#define RTS_ISP_CMD_GET_MASK_RECT		((0x09 << 8) | 0x85)
#define RTS_ISP_CMD_SET_MASK_GRID_ABSOLUTE	((0x09 << 8) | 0x06)
#define RTS_ISP_CMD_GET_MASK_GRID_ABSOLUTE	((0x09 << 8) | 0x86)
#define RTS_ISP_CMD_SET_MASK_RECT_ABSOLUTE	((0x09 << 8) | 0x07)
#define RTS_ISP_CMD_GET_MASK_RECT_ABSOLUTE	((0x09 << 8) | 0x87)
#define RTS_ISP_CMD_SET_MASK_GRID_RES		((0x09 << 8) | 0x08)
#define RTS_ISP_CMD_GET_MASK_GRID_RES		((0x09 << 8) | 0x88)
#define RTS_ISP_CMD_SET_MASK_RECT_RES		((0x09 << 8) | 0x09)
#define RTS_ISP_CMD_GET_MASK_RECT_RES		((0x09 << 8) | 0x89)

#define RTS_ISP_CMD_SET_ISP_FUN_ENABLE		((0x0a << 8) | 0x01)
#define RTS_ISP_CMD_GET_ISP_FUN_ENABLE		((0x0a << 8) | 0x81)
#define RTS_ISP_CMD_SET_ISP_GRAY_MODE		((0x0a << 8) | 0x02)
#define RTS_ISP_CMD_GET_ISP_GRAY_MODE		((0x0a << 8) | 0x82)
#define RTS_ISP_CMD_GET_IQ_TABLE_ATTR		((0x0a << 8) | 0x83)
#define RTS_ISP_CMD_GET_3A_VERSION		((0x0a << 8) | 0x84)
#define RTS_ISP_CMD_SET_WDR_MODE		((0x0a << 8) | 0x05)
#define RTS_ISP_CMD_GET_WDR_MODE		((0x0a << 8) | 0x85)
#define RTS_ISP_CMD_SET_WDR_LEVEL		((0x0a << 8) | 0x06)
#define RTS_ISP_CMD_GET_WDR_LEVEL		((0x0a << 8) | 0x86)
#define RTS_ISP_CMD_SET_TPNR_LEVEL		((0x0a << 8) | 0x07)
#define RTS_ISP_CMD_GET_TPNR_LEVEL		((0x0a << 8) | 0x87)
#define RTS_ISP_CMD_SET_IR_MODE			((0x0a << 8) | 0x08)
#define RTS_ISP_CMD_GET_IR_MODE			((0x0a << 8) | 0x88)
#define RTS_ISP_CMD_GET_AE_GAIN			((0x0a << 8) | 0x89)
#define RTS_ISP_CMD_SET_AE_GAIN			((0x0a << 8) | 0x09)
#define RTS_ISP_CMD_GET_AE_WEIGHT		((0x0a << 8) | 0x8a)
#define RTS_ISP_CMD_SET_AE_WEIGHT		((0x0a << 8) | 0x0a)
#define RTS_ISP_CMD_GET_AE_STATIS		((0x0a << 8) | 0x8b)
#define RTS_ISP_CMD_GET_AWB_STATIS		((0x0a << 8) | 0x8c)
#define RTS_ISP_CMD_GET_AWB_CT_GAIN		((0x0a << 8) | 0x8d)
#define RTS_ISP_CMD_GET_AT_TARGET_DELTA		((0x0a << 8) | 0x8e)
#define RTS_ISP_CMD_SET_AT_TARGET_DELTA		((0x0a << 8) | 0x0e)

#define RTS_ISP_CMD_GET_FT2_ISP_STATIS		((0x0b << 8) | 0x81)
#define RTS_ISP_CMD_GET_GPIO_USE_STATUS		((0x0c << 8) | 0x81)
#define RTS_ISP_CMD_SET_GPIO_DIR		((0x0c << 8) | 0x02)
#define RTS_ISP_CMD_GET_GPIO_DIR		((0x0c << 8) | 0x82)
#define RTS_ISP_CMD_SET_GPIO_VALUE		((0x0c << 8) | 0x03)
#define RTS_ISP_CMD_GET_GPIO_VALUE		((0x0c << 8) | 0x83)

#endif
