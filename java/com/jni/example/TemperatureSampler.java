package com.jni.example;

public class TemperatureSampler {

    static {
        System.loadLibrary("temperaturesampler");
    }

    public static void main(String[] args) {
        TemperatureSampler temperatureSampler = new TemperatureSampler();
        System.out.println("Sampled Temperature = " + temperatureSampler.getTemperature());

        TemperatureData temperatureData = temperatureSampler.getDetailedTemperature();
        if (temperatureData != null) {
            System.out.println(temperatureData);
        }
    }

    private native float getTemperature();
    private native TemperatureData getDetailedTemperature();
}
