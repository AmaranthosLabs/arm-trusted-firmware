/*
 * Copyright (c) 2016, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PMU_H__
#define __PMU_H__

/* Allocate sp reginon in pmusram */
#define PSRAM_SP_SIZE		0x80
#define PSRAM_SP_BOTTOM		(PSRAM_SP_TOP - PSRAM_SP_SIZE)

/*****************************************************************************
 * Common define for per soc pmu.h
 *****************************************************************************/
/* The ways of cores power domain contorlling */
enum cores_pm_ctr_mode {
	core_pwr_pd = 0,
	core_pwr_wfi = 1,
	core_pwr_wfi_int = 2
};

/*****************************************************************************
 * pmu con,reg
 *****************************************************************************/
#define PMU_WKUP_CFG(n)	((n) * 4)

#define PMU_CORE_PM_CON(cpu)		(0xc0 + (cpu * 4))

/* the shift of bits for cores status */
enum pmu_core_pwrst_shift {
	clstl_cpu_wfe = 2,
	clstl_cpu_wfi = 6,
	clstb_cpu_wfe = 12,
	clstb_cpu_wfi = 16
};

#define CKECK_WFE_MSK		0x1
#define CKECK_WFI_MSK		0x10
#define CKECK_WFEI_MSK		0x11

enum pmu_powerdomain_id {
	PD_CPUL0 = 0,
	PD_CPUL1,
	PD_CPUL2,
	PD_CPUL3,
	PD_CPUB0,
	PD_CPUB1,
	PD_SCUL,
	PD_SCUB,
	PD_TCPD0,
	PD_TCPD1,
	PD_CCI,
	PD_PERILP,
	PD_PERIHP,
	PD_CENTER,
	PD_VIO,
	PD_GPU,
	PD_VCODEC,
	PD_VDU,
	PD_RGA,
	PD_IEP,
	PD_VO,
	PD_ISP0 = 22,
	PD_ISP1,
	PD_HDCP,
	PD_GMAC,
	PD_EMMC,
	PD_USB3,
	PD_EDP,
	PD_GIC,
	PD_SD,
	PD_SDIOAUDIO,
	PD_END
};

enum powerdomain_state {
	PMU_POWER_ON = 0,
	PMU_POWER_OFF,
};

enum pmu_bus_id {
	BUS_ID_GPU = 0,
	BUS_ID_PERILP,
	BUS_ID_PERIHP,
	BUS_ID_VCODEC,
	BUS_ID_VDU,
	BUS_ID_RGA,
	BUS_ID_IEP,
	BUS_ID_VOPB,
	BUS_ID_VOPL,
	BUS_ID_ISP0,
	BUS_ID_ISP1,
	BUS_ID_HDCP,
	BUS_ID_USB3,
	BUS_ID_PERILPM0,
	BUS_ID_CENTER,
	BUS_ID_CCIM0,
	BUS_ID_CCIM1,
	BUS_ID_VIO,
	BUS_ID_MSCH0,
	BUS_ID_MSCH1,
	BUS_ID_ALIVE,
	BUS_ID_PMU,
	BUS_ID_EDP,
	BUS_ID_GMAC,
	BUS_ID_EMMC,
	BUS_ID_CENTER1,
	BUS_ID_PMUM0,
	BUS_ID_GIC,
	BUS_ID_SD,
	BUS_ID_SDIOAUDIO,
};

enum pmu_bus_state {
	BUS_ACTIVE,
	BUS_IDLE,
};

/* pmu_cpuapm bit */
enum pmu_cores_pm_by_wfi {
	core_pm_en = 0,
	core_pm_int_wakeup_en,
	core_pm_resv,
	core_pm_sft_wakeup_en
};

enum pmu_wkup_cfg0 {
	PMU_GPIO0A_POSE_WKUP_EN = 0,
	PMU_GPIO0B_POSE_WKUP_EN = 8,
	PMU_GPIO0C_POSE_WKUP_EN = 16,
	PMU_GPIO0D_POSE_WKUP_EN = 24,
};

enum pmu_wkup_cfg1 {
	PMU_GPIO0A_NEGEDGE_WKUP_EN = 0,
	PMU_GPIO0B_NEGEDGE_WKUP_EN = 7,
	PMU_GPIO0C_NEGEDGE_WKUP_EN = 16,
	PMU_GPIO0D_NEGEDGE_WKUP_EN = 24,
};

enum pmu_wkup_cfg2 {
	PMU_GPIO1A_POSE_WKUP_EN = 0,
	PMU_GPIO1B_POSE_WKUP_EN = 7,
	PMU_GPIO1C_POSE_WKUP_EN = 16,
	PMU_GPIO1D_POSE_WKUP_EN = 24,
};

enum pmu_wkup_cfg3 {
	PMU_GPIO1A_NEGEDGE_WKUP_EN = 0,
	PMU_GPIO1B_NEGEDGE_WKUP_EN = 7,
	PMU_GPIO1C_NEGEDGE_WKUP_EN = 16,
	PMU_GPIO1D_NEGEDGE_WKUP_EN = 24,
};

