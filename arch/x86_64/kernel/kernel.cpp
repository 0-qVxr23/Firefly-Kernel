#include "x86_64/kernel.hpp"

#include <stl/array.h>
#include <stl/cstdlib/stdio.h>

#include "x86_64/drivers/ps2.hpp"
#include "x86_64/drivers/serial.hpp"
#include "x86_64/drivers/vbe.hpp"
#include "x86_64/init/init.hpp"
#include "x86_64/logger.hpp"
#include "x86_64/memory-manager/primary/primary_phys.hpp"
#include "x86_64/memory-manager/virtual/virtual.hpp"
#include "x86_64/trace/strace.hpp"


[[maybe_unused]] constexpr short MAJOR_VERSION = 0;
[[maybe_unused]] constexpr short MINOR_VERSION = 0;
constexpr const char *VERSION_STRING = "0.0";

namespace firefly::kernel {
void log_core_firefly_contributors() {
    info_logger << "FireflyOS\nVersion: " << VERSION_STRING << "\nContributors:";

    firefly::std::array<const char *, 3> arr = {
        "Lime\t  ", "JohnkaS", "V01D-NULL"
    };

    for (size_t i = 0; i < arr.max_size(); i++) {
        if (i % 2 == 0) {
            info_logger << info_logger.newline() << info_logger.tab();
        }
        info_logger << " " << arr[i];
    }
    info_logger << info_logger.newline();
}

[[noreturn]] void kernel_main() {
    mm::VirtualMemoryManager vmm{ true };

    trace::panic("Reached the end of the kernel");
    __builtin_unreachable();
}
}  // namespace firefly::kernel