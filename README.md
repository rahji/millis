# millis library for Microchip/Atmel AVR microcontrollers

This is a simple library to provide millis()-like capability without using the Arduino framework. 

## Installing

I use this module with PlatformIO. Here are a few different ways you can add it to your project:

1. Download the zip file, rename the unzipped folder to `millis` and place it in the `lib` folder of your project
2. Add it as a git submodule by typing the following command while in the `lib` folder: `git submodule add https://github.com/rahji/millis.git`
3. Add it to your `platformio.ini` file as a dependency, as shown below (I think).

```ini
lib_deps = https://github.com/rahji/millis.git#v1.0.0
```

You'll want to make sure that the `framework = arduino` line is removed from `platformio.ini`

## Usage

`millis_init()` will need to be called near the top of your main program. After that, you can call `millis_get()` to get the number of milliseconds that have passed.

## Some Notes

This isn't really a proper library with features, etc. It basically just sets up the timer registers and supplies a `millis()`-like function. Unless you're using Timer 0, you'll need to tweak the `millis_init()` function.

Also, I have defined the `millis_t` type to be `unsigned int`, but you probably want it to be `unsigned long`.
