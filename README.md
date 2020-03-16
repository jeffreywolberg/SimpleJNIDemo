# SimpleJNIDemo
A simple application to demonstrate how JNI is used to communicate between C/CPP and Java.

Change JAVA_HOME variable inside Makefile based on your JDK directory before building.

## Dependencies
Youn will need Java and g++ in order to build the project.
```bash
sudo apt-get install default-jdk build-essentials
```

## Build the sample application:
```bash
make temperaturesampler
```
  

## Build and run afterwards:
```bash
make run_temperaturesampler
```