/* pmu_wkup_cfg4 */
enum pmu_wkup_cfg4 {
	PMU_CLUSTER_L_WKUP_EN = 0,
	PMU_CLUSTER_B_WKUP_EN,
	PMU_GPIO_WKUP_EN,
	PMU_SDIO_WKUP_EN,

	PMU_SDMMC_WKUP_EN,
	PMU_TIMER_WKUP_EN = 6,
	PMU_USBDEV_WKUP_EN,

	PMU_SFT_WKUP_EN,
	PMU_M0_WDT_WKUP_EN,
	PMU_TIMEOUT_WKUP_EN,
	PMU_PWM_WKUP_EN,

	PMU_PCIE_WKUP_EN = 13,
};

enum pmu_pwrdn_con {
	PMU_A53_L0_PWRDWN_EN = 0,
	PMU_A53_L1_PWRDWN_EN,
	PMU_A53_L2_PWRDWN_EN,
	PMU_A53_L3_PWRDWN_EN,

	PMU_A72_B0_PWRDWN_EN,
	PMU_A72_B1_PWRDWN_EN,
	PMU_SCU_L_PWRDWN_EN,
	PMU_SCU_B_PWRDWN_EN,

	PMU_TCPD0_PWRDWN_EN,
	PMU_TCPD1_PWRDWN_EN,
	PMU_CCI_PWRDWN_EN,
	PMU_PERILP_PWRDWN_EN,

	PMU_PERIHP_PWRDWN_EN,
	PMU_CENTER_PWRDWN_EN,
	PMU_VIO_PWRDWN_EN,
	PMU_GPU_PWRDWN_EN,

	PMU_VCODEC_PWRDWN_EN,
	PMU_VDU_PWRDWN_EN,
	PMU_RGA_PWRDWN_EN,
	PMU_IEP_PWRDWN_EN,

	PMU_VO_PWRDWN_EN,
	PMU_ISP0_PWRDWN_EN = 22,
	PMU_ISP1_PWRDWN_EN,

	PMU_HDCP_PWRDWN_EN,
	PMU_GMAC_PWRDWN_EN,
	PMU_EMMC_PWRDWN_EN,
	PMU_USB3_PWRDWN_EN,

	PMU_EDP_PWRDWN_EN,
	PMU_GIC_PWRDWN_EN,
	PMU_SD_PWRDWN_EN,
	PMU_SDIOAUDIO_PWRDWN_EN,
};

enum pmu_pwrdn_st {
	PMU_A53_L0_PWRDWN_ST = 0,
	PMU_A53_L1_PWRDWN_ST,
	PMU_A53_L2_PWRDWN_ST,
	PMU_A53_L3_PWRDWN_ST,

	PMU_A72_B0_PWRDWN_ST,
	PMU_A72_B1_PWRDWN_ST,
	PMU_SCU_L_PWRDWN_ST,
	PMU_SCU_B_PWRDWN_ST,

	PMU_TCPD0_PWRDWN_ST,
	PMU_TCPD1_PWRDWN_ST,
	PMU_CCI_PWRDWN_ST,
	PMU_PERILP_PWRDWN_ST,

	PMU_PERIHP_PWRDWN_ST,
	PMU_CENTER_PWRDWN_ST,
	PMU_VIO_PWRDWN_ST,
	PMU_GPU_PWRDWN_ST,

	PMU_VCODEC_PWRDWN_ST,
	PMU_VDU_PWRDWN_ST,
	PMU_RGA_PWRDWN_ST,
	PMU_IEP_PWRDWN_ST,

	PMU_VO_PWRDWN_ST,
	PMU_ISP0_PWRDWN_ST = 22,
	PMU_ISP1_PWRDWN_ST,

	PMU_HDCP_PWRDWN_ST,
	PMU_GMAC_PWRDWN_ST,
	PMU_EMMC_PWRDWN_ST,
	PMU_USB3_PWRDWN_ST,

	PMU_EDP_PWRDWN_ST,
	PMU_GIC_PWRDWN_ST,
	PMU_SD_PWRDWN_ST,
	PMU_SDIOAUDIO_PWRDWN_ST,

};

enum pmu_pll_con {
	PMU_PLL_PD_CFG = 0,
	PMU_SFT_PLL_PD = 8,
};

enum pmu_pwermode_con {
	PMU_PWR_MODE_EN = 0,
	PMU_WKUP_RST_EN,
	PMU_INPUT_CLAMP_EN,
	PMU_OSC_DIS,

	PMU_ALIVE_USE_LF,
	PMU_PMU_USE_LF,
	PMU_POWER_OFF_REQ_CFG,
	PMU_CHIP_PD_EN,

	PMU_PLL_PD_EN,
	PMU_CPU0_PD_EN,
	PMU_L2_FLUSH_EN,
	PMU_L2_IDLE_EN,

	PMU_SCU_PD_EN,
	PMU_CCI_PD_EN,
	PMU_PERILP_PD_EN,
	PMU_CENTER_PD_EN,

