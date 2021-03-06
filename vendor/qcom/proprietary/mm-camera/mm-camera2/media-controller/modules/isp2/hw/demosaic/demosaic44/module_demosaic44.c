/* module_demosaic44.c
 *
 * Copyright (c) 2012-2013 Qualcomm Technologies, Inc. All Rights Reserved.
 * Qualcomm Technologies Proprietary and Confidential.
 */

/* std headers */
#include <stdio.h>

/* mctl headers */
#include "media_controller.h"
#include "mct_list.h"
#include "mct_module.h"
#include "mct_port.h"
#include "chromatix.h"

#undef ISP_DBG
#define ISP_DBG(fmt, args...) \
  ISP_DBG_MOD(ISP_LOG_DEMOSAIC, fmt, ##args)
#undef ISP_HIGH
#define ISP_HIGH(fmt, args...) \
  ISP_HIGH_MOD(ISP_LOG_DEMOSAIC, fmt, ##args)

/* isp headers */
#include "isp_common.h"
#include "isp_sub_module_log.h"
#include "module_demosaic44.h"
#include "demosaic44.h"
#include "isp_sub_module_common.h"
#include "isp_sub_module.h"
#include "isp_sub_module_port.h"

#define DEMOSAIC_ENABLE_BIT 4

/* TODO pass from Android.mk */
#define DEMOSAIC40_VERSION "44"

#define DEMOSAIC40_MODULE_NAME(n) \
  "demosaic"n

static isp_sub_module_private_func_t demosaic44_private_func = {
  .isp_sub_module_init_data              = demosaic44_init,
  .isp_sub_module_destroy                = demosaic44_destroy,

  .control_event_handler = {
    [ISP_CONTROL_EVENT_STREAMON]         = demosaic44_streamon,
    [ISP_CONTROL_EVENT_STREAMOFF]        = demosaic44_streamoff,
    [ISP_CONTROL_EVENT_SET_PARM]         = isp_sub_module_port_set_param,
  },

  .module_event_handler = {
    [ISP_MODULE_EVENT_SET_CHROMATIX_PTR] =
      isp_sub_module_port_set_chromatix_ptr,
    [ISP_MODULE_EVENT_STATS_AEC_UPDATE]  = demosaic44_stats_aec_update,
    [ISP_MODULE_EVENT_STATS_AWB_UPDATE]  = demosaic44_stats_awb_update,
    [ISP_MODULE_EVENT_MANUAL_AWB_UPDATE] = demosaic44_stats_awb_update,
    [ISP_MODULE_EVENT_ISP_PRIVATE_EVENT] =
      isp_sub_module_port_isp_private_event,
  },

  .isp_private_event_handler = {
    [ISP_PRIVATE_GET_VFE_DIAG_INFO_USER] = demosaic44_get_vfe_diag_info_user,
    [ISP_PRIVATE_SET_MOD_ENABLE]         = isp_sub_module_port_enable,
    [ISP_PRIVATE_SET_TRIGGER_ENABLE]     = isp_sub_module_port_trigger_enable,
    [ISP_PRIVATE_ACTION_RESET]           = demosaic44_reset,
    [ISP_PRIVATE_SET_TRIGGER_UPDATE]     = demosaic44_trigger_update,
  },

  .set_param_handler = {
    [ISP_SET_PARM_SET_VFE_COMMAND] = isp_sub_module_port_set_vfe_command,
    [ISP_SET_PARM_UPDATE_DEBUG_LEVEL]   = isp_sub_module_port_set_log_level,
  },
};

/** module_demosaic44_init:
 *
 *  @name: name of ISP module - "demosaic44"
 *
 *  Initializes new instance of ISP module
 *
 *  create mct module for demosaic
 *
 *  Return mct module handle on success or NULL on failure
 **/
static mct_module_t *module_demosaic44_init(const char *name)
{
  boolean                ret = TRUE;
  mct_module_t          *module = NULL;

  ISP_HIGH("name %s", name);

  if (!name) {
    ISP_ERR("failed: name %s", name);
    return NULL;
  }

  if (strncmp(name, DEMOSAIC40_MODULE_NAME(DEMOSAIC40_VERSION), strlen(name))) {
    ISP_ERR("failed: invalid name %s expected %s", name,
      DEMOSAIC40_MODULE_NAME(DEMOSAIC40_VERSION));
    return NULL;
  }

  module = isp_sub_module_init(name, NUM_SINK_PORTS, NUM_SOURCE_PORTS,
    &demosaic44_private_func, ISP_MOD_DEMOSAIC, "demosaic",
    ISP_LOG_DEMOSAIC);
  if (!module || !MCT_OBJECT_PRIVATE(module)) {
    ISP_ERR("module %p", module);
    goto ERROR1;
  }

  return module;

ERROR1:
  if (module) {
    mct_module_destroy(module);
  }
  ISP_ERR("failed");
  return NULL;
}

/** module_demosaic44_deinit:
 *
 *  @module: isp module handle
 *
 *  Deinit isp module
 *
 *  Returns: void
 **/
static void module_demosaic44_deinit(mct_module_t *module)
{
  if (!module) {
    ISP_ERR("failed: module %p", module);
    return;
  }

  isp_sub_module_deinit(module);
}

static isp_submod_init_table_t submod_init_table = {
  .module_init = module_demosaic44_init,
  .module_deinit = module_demosaic44_deinit,
};

/** module_open:
 *
 *  Return handle to isp_submod_init_table_t
 **/
isp_submod_init_table_t *module_open(void)
{
  return &submod_init_table;
}
