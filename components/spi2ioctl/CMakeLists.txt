set(src "spi2ioctl.c")
set(inc "include")


idf_component_register(SRCS ${src}
                    INCLUDE_DIRS ${inc})