	PMU_SREF0_ENTER_EN,
	PMU_DDRC0_GATING_EN,
	PMU_DDRIO0_RET_EN,
	PMU_DDRIO0_RET_DE_REQ,

	PMU_SREF1_ENTER_EN,
	PMU_DDRC1_GATING_EN,
	PMU_DDRIO1_RET_EN,
	PMU_DDRIO1_RET_DE_REQ,

	PMU_CLK_CENTER_SRC_GATE_EN = 26,
	PMU_CLK_PERILP_SRC_GATE_EN,

	PMU_CLK_CORE_SRC_GATE_EN,
	PMU_DDRIO_RET_HW_DE_REQ,
	PMU_SLP_OUTPUT_CFG,
	PMU_MAIN_CLUSTER,
};

enum pmu_sft_con {
	PMU_WKUP_SFT = 0,
	PMU_INPUT_CLAMP_CFG,
	PMU_OSC_DIS_CFG,
	PMU_PMU_LF_EN_CFG,

	PMU_ALIVE_LF_EN_CFG,
	PMU_24M_EN_CFG,
	PMU_DBG_PWRUP_L0_CFG,
	PMU_WKUP_SFT_M0,

	PMU_DDRCTL0_C_SYSREQ_CFG,
	PMU_DDR0_IO_RET_CFG,

	PMU_DDRCTL1_C_SYSREQ_CFG = 12,
	PMU_DDR1_IO_RET_CFG,
	DBG_PWRUP_B0_CFG = 15,

	DBG_NOPWERDWN_L0_EN,
	DBG_NOPWERDWN_L1_EN,
	DBG_NOPWERDWN_L2_EN,
	DBG_NOPWERDWN_L3_EN,

	DBG_PWRUP_REQ_L_EN = 20,
	CLUSTER_L_CLK_SRC_GATING_CFG,
	L2_FLUSH_REQ_CLUSTER_L,
	ACINACTM_CLUSTER_L_CFG,

	DBG_NO_PWERDWN_B0_EN,
	DBG_NO_PWERDWN_B1_EN,

	DBG_PWRUP_REQ_B_EN = 28,
	CLUSTER_B_CLK_SRC_GATING_CFG,
	L2_FLUSH_REQ_CLUSTER_B,
	ACINACTM_CLUSTER_B_CFG,
};

enum pmu_int_con {
	PMU_PMU_INT_EN = 0,
	PMU_PWRMD_WKUP_INT_EN,
	PMU_WKUP_GPIO0_NEG_INT_EN,
	PMU_WKUP_GPIO0_POS_INT_EN,
	PMU_WKUP_GPIO1_NEG_INT_EN,
	PMU_WKUP_GPIO1_POS_INT_EN,
};

enum pmu_int_st {
	PMU_PWRMD_WKUP_INT_ST = 1,
	PMU_WKUP_GPIO0_NEG_INT_ST,
	PMU_WKUP_GPIO0_POS_INT_ST,
	PMU_WKUP_GPIO1_NEG_INT_ST,
	PMU_WKUP_GPIO1_POS_INT_ST,
};

enum pmu_gpio0_pos_int_con {
	PMU_GPIO0A_POS_INT_EN = 0,
	PMU_GPIO0B_POS_INT_EN = 8,
	PMU_GPIO0C_POS_INT_EN = 16,
	PMU_GPIO0D_POS_INT_EN = 24,
};

enum pmu_gpio0_neg_int_con {
	PMU_GPIO0A_NEG_INT_EN = 0,
	PMU_GPIO0B_NEG_INT_EN = 8,
	PMU_GPIO0C_NEG_INT_EN = 16,
	PMU_GPIO0D_NEG_INT_EN = 24,
};

enum pmu_gpio1_pos_int_con {
	PMU_GPIO1A_POS_INT_EN = 0,
	PMU_GPIO1B_POS_INT_EN = 8,
	PMU_GPIO1C_POS_INT_EN = 16,
	PMU_GPIO1D_POS_INT_EN = 24,
};

enum pmu_gpio1_neg_int_con {
	PMU_GPIO1A_NEG_INT_EN = 0,
	PMU_GPIO1B_NEG_INT_EN = 8,
	PMU_GPIO1C_NEG_INT_EN = 16,
	PMU_GPIO1D_NEG_INT_EN = 24,
};

enum pmu_gpio0_pos_int_st {
	PMU_GPIO0A_POS_INT_ST = 0,
	PMU_GPIO0B_POS_INT_ST = 8,
	PMU_GPIO0C_POS_INT_ST = 16,
	PMU_GPIO0D_POS_INT_ST = 24,
};

enum pmu_gpio0_neg_int_st {
	PMU_GPIO0A_NEG_INT_ST = 0,
	PMU_GPIO0B_NEG_INT_ST = 8,
	PMU_GPIO0C_NEG_INT_ST = 16,
	PMU_GPIO0D_NEG_INT_ST = 24,
};

