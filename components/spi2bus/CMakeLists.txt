set(src "spi2bus.c")
set(inc "include")

idf_component_register(SRCS ${src}
                    INCLUDE_DIRS ${inc})
