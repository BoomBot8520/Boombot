#!/usr/bin/env python3
# Remember to change the coordinates recieved by the planner from (X, Y) to (X + 1.79, Y + 0.66).
# you need to name this node "controller"

import rospy
from  nav_msgs.msg import Odometry
from geometry_msgs.msg import Twist, Pose, Point, Quaternion
import math
import matplotlib.pyplot as plt
from tf.transformations import euler_from_quaternion

yaw = 0.0

class controller:
    def __init__(self, kp, ki, kd):
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.integral = 0
        self.past_error = 0
    def get_action(self, goal, start):
        error = distance((pose.x, pose.y), goal, start)
        self.integral += error
        differential = error - self.past_error
        self.past_error = error
        return self.kp*error + self.ki*self.integral + self.kd*differential
    def get_action_angle(self, goal):
        error = goal - pose_angle
        self.integral += error
        differential = error -self.past_error
        self.past_error = error
        return self.kp*error + self.ki*self.integral + self.kd*differential

def slope_angle(point1, point2):
    ang = math.atan2(point2[1]-point1[1], point2[0]-point1[0]) 
    return ang

def dist(point1: tuple, point2: tuple):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)

def distance(current_pos, goal, start):
    return dist(start, goal) - dist(start, current_pos) 

def callback_path(nodes: Point):

    pid_dist = controller(kp = 1, ki = 0.0, kd = 0.0001)
    pid_angle = controller(kp = 1.5, ki = 0.0, kd = 0.0002)

    global pose
    start_pose = pose.x, pose.y
    goal = nodes.x + 1.79, nodes.y + 0.66
    if (pose.x, pose.y) == goal:
        return
    else :
        slope = slope_angle((pose.x, pose.y), goal)
        tolerance_ang = 0.0085
        tolerance_lin = 0.004
        cmd = Twist()
        cmd.linear.x = 0
        cmd.linear.y = 0
        cmd.linear.z = 0
        cmd.angular.x = 0
        cmd.angular.y = 0
        cmd.angular.z = 0
        while not abs(slope - pose_angle) < tolerance_ang :
            action = pid_angle.get_action_angle(slope)
            cmd.angular.z = action
            pub.publish(cmd)
        cmd.angular.z = 0
        pub.publish(cmd)

        while not abs(distance((pose.x, pose.y), goal, start_pose)) < tolerance_lin:
            action = pid_dist.get_action(goal, start_pose)
            cmd.linear.x = action
            pub.publish(cmd)
        cmd.linear.x = 0
        pub.publish(cmd)

def callback_odom(msg: Odometry):
    global pose
    pose = msg.pose.pose.position
    global pose_angle
    ang = msg.pose.pose.orientation
    pose_angle = euler_from_quaternion([ang.x,ang.y,ang.z,ang.w])[2]

if __name__ == '__main__':
    global pose
    global pose_angle
    pose = Point()
    pose_angle = 0.0
    rospy.init_node("tb3_controller")
    pub = rospy.Publisher("/cmd_vel", Twist, queue_size=10)
    sub_odo = rospy.Subscriber("/odom", Odometry, callback_odom)
    sub_path = rospy.Subscriber("/planned_path", Point, callback_path)
    rospy.spin()