enum pmu_gpio1_pos_int_st {
	PMU_GPIO1A_POS_INT_ST = 0,
	PMU_GPIO1B_POS_INT_ST = 8,
	PMU_GPIO1C_POS_INT_ST = 16,
	PMU_GPIO1D_POS_INT_ST = 24,
};

enum pmu_gpio1_neg_int_st {
	PMU_GPIO1A_NEG_INT_ST = 0,
	PMU_GPIO1B_NEG_INT_ST = 8,
	PMU_GPIO1C_NEG_INT_ST = 16,
	PMU_GPIO1D_NEG_INT_ST = 24,
};

/* pmu power down configure register 0x0050 */
enum pmu_pwrdn_inten {
	PMU_A53_L0_PWR_SWITCH_INT_EN = 0,
	PMU_A53_L1_PWR_SWITCH_INT_EN,
	PMU_A53_L2_PWR_SWITCH_INT_EN,
	PMU_A53_L3_PWR_SWITCH_INT_EN,

	PMU_A72_B0_PWR_SWITCH_INT_EN,
	PMU_A72_B1_PWR_SWITCH_INT_EN,
	PMU_SCU_L_PWR_SWITCH_INT_EN,
	PMU_SCU_B_PWR_SWITCH_INT_EN,

	PMU_TCPD0_PWR_SWITCH_INT_EN,
	PMU_TCPD1_PWR_SWITCH_INT_EN,
	PMU_CCI_PWR_SWITCH_INT_EN,
	PMU_PERILP_PWR_SWITCH_INT_EN,

	PMU_PERIHP_PWR_SWITCH_INT_EN,
	PMU_CENTER_PWR_SWITCH_INT_EN,
	PMU_VIO_PWR_SWITCH_INT_EN,
	PMU_GPU_PWR_SWITCH_INT_EN,

	PMU_VCODEC_PWR_SWITCH_INT_EN,
	PMU_VDU_PWR_SWITCH_INT_EN,
	PMU_RGA_PWR_SWITCH_INT_EN,
	PMU_IEP_PWR_SWITCH_INT_EN,

	PMU_VO_PWR_SWITCH_INT_EN,
	PMU_ISP0_PWR_SWITCH_INT_EN = 22,
	PMU_ISP1_PWR_SWITCH_INT_EN,

	PMU_HDCP_PWR_SWITCH_INT_EN,
	PMU_GMAC_PWR_SWITCH_INT_EN,
	PMU_EMMC_PWR_SWITCH_INT_EN,
	PMU_USB3_PWR_SWITCH_INT_EN,

	PMU_EDP_PWR_SWITCH_INT_EN,
	PMU_GIC_PWR_SWITCH_INT_EN,
	PMU_SD_PWR_SWITCH_INT_EN,
	PMU_SDIOAUDIO_PWR_SWITCH_INT_EN,
};

enum pmu_wkup_status {
	PMU_WKUP_BY_CLSTER_L_INT = 0,
	PMU_WKUP_BY_CLSTER_b_INT,
	PMU_WKUP_BY_GPIO_INT,
	PMU_WKUP_BY_SDIO_DET,

	PMU_WKUP_BY_SDMMC_DET,
	PMU_WKUP_BY_TIMER = 6,
	PMU_WKUP_BY_USBDEV_DET,

	PMU_WKUP_BY_M0_SFT,
	PMU_WKUP_BY_M0_WDT_INT,
	PMU_WKUP_BY_TIMEOUT,
	PMU_WKUP_BY_PWM,

	PMU_WKUP_BY_PCIE = 13,
};

enum pmu_bus_clr {
	PMU_CLR_GPU = 0,
	PMU_CLR_PERILP,
	PMU_CLR_PERIHP,
	PMU_CLR_VCODEC,

	PMU_CLR_VDU,
	PMU_CLR_RGA,
	PMU_CLR_IEP,
	PMU_CLR_VOPB,

	PMU_CLR_VOPL,
	PMU_CLR_ISP0,
	PMU_CLR_ISP1,
	PMU_CLR_HDCP,

	PMU_CLR_USB3,
	PMU_CLR_PERILPM0,
	PMU_CLR_CENTER,
	PMU_CLR_CCIM1,

	PMU_CLR_CCIM0,
	PMU_CLR_VIO,
	PMU_CLR_MSCH0,
	PMU_CLR_MSCH1,

	PMU_CLR_ALIVE,
	PMU_CLR_PMU,
	PMU_CLR_EDP,
	PMU_CLR_GMAC,

	PMU_CLR_EMMC,
	PMU_CLR_CENTER1,
	PMU_CLR_PMUM0,
	PMU_CLR_GIC,

	PMU_CLR_SD,
	PMU_CLR_SDIOAUDIO,
};

/* PMU bus idle request register */
enum pmu_bus_idle_req {
	PMU_IDLE_REQ_GPU = 0,
	PMU_IDLE_REQ_PERILP,
	PMU_IDLE_REQ_PERIHP,
	PMU_IDLE_REQ_VCODEC,

