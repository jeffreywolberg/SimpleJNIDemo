export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
export MY_JNI_HEADERS=${OUT_DIR}/jniHeaders
export PROJECT_PACKAGE=${PWD}/java/com/jni/example
export CPP_FOLDER=${PWD}/cpp

export OUT_DIR=${PWD}/out

temperaturesampler:
	mkdir -p ${OUT_DIR} ${MY_JNI_HEADERS}
	javac -h ${MY_JNI_HEADERS} -d ${OUT_DIR} ${PROJECT_PACKAGE}/TemperatureSampler.java ${PROJECT_PACKAGE}/TemperatureData.java ${PROJECT_PACKAGE}/TemperatureScale.java
	g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -I${MY_JNI_HEADERS} ${CPP_FOLDER}/TemperatureSampler.cpp -o ${OUT_DIR}/temperatureSampler.o
	g++ -shared -fPIC -o ${OUT_DIR}/libtemperaturesampler.so ${OUT_DIR}/temperatureSampler.o -lc

run_temperaturesampler: temperaturesampler
	java -cp ${OUT_DIR} -Djava.library.path=${OUT_DIR} com.jni.example.TemperatureSampler

clean:
	rm -rf ${OUT_DIR} ${MY_JNI_HEADERS}
