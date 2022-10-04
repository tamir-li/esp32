set(src "w25qxx.c")
set(inc "include")

idf_component_register(SRCS ${src}
                    INCLUDE_DIRS ${inc}
	    REQUIRES spi2bus spi2ioctl)