	PMU_IDLE_REQ_VDU,
	PMU_IDLE_REQ_RGA,
	PMU_IDLE_REQ_IEP,
	PMU_IDLE_REQ_VOPB,

	PMU_IDLE_REQ_VOPL,
	PMU_IDLE_REQ_ISP0,
	PMU_IDLE_REQ_ISP1,
	PMU_IDLE_REQ_HDCP,

	PMU_IDLE_REQ_USB3,
	PMU_IDLE_REQ_PERILPM0,
	PMU_IDLE_REQ_CENTER,
	PMU_IDLE_REQ_CCIM0,

	PMU_IDLE_REQ_CCIM1,
	PMU_IDLE_REQ_VIO,
	PMU_IDLE_REQ_MSCH0,
	PMU_IDLE_REQ_MSCH1,

	PMU_IDLE_REQ_ALIVE,
	PMU_IDLE_REQ_PMU,
	PMU_IDLE_REQ_EDP,
	PMU_IDLE_REQ_GMAC,

	PMU_IDLE_REQ_EMMC,
	PMU_IDLE_REQ_CENTER1,
	PMU_IDLE_REQ_PMUM0,
	PMU_IDLE_REQ_GIC,

	PMU_IDLE_REQ_SD,
	PMU_IDLE_REQ_SDIOAUDIO,
};

/* pmu bus idle status register */
enum pmu_bus_idle_st {
	PMU_IDLE_ST_GPU = 0,
	PMU_IDLE_ST_PERILP,
	PMU_IDLE_ST_PERIHP,
	PMU_IDLE_ST_VCODEC,

	PMU_IDLE_ST_VDU,
	PMU_IDLE_ST_RGA,
	PMU_IDLE_ST_IEP,
	PMU_IDLE_ST_VOPB,

	PMU_IDLE_ST_VOPL,
	PMU_IDLE_ST_ISP0,
	PMU_IDLE_ST_ISP1,
	PMU_IDLE_ST_HDCP,

	PMU_IDLE_ST_USB3,
	PMU_IDLE_ST_PERILPM0,
	PMU_IDLE_ST_CENTER,
	PMU_IDLE_ST_CCIM0,

	PMU_IDLE_ST_CCIM1,
	PMU_IDLE_ST_VIO,
	PMU_IDLE_ST_MSCH0,
	PMU_IDLE_ST_MSCH1,

	PMU_IDLE_ST_ALIVE,
	PMU_IDLE_ST_PMU,
	PMU_IDLE_ST_EDP,
	PMU_IDLE_ST_GMAC,

	PMU_IDLE_ST_EMMC,
	PMU_IDLE_ST_CENTER1,
	PMU_IDLE_ST_PMUM0,
	PMU_IDLE_ST_GIC,

	PMU_IDLE_ST_SD,
	PMU_IDLE_ST_SDIOAUDIO,
};

enum pmu_bus_idle_ack {
	PMU_IDLE_ACK_GPU = 0,
	PMU_IDLE_ACK_PERILP,
	PMU_IDLE_ACK_PERIHP,
	PMU_IDLE_ACK_VCODEC,

	PMU_IDLE_ACK_VDU,
	PMU_IDLE_ACK_RGA,
	PMU_IDLE_ACK_IEP,
	PMU_IDLE_ACK_VOPB,

	PMU_IDLE_ACK_VOPL,
	PMU_IDLE_ACK_ISP0,
	PMU_IDLE_ACK_ISP1,
	PMU_IDLE_ACK_HDCP,

	PMU_IDLE_ACK_USB3,
	PMU_IDLE_ACK_PERILPM0,
	PMU_IDLE_ACK_CENTER,
	PMU_IDLE_ACK_CCIM0,

	PMU_IDLE_ACK_CCIM1,
	PMU_IDLE_ACK_VIO,
	PMU_IDLE_ACK_MSCH0,
	PMU_IDLE_ACK_MSCH1,

	PMU_IDLE_ACK_ALIVE,
	PMU_IDLE_ACK_PMU,
	PMU_IDLE_ACK_EDP,
	PMU_IDLE_ACK_GMAC,

	PMU_IDLE_ACK_EMMC,
	PMU_IDLE_ACK_CENTER1,
	PMU_IDLE_ACK_PMUM0,
	PMU_IDLE_ACK_GIC,

	PMU_IDLE_ACK_SD,
	PMU_IDLE_ACK_SDIOAUDIO,
};

enum pmu_cci500_con {
	PMU_PREQ_CCI500_CFG_SW = 0,
	PMU_CLR_PREQ_CCI500_HW,
	PMU_PSTATE_CCI500_0,
	PMU_PSTATE_CCI500_1,

	PMU_PSTATE_CCI500_2,
	PMU_QREQ_CCI500_CFG_SW,
	PMU_CLR_QREQ_CCI500_HW,
	PMU_QGATING_CCI500_CFG,

	PMU_PREQ_CCI500_CFG_SW_WMSK = 16,
	PMU_CLR_PREQ_CCI500_HW_WMSK,
	PMU_PSTATE_CCI500_0_WMSK,
	PMU_PSTATE_CCI500_1_WMSK,

