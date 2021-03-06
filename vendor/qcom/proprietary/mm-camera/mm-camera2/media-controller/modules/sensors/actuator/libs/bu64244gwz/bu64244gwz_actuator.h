/**
 * bu64244gwz_actuator.h
 *
 * DESCRIPTION
 *  Auto-Generated by Actuator tool.
 *
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 */
  {
    .actuator_params =
    {
      .module_name = "rohm",
      .actuator_name = "bu64244gwz",
      .i2c_addr = 0x18,
      .i2c_data_type = CAMERA_I2C_BYTE_DATA,
      .i2c_addr_type = CAMERA_I2C_BYTE_ADDR,
      .act_type = ACTUATOR_TYPE_VCM,
      .data_size = 10,
      .reg_tbl =
      {
        .reg_tbl_size = 1,
        .reg_params =
        {
          {
            .reg_write_type = ACTUATOR_WRITE_DAC,
            .hw_mask = 0x0000c400,
            .reg_addr = 0xFFFF,
            .hw_shift = 0,
            .data_shift = 0,
          },
        },
      },
      .init_setting_size = 4,
      .init_settings =
      {
        {
          .reg_addr = 0xCC,
          .addr_type = CAMERA_I2C_BYTE_ADDR,
          .reg_data = 0x43,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .i2c_operation = ACTUATOR_I2C_OP_WRITE,
          .delay = 0,
        },
        {
          .reg_addr = 0xD4,
          .addr_type = CAMERA_I2C_BYTE_ADDR,
          .reg_data = 0x3C,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .i2c_operation = ACTUATOR_I2C_OP_WRITE,
          .delay = 0,
        },
        {
          .reg_addr = 0xDC,
          .addr_type = CAMERA_I2C_BYTE_ADDR,
          .reg_data = 0x78,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .i2c_operation = ACTUATOR_I2C_OP_WRITE,
          .delay = 0,
        },
        {
          .reg_addr = 0xE4,
          .addr_type = CAMERA_I2C_BYTE_ADDR,
          .reg_data = 0x6F,
          .data_type = CAMERA_I2C_BYTE_DATA,
          .i2c_operation = ACTUATOR_I2C_OP_WRITE,
          .delay = 0,
        },
      },
    }, /* actuator_params */

    .actuator_tuned_params =
    {
      .scenario_size =
      {
        1, /* MOVE_NEAR */
        1, /* MOVE_FAR */
      },
      .ringing_scenario =
      {
        /* MOVE_NEAR */
        {
          400,
        },
        /* MOVE_FAR */
        {
          400,
        },
      },
      .initial_code = 118,
      .region_size = 1,
      .region_params =
      {
        {
          .step_bound =
          {
            400, /* Macro step boundary*/
            0, /* Infinity step boundary*/
          },
          .code_per_step = 2,
          .qvalue = 1024,
        },
      },
      .damping =
      {
        /* damping[MOVE_NEAR] */
        {
          /* Scenario 0 */
          {
            .ringing_params =
            {
              /* Region 0 */
              {
                .damping_step = 0x3FF,
                .damping_delay = 5000,
                .hw_params = 0xC400,
              },
            },
          },
        },
        /* damping[MOVE_FAR] */
        {
          /* Scenario 0 */
          {
            .ringing_params =
            {
              /* Region 0 */
              {
                .damping_step = 0x3FF,
                .damping_delay = 5000,
                .hw_params = 0xC400,
              },
            },
          },
        },
      },
    }, /* actuator_tuned_params */
  },
