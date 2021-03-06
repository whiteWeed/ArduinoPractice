import cv2
import numpy as np
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.setup

cap = cv2.VideoCapture(-1)
if cap.isOpened():
    while True:
        ret, frame = cap.read()
        # blurring the frame that's captured
        frame_gau_blur = cv2.GaussianBlur(frame, (3, 3), 0)
        # converting BGR to HSV
        hsv = cv2.cvtColor(frame_gau_blur, cv2.COLOR_BGR2HSV)
        # the range of blue color in HSV
        lower_blue = np.array([170, 80, 80])
        higher_blue = np.array([190, 255, 255])
        # getting the range of blue color in frame
        blue_range = cv2.inRange(hsv, lower_blue, higher_blue)
        res_blue = cv2.bitwise_and(frame_gau_blur,frame_gau_blur, mask=blue_range)
        blue_s_gray = cv2.cvtColor(res_blue, cv2.COLOR_BGR2GRAY)
        canny_edge = cv2.Canny(blue_s_gray, 50, 240)
        # applying HoughCircles
        circles = cv2.HoughCircles(canny_edge, cv2.HOUGH_GRADIENT, dp=1, minDist=50, param1=10, param2=20, minRadius=30, maxRadius=50)
        cir_cen = []
        if circles is not None:
            GPIO.output(17, True)
            # circles = np.uint16(np.around(circles))
            for i in circles[0, :]:
                # drawing on detected circle and its center
                cv2.circle(frame,(i[0],i[1]),i[2],(0,255,0),2)
                cv2.circle(frame,(i[0],i[1]),2,(0,0,255),3)
                cir_cen.append((i[0],i[1]))
        else:
            GPIO.output(17, False)
        print(cir_cen)
        cv2.imshow('circles', frame)
        cv2.imshow('gray', blue_s_gray)
        cv2.imshow('canny', canny_edge)
        time.sleep(0.2)
        k = cv2.waitKey(5) & 0xFF
        if k == 27:
            break
    cv2.destroyAllWindows()
else:
    print('no cam')