	PMU_PSTATE_CCI500_2_WMSK,
	PMU_QREQ_CCI500_CFG_SW_WMSK,
	PMU_CLR_QREQ_CCI500_HW_WMSK,
	PMU_QGATING_CCI500_CFG_WMSK,
};

enum pmu_adb400_con {
	PMU_PWRDWN_REQ_CXCS_SW = 0,
	PMU_PWRDWN_REQ_CORE_L_SW,
	PMU_PWRDWN_REQ_CORE_L_2GIC_SW,
	PMU_PWRDWN_REQ_GIC2_CORE_L_SW,

	PMU_PWRDWN_REQ_CORE_B_SW,
	PMU_PWRDWN_REQ_CORE_B_2GIC_SW,
	PMU_PWRDWN_REQ_GIC2_CORE_B_SW,

	PMU_CLR_CXCS_HW = 8,
	PMU_CLR_CORE_L_HW,
	PMU_CLR_CORE_L_2GIC_HW,
	PMU_CLR_GIC2_CORE_L_HW,

	PMU_CLR_CORE_B_HW,
	PMU_CLR_CORE_B_2GIC_HW,
	PMU_CLR_GIC2_CORE_B_HW,

	PMU_PWRDWN_REQ_CXCS_SW_WMSK = 16,
	PMU_PWRDWN_REQ_CORE_L_SW_WMSK,
	PMU_PWRDWN_REQ_CORE_L_2GIC_SW_WMSK,
	PMU_PWRDWN_REQ_GIC2_CORE_L_SW_WMSK,

	PMU_PWRDWN_REQ_CORE_B_SW_WMSK,
	PMU_PWRDWN_REQ_CORE_B_2GIC_SW_WMSK,
	PMU_PWRDWN_REQ_GIC2_CORE_B_SW_WMSK,

	PMU_CLR_CXCS_HW_WMSK = 24,
	PMU_CLR_CORE_L_HW_WMSK,
	PMU_CLR_CORE_L_2GIC_HW_WMSK,
	PMU_CLR_GIC2_CORE_L_HW_WMSK,

	PMU_CLR_CORE_B_HW_WMSK,
	PMU_CLR_CORE_B_2GIC_HW_WMSK,
	PMU_CLR_GIC2_CORE_B_HW_WMSK,
};

enum pmu_adb400_st {
	PMU_PWRDWN_REQ_CXCS_SW_ST = 0,
	PMU_PWRDWN_REQ_CORE_L_SW_ST,
	PMU_PWRDWN_REQ_CORE_L_2GIC_SW_ST,
	PMU_PWRDWN_REQ_GIC2_CORE_L_SW_ST,

	PMU_PWRDWN_REQ_CORE_B_SW_ST,
	PMU_PWRDWN_REQ_CORE_B_2GIC_SW_ST,
	PMU_PWRDWN_REQ_GIC2_CORE_B_SW_ST,

	PMU_CLR_CXCS_HW_ST = 8,
	PMU_CLR_CORE_L_HW_ST,
	PMU_CLR_CORE_L_2GIC_HW_ST,
	PMU_CLR_GIC2_CORE_L_HW_ST,

	PMU_CLR_CORE_B_HW_ST,
	PMU_CLR_CORE_B_2GIC_HW_ST,
	PMU_CLR_GIC2_CORE_B_HW_ST,
};

enum pmu_pwrdn_con1 {
	PMU_VD_SCU_L_PWRDN_EN = 0,
	PMU_VD_SCU_B_PWRDN_EN,
	PMU_VD_CENTER_PWRDN_EN,
};

enum pmu_core_pwr_st {
	L2_FLUSHDONE_CLUSTER_L = 0,
	STANDBY_BY_WFIL2_CLUSTER_L,

	L2_FLUSHDONE_CLUSTER_B = 10,
	STANDBY_BY_WFIL2_CLUSTER_B,
};

