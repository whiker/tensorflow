#include "tensorflow/core/framework/allocator.h"
#include "tensorflow/core/platform/port.h"

namespace tensorflow {

Allocator::~Allocator() {}

class CPUAllocator : public Allocator {
 public:
  ~CPUAllocator() override {}

  string Name() override { return "cpu"; }
  void* AllocateRaw(size_t alignment, size_t num_bytes) override {
	// aligned_malloc() 声明于core/platform/port.h
	// 定义于core/platform/posix/port.cc
    return port::aligned_malloc(num_bytes, alignment);
  }

  void DeallocateRaw(void* ptr) override { port::aligned_free(ptr); }
};

Allocator* cpu_allocator() {
  // 单例类 CPUAllocator 定义在上面
  static CPUAllocator* cpu_alloc = new CPUAllocator;
  return cpu_alloc;
}

}  // namespace tensorflow
