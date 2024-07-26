cc_library(
    name = "filing",
    srcs = glob(["filing/src/**/*.cpp"]),
    hdrs = glob(["filing/include/**/*.h"]),
    includes = ["filing/include"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "vet_clinic",
    srcs = ["vet_clinic.cpp"],
    deps = [":filing"],
)