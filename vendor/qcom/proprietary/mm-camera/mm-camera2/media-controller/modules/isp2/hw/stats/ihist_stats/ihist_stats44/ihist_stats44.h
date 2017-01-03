/* ihist_stats44.h
 *
 * Copyright (c) 2013-2014 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __IHIST_STATS_44_H__
#define __IHIST_STATS_44_H__

/* mctl headers */
#include "modules.h"
#include "mct_event_stats.h"

/* isp headers */
#include "ihist_stats_reg.h"
#include "isp_sub_module_common.h"

/** ihist_stats44_t:
 *
 *  @pcmd: hardware configuration
 *  @ispif_out_info: ispif out info
 *  @isp_out_info: isp out info
 *  @af_config: af config params
 *  @sensor_out_info: sensor out info
 *  @num_left_rgns: number of left regions
 *  @num_right_rgns: number of right regions
 **/
typedef struct {
  ISP_StatsIhist_CfgType pcmd;
  ispif_out_info_t       ispif_out_info;
  isp_out_info_t         isp_out_info;
  sensor_out_info_t      sensor_out_info;
  uint32_t               num_left_rgns;
  uint32_t               num_right_rgns;
} ihist_stats44_t;

boolean ihist_stats44_trigger_update(isp_sub_module_t *isp_sub_module,
  void *data);

boolean ihist_stats44_streamoff(isp_sub_module_t *isp_sub_module,
  void *data);

boolean ihist_stats44_init(isp_sub_module_t *isp_sub_module);

void ihist_stats44_destroy(isp_sub_module_t *isp_sub_module);

boolean ihist_stats44_set_stream_config(isp_sub_module_t *isp_sub_module,
  void *data);

boolean ihist_stats44_set_split_info(isp_sub_module_t *isp_sub_module,
  void *data);

boolean ihist_stats44_set_stripe_info(isp_sub_module_t *isp_sub_module,
  void *data);
#endif /* __IHIST_STATS_44_H__ */