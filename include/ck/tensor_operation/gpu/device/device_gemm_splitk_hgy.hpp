// SPDX-License-Identifier: MIT
// Copyright (c) 2018-2023, Advanced Micro Devices, Inc. All rights reserved.

#pragma once

#include <iostream>
#include <vector>

#include "device_base.hpp"

namespace ck {
namespace tensor_operation {
namespace device {

template <typename ALayout,
          typename BLayout,
          typename CLayout,
          typename ADataType,
          typename BDataType,
          typename CDataType,
          typename AElementwiseOperation,
          typename BElementwiseOperation,
          typename CElementwiseOperation,
          typename MacAElementwiseOperation,
          typename MacBElementwiseOperation>
struct DeviceGemmSplitKHgy : public BaseOperator
{
    virtual std::unique_ptr<BaseArgument> MakeArgumentPointer(const void* p_a,
                                                              const void* p_b,
                                                              void* p_c,
                                                              ck::index_t M,
                                                              ck::index_t N,
                                                              ck::index_t K,
                                                              ck::index_t StrideA,
                                                              ck::index_t StrideB,
                                                              ck::index_t StrideC,
                                                              AElementwiseOperation a_element_op,
                                                              BElementwiseOperation b_element_op,
                                                              CElementwiseOperation c_element_op,
                                                              ck::index_t KBatch,
                                                              MacAElementwiseOperation mac_a_element_op,
                                                              MacBElementwiseOperation mac_b_element_op) = 0;

    virtual std::unique_ptr<BaseInvoker> MakeInvokerPointer() = 0;
};

template <typename ALayout,
          typename BLayout,
          typename CLayout,
          typename ADataType,
          typename BDataType,
          typename CDataType,
          typename AElementwiseOperation,
          typename BElementwiseOperation,
          typename CElementwiseOperation,
          typename MacAElementwiseOperation,
          typename MacBElementwiseOperation>
using DeviceGemmSplitKPtrHgy = std::unique_ptr<DeviceGemmSplitKHgy<ALayout,
                                                             BLayout,
                                                             CLayout,
                                                             ADataType,
                                                             BDataType,
                                                             CDataType,
                                                             AElementwiseOperation,
                                                             BElementwiseOperation,
                                                             CElementwiseOperation,
                                                             MacAElementwiseOperation,
                                                             MacBElementwiseOperation>>;

} // namespace device
} // namespace tensor_operation
} // namespace ck
