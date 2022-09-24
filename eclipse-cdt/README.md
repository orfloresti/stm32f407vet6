## Documentation
[ESP8266](https://docs.espressif.com/projects/esp8266-rtos-sdk/en/latest/get-started/index.html)

## Create config
`make menuconfig`

## Build project
`make`

## Flash project  
`make flash`

## Monitor
`make monitor`

boud rate for monitor 74880


## Notes
Before compiling validate minimum files path
```
${PWD} .
│   CMakeLists.txt
│   Makefile
│   README.md
│
└───main
        CMakeLists.txt
        component.mk
        hello_world_main.c

```
