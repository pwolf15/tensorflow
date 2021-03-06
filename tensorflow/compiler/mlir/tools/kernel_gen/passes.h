/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_COMPILER_MLIR_TOOLS_KERNEL_GEN_PASSES_H_
#define TENSORFLOW_COMPILER_MLIR_TOOLS_KERNEL_GEN_PASSES_H_

#include <memory>

#include "mlir/Dialect/GPU/GPUDialect.h"  // from @llvm-project
#include "mlir/Dialect/LLVMIR/LLVMDialect.h"  // from @llvm-project
#include "mlir/Pass/Pass.h"  // from @llvm-project

namespace mlir {
namespace kernel_gen {

std::unique_ptr<mlir::FunctionPass> createMaterializeBroadcastsPass();

std::unique_ptr<mlir::FunctionPass> createUnfuseBatchNormPass();

std::unique_ptr<mlir::OperationPass<mlir::LLVM::LLVMFuncOp>>
createPropagateTensorFlowABIKnowledgePass(mlir::FunctionType type,
                                          llvm::ArrayRef<uint32_t> same_shape);

std::unique_ptr<mlir::OperationPass<mlir::gpu::GPUModuleOp>>
createGpuKernelToBlobPass(
    mlir::StringRef blob_annotation,
    const std::pair<int32_t, int32_t>& compute_capability);

}  // namespace kernel_gen
}  // namespace mlir

#endif  // TENSORFLOW_COMPILER_MLIR_TOOLS_KERNEL_GEN_PASSES_H_
