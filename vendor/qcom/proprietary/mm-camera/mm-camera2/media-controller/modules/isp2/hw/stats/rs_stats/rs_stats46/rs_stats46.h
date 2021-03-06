/* rs_stats46.h
 *
 * Copyright (c) 2012-2014 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

#ifndef __RS_STATS_46_H__
#define __RS_STATS_46_H__

/* mctl headers */
#include "modules.h"
#include "mct_event_stats.h"

/* isp headers */
#include "rs_stats_reg.h"
#include "isp_sub_module_common.h"

/** rs_stats46_t:
 *
 *  @pcmd: hardware configuration
 *  @ispif_out_info: ispif out info
 *  @isp_out_info: isp out info
 *  @sensor_out_info: sensor out info
 *  @num_left_rgns: number of left regions
 *  @num_right_rgns: number of right regions
 **/
typedef struct {
  ISP_Stats_CfgType   init_pcmd;
  ISP_StatsRs_CfgType rs_pcmd;
  ispif_out_info_t    ispif_out_info;
  isp_out_info_t      isp_out_info;
  sensor_out_info_t   sensor_out_info;
  uint32_t            num_left_rgns;
  uint32_t            num_right_rgns;
  mct_stats_rs_caps_t rs_caps;
  rs_config_t         rs_config;
} rs_stats46_t;

boolean rs_stats46_trigger_update(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_fetch_rs_info(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_streamoff(isp_sub_module_t *isp_sub_module, void *data);

boolean rs_stats46_init(isp_sub_module_t *isp_sub_module);

void rs_stats46_destroy(isp_sub_module_t *isp_sub_module);

boolean rs_stats46_set_stream_config(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_set_split_info(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_set_stripe_info(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_stats_config_update(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_update_min_stripe_overlap(isp_sub_module_t *isp_sub_module,
  void *data);

boolean rs_stats46_get_stats_capabilities(isp_sub_module_t *isp_sub_module,
  void *data);

#endif /* __RS_STATS_46_H__ */
