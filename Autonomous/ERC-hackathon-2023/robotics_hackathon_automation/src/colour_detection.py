#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2 as cv
import numpy as np
from std_msgs.msg import String
def image_callback(msg):
    bridge = CvBridge()
    cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")  
    hsv_frame = cv.cvtColor(cv_image, cv.COLOR_BGR2HSV)
    lower_red1 = np.array([159, 50, 70])
    upper_red1 = np.array([180, 255, 255])
    lower_red2 = np.array([0, 50, 70])
    upper_red2 = np.array([9, 255, 255])
    mask_red1 = cv.inRange(hsv_frame, lower_red1, upper_red1)
    contours_red1, _ = cv.findContours(mask_red1, cv.RETR_EXTERNAL,cv.CHAIN_APPROX_SIMPLE)
    mask_red2 = cv.inRange(hsv_frame, lower_red2, upper_red2)
    contours_red2, _ = cv.findContours(mask_red2, cv.RETR_EXTERNAL,cv.CHAIN_APPROX_SIMPLE)
    lower_blue = np.array([36, 50, 70])
    upper_blue = np.array([128, 255, 255])
    mask_blue = cv.inRange(hsv_frame, lower_blue, upper_blue)
    contours_blue, _ = cv.findContours(mask_blue, cv.RETR_EXTERNAL,cv.CHAIN_APPROX_SIMPLE)
    if len(contours_red1) > 0 or len(contours_red2) > 0:
        pub.publish("Zinc extraction ongoing")
    elif len(contours_blue) > 0:
        pub.publish("Iron extraction ongoing")
    # cv.imshow('Live_Feed', cv_image)
    # cv.waitKey(1)
def main():
    global pub
    rospy.init_node('color_detector')
    pub = rospy.Publisher('task_status', String, queue_size=100)
    sub = rospy.Subscriber('/camera/rgb/image_raw', Image, image_callback)
    rospy.spin()
if __name__ == '__main__':
    main()
