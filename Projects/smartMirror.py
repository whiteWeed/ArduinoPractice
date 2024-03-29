#!/usr/bin/python3

import Adafruit_DHT
import time
import threading
import RPi.GPIO as GPIO
from picamera2 import Picamera2, Preview


GPIO.setmode(GPIO.BCM)  # GPIO setting

sensor = Adafruit_DHT.DHT11 # DHT setting
cam = Picamera2()     # camera 선언

MOTpin = 27     # Fan Motor Pin 설정
PIRpin = 7      # 인체감지 센서 핀 설정
DHTpin = 17     # 온습도 핀 설정

GPIO.setup(MOTpin, GPIO.OUT)    # 팬 모터 핀 출력으로 설정
GPIO.setup(PIRpin, GPIO.IN)     # 인체감지 센서 핀 입력으로 설정
GPIO.setup(DHTpin, GPIO.IN)     # 온습도 센서 핀 입력으로 설정

humidity, temperature = Adafruit_DHT.read_retry(sensor, DHTpin) # 온습도 정보 받아오기


if humidity is not None and temperature is not None:    # 온습도 정보 있는지 확인
    print('success')
else:   #온습도 정보 있으면
    print('Failed to get reading. Try again.')  #온습도 다시 확인하라는 안내


def temp():  # 온도 정보 받아오는 함수
    global DHTpin   # DHTpin 변수를 global 변수로 지정
    humidity, temperature = Adafruit_DHT.read_retry(sensor, DHTpin)  # global변수로 지정 및 정보 받아오기

    if humidity is not None and temperature is not None:    # 정보 있으면
        return temperature  # 온도 정보 반환
    else:   # 없으면
        print('Failed to get reading. Try again.')  # 다시 확인해 보세요
        return False    # 거짓 반환


try:    # 무한루프이기 때문에 인터럽트 설정
    cam_preview = cam.create_preview_configuration(main={"size": (1024, 600)})
    cam.configure(cam_preview)
    cam.start_preview(Preview.QTGL)
    cam.start()
    time.sleep(5);      # 카메라 준비를 위한 대기
    crtTime = time.time()    # 업타임 계산용 변수 지정
    while True: # 무한루프
        tempNow = temp()    # tempNow 변수에 온도값 저장
        if tempNow > 60:    # 60도 이상이면
            GPIO.output(MOTpin, True)   # 모터 켜기
        else:               # 60도 미만이면
            GPIO.output(MOTpin, False)  # 모터 끄기

        if GPIO.input(PIRpin):  # 인체감지 센서 인식 시
            if crtTime + 30 < time.time():    # 마지막 인식으로부터 30초 이상 지났다면
                t = time.localtime()    # 일시 데이터 저장
                print("{0}:{1}:{2} motion detected!".format(t.tm_hour, t.tm_min, t.tm_sec))  # 모션 감지되었다는 안내.
                cam.capture_file("/home/pi/capture/{0}-{1}-{2}-{3}:{4}:{5}.jpg".format(t.tm_year, t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec))  # 모션 감지 시 사진 저장
                crtTime = time.time()    # 마지막 센서 감지시간 저장

except KeyboardInterrupt:   # 키보드 입력시
    print("quit")   # 나가기
    cam.stop_preview()  # 카메라 정지
    GPIO.cleanup()  # GPIO 날리기