#define PMU_WKUP_CFG0		0x00
#define PMU_WKUP_CFG1		0x04
#define PMU_WKUP_CFG2		0x08
#define PMU_WKUP_CFG3		0x0c
#define PMU_WKUP_CFG4		0x10
#define PMU_PWRDN_CON		0x14
#define PMU_PWRDN_ST		0x18
#define PMU_PLL_CON		0x1c
#define PMU_PWRMODE_CON		0x20
#define PMU_SFT_CON		0x24
#define PMU_INT_CON		0x28
#define PMU_INT_ST		0x2c
#define PMU_GPIO0_POS_INT_CON	0x30
#define PMU_GPIO0_NEG_INT_CON	0x34
#define PMU_GPIO1_POS_INT_CON	0x38
#define PMU_GPIO1_NEG_INT_CON	0x3c
#define PMU_GPIO0_POS_INT_ST	0x40
#define PMU_GPIO0_NEG_INT_ST	0x44
#define PMU_GPIO1_POS_INT_ST	0x48
#define PMU_GPIO1_NEG_INT_ST	0x4c
#define PMU_PWRDN_INTEN		0x50
#define PMU_PWRDN_STATUS	0x54
#define PMU_WAKEUP_STATUS	0x58
#define PMU_BUS_CLR		0x5c
#define PMU_BUS_IDLE_REQ	0x60
#define PMU_BUS_IDLE_ST		0x64
#define PMU_BUS_IDLE_ACK	0x68
#define PMU_CCI500_CON		0x6c
#define PMU_ADB400_CON		0x70
#define PMU_ADB400_ST		0x74
#define PMU_POWER_ST		0x78
#define PMU_CORE_PWR_ST		0x7c
#define PMU_OSC_CNT		0x80
#define PMU_PLLLOCK_CNT		0x84
#define PMU_PLLRST_CNT		0x88
#define PMU_STABLE_CNT		0x8c
#define PMU_DDRIO_PWRON_CNT	0x90
#define PMU_WAKEUP_RST_CLR_CNT	0x94
#define PMU_DDR_SREF_ST		0x98
#define PMU_SCU_L_PWRDN_CNT	0x9c
#define PMU_SCU_L_PWRUP_CNT	0xa0
#define PMU_SCU_B_PWRDN_CNT	0xa4
#define PMU_SCU_B_PWRUP_CNT	0xa8
#define PMU_GPU_PWRDN_CNT	0xac
#define PMU_GPU_PWRUP_CNT	0xb0
#define PMU_CENTER_PWRDN_CNT	0xb4
#define PMU_CENTER_PWRUP_CNT	0xb8
#define PMU_TIMEOUT_CNT		0xbc
#define PMU_CPU0APM_CON		0xc0
#define PMU_CPU1APM_CON		0xc4
#define PMU_CPU2APM_CON		0xc8
#define PMU_CPU3APM_CON		0xcc
#define PMU_CPU0BPM_CON		0xd0
#define PMU_CPU1BPM_CON		0xd4
#define PMU_NOC_AUTO_ENA	0xd8
#define PMU_PWRDN_CON1		0xdc

#define PMUGRF_GPIO0A_IOMUX	0x00
#define PMUGRF_GPIO1A_IOMUX	0x10
#define PMUGRF_GPIO1C_IOMUX	0x18

#define PMUGRF_GPIO0A6_IOMUX_SHIFT      12
#define PMUGRF_GPIO0A6_IOMUX_PWM        0x1
#define PMUGRF_GPIO1C3_IOMUX_SHIFT      6
#define PMUGRF_GPIO1C3_IOMUX_PWM        0x1

#define AP_PWROFF		0x0a

#define GPIO0A0_SMT_ENABLE	BITS_WITH_WMASK(1, 3, 0)
#define GPIO1A6_IOMUX		BITS_WITH_WMASK(0, 3, 12)

#define TSADC_INT_PIN		38
#define CORES_PM_DISABLE	0x0
#define CPU_AXI_QOS_ID_COREID		0x00
#define CPU_AXI_QOS_REVISIONID		0x04
#define CPU_AXI_QOS_PRIORITY		0x08
#define CPU_AXI_QOS_MODE		0x0c
#define CPU_AXI_QOS_BANDWIDTH		0x10
#define CPU_AXI_QOS_SATURATION		0x14
#define CPU_AXI_QOS_EXTCONTROL		0x18
#define CPU_AXI_QOS_NUM_REGS		0x07

#define CPU_AXI_CCI_M0_QOS_BASE		0xffa50000
#define CPU_AXI_CCI_M1_QOS_BASE		0xffad8000
#define CPU_AXI_DMAC0_QOS_BASE		0xffa64200
#define CPU_AXI_DMAC1_QOS_BASE		0xffa64280
#define CPU_AXI_DCF_QOS_BASE		0xffa64180
#define CPU_AXI_CRYPTO0_QOS_BASE	0xffa64100
#define CPU_AXI_CRYPTO1_QOS_BASE	0xffa64080
#define CPU_AXI_PMU_CM0_QOS_BASE	0xffa68000
#define CPU_AXI_PERI_CM1_QOS_BASE	0xffa64300
#define CPU_AXI_GIC_QOS_BASE		0xffa78000
#define CPU_AXI_SDIO_QOS_BASE		0xffa76000
#define CPU_AXI_SDMMC_QOS_BASE		0xffa74000
#define CPU_AXI_EMMC_QOS_BASE		0xffa58000
#define CPU_AXI_GMAC_QOS_BASE		0xffa5c000
#define CPU_AXI_USB_OTG0_QOS_BASE	0xffa70000
#define CPU_AXI_USB_OTG1_QOS_BASE	0xffa70080
#define CPU_AXI_USB_HOST0_QOS_BASE	0xffa60100
#define CPU_AXI_USB_HOST1_QOS_BASE	0xffa60180
#define CPU_AXI_GPU_QOS_BASE		0xffae0000
#define CPU_AXI_VIDEO_M0_QOS_BASE	0xffab8000
#define CPU_AXI_VIDEO_M1_R_QOS_BASE	0xffac0000
#define CPU_AXI_VIDEO_M1_W_QOS_BASE	0xffac0080
#define CPU_AXI_RGA_R_QOS_BASE		0xffab0000
#define CPU_AXI_RGA_W_QOS_BASE		0xffab0080
#define CPU_AXI_IEP_QOS_BASE		0xffa98000
#define CPU_AXI_VOP_BIG_R_QOS_BASE	0xffac8000
#define CPU_AXI_VOP_BIG_W_QOS_BASE	0xffac8080
#define CPU_AXI_VOP_LITTLE_QOS_BASE	0xffad0000
#define CPU_AXI_ISP0_M0_QOS_BASE	0xffaa0000
#define CPU_AXI_ISP0_M1_QOS_BASE	0xffaa0080
#define CPU_AXI_ISP1_M0_QOS_BASE	0xffaa8000
#define CPU_AXI_ISP1_M1_QOS_BASE	0xffaa8080
#define CPU_AXI_HDCP_QOS_BASE		0xffa90000
#define CPU_AXI_PERIHP_NSP_QOS_BASE	0xffad8080
#define CPU_AXI_PERILP_NSP_QOS_BASE	0xffad8180
#define CPU_AXI_PERILPSLV_NSP_QOS_BASE	0xffad8100

