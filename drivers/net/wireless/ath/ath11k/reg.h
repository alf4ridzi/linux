/* SPDX-License-Identifier: BSD-3-Clause-Clear */
/*
 * Copyright (c) 2019 The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2025 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef ATH11K_REG_H
#define ATH11K_REG_H

#include <linux/kernel.h>
#include <net/regulatory.h>

struct ath11k_base;
struct ath11k;

/* DFS regdomains supported by Firmware */
enum ath11k_dfs_region {
	ATH11K_DFS_REG_UNSET,
	ATH11K_DFS_REG_FCC,
	ATH11K_DFS_REG_ETSI,
	ATH11K_DFS_REG_MKK,
	ATH11K_DFS_REG_CN,
	ATH11K_DFS_REG_KR,
	ATH11K_DFS_REG_MKK_N,
	ATH11K_DFS_REG_UNDEF,
};

/* Phy bitmaps */
#define ATH11K_REG_PHY_BITMAP_NO11AX	BIT(5)

/* ATH11K Regulatory API's */
void ath11k_reg_init(struct ath11k *ar);
void ath11k_reg_reset_info(struct cur_regulatory_info *reg_info);
void ath11k_reg_free(struct ath11k_base *ab);
void ath11k_regd_update_work(struct work_struct *work);
void ath11k_regd_update_chan_list_work(struct work_struct *work);
struct ieee80211_regdomain *
ath11k_reg_build_regd(struct ath11k_base *ab,
		      struct cur_regulatory_info *reg_info, bool intersect,
		      enum wmi_vdev_type vdev_type,
		      enum ieee80211_ap_reg_power power_type);
int ath11k_regd_update(struct ath11k *ar);
int ath11k_reg_update_chan_list(struct ath11k *ar, bool wait);
enum wmi_reg_6ghz_ap_type
ath11k_reg_ap_pwr_convert(enum ieee80211_ap_reg_power power_type);
int ath11k_reg_handle_chan_list(struct ath11k_base *ab,
				struct cur_regulatory_info *reg_info,
				enum ieee80211_ap_reg_power power_type);
int ath11k_reg_set_cc(struct ath11k *ar);
#endif