#define PD_CTR_LOOP		500
#define CHK_CPU_LOOP		500
#define MAX_WAIT_COUNT		1000

#define	GRF_SOC_CON4		0x0e210
#define GRF_GPIO4C_IOMUX	0x0e028

#define PMUGRF_GPIO0A_SMT	0x0120
#define PMUGRF_SOC_CON0		0x0180

#define CCI_FORCE_WAKEUP	WMSK_BIT(8)
#define EXTERNAL_32K		WMSK_BIT(0)

#define PLL_PD_HW		0xff
#define IOMUX_CLK_32K		0x00030002
#define NOC_AUTO_ENABLE		0x3fffffff

#define SAVE_QOS(array, NAME) \
	RK3399_CPU_AXI_SAVE_QOS(array, CPU_AXI_##NAME##_QOS_BASE)
#define RESTORE_QOS(array, NAME) \
	RK3399_CPU_AXI_RESTORE_QOS(array, CPU_AXI_##NAME##_QOS_BASE)

#define RK3399_CPU_AXI_SAVE_QOS(array, base) do { \
	array[0] = mmio_read_32(base + CPU_AXI_QOS_ID_COREID); \
	array[1] = mmio_read_32(base + CPU_AXI_QOS_REVISIONID); \
	array[2] = mmio_read_32(base + CPU_AXI_QOS_PRIORITY); \
	array[3] = mmio_read_32(base + CPU_AXI_QOS_MODE); \
	array[4] = mmio_read_32(base + CPU_AXI_QOS_BANDWIDTH); \
	array[5] = mmio_read_32(base + CPU_AXI_QOS_SATURATION); \
	array[6] = mmio_read_32(base + CPU_AXI_QOS_EXTCONTROL); \
} while (0)

#define RK3399_CPU_AXI_RESTORE_QOS(array, base) do { \
	mmio_write_32(base + CPU_AXI_QOS_ID_COREID, array[0]); \
	mmio_write_32(base + CPU_AXI_QOS_REVISIONID, array[1]); \
	mmio_write_32(base + CPU_AXI_QOS_PRIORITY, array[2]); \
	mmio_write_32(base + CPU_AXI_QOS_MODE, array[3]); \
	mmio_write_32(base + CPU_AXI_QOS_BANDWIDTH, array[4]); \
	mmio_write_32(base + CPU_AXI_QOS_SATURATION, array[5]); \
	mmio_write_32(base + CPU_AXI_QOS_EXTCONTROL, array[6]); \
} while (0)

struct pmu_slpdata_s {
	uint32_t cci_m0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t cci_m1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t dmac0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t dmac1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t dcf_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t crypto0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t crypto1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t pmu_cm0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t peri_cm1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t gic_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t sdmmc_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t gmac_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t emmc_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t usb_otg0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t usb_otg1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t usb_host0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t usb_host1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t gpu_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t video_m0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t video_m1_r_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t video_m1_w_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t rga_r_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t rga_w_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t vop_big_r[CPU_AXI_QOS_NUM_REGS];
	uint32_t vop_big_w[CPU_AXI_QOS_NUM_REGS];
	uint32_t vop_little[CPU_AXI_QOS_NUM_REGS];
	uint32_t iep_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t isp1_m0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t isp1_m1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t isp0_m0_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t isp0_m1_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t hdcp_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t perihp_nsp_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t perilp_nsp_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t perilpslv_nsp_qos[CPU_AXI_QOS_NUM_REGS];
	uint32_t sdio_qos[CPU_AXI_QOS_NUM_REGS];
};

extern uint32_t clst_warmboot_data[PLATFORM_CLUSTER_COUNT];
#endif /* __PMU_H__ */
