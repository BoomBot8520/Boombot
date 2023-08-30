#!/usr/bin/env python3
import obstacle_detection as obsdet
import random
import matplotlib.pyplot as plt
from shapely.geometry import Point
from shapely.ops import nearest_points
import rospy
import math
from geometry_msgs.msg import Point as ROSPoint
class Node:
    def __init__(self, x, y, parent = None):
        self.x = x
        self.y = y
        self.parent = parent
def rrt(start, goal, max_iterations=15000, step_size=0.4, circle_radius = 0.25):
    nodes = [Node(start[0], start[1])]
    for _ in range(max_iterations):
        if random.random() < 0.26:
            rnd = goal
        else:
            rnd = (random.uniform(-5.0, 5.0), random.uniform(-2.75, 3.5))
        nearest_node = min(nodes, key=lambda node: distance(node, rnd))
        new_node = step_from_to(nearest_node, rnd, step_size)
        if obsdet.isValidPoint(nearest_node.x, nearest_node.y, new_node.x, new_node.y):
            new_node.parent = nearest_node
            nodes.append(new_node)
            if distance(new_node, goal) <= step_size:
                global near_goal
                theta = math.atan2(goal[1] - new_node.y, goal[0] - new_node.x)
                circle_point = (goal[0] - circle_radius * math.cos(theta), goal[1] - circle_radius * math.sin(theta))
                near_goal = circle_point
                nodes.append(Node(circle_point[0], circle_point[1], parent=new_node))
                return nodes
    return None
def distance(node1, node2):
    return ((node1.x - node2[0]) ** 2 + (node1.y - node2[1]) ** 2) ** 0.5
def step_from_to(node1, node2, step_size):
    dist = distance(node1, node2)
    if dist < step_size:
        return Node(node2[0], node2[1])
    else:
        theta = math.atan2(node2[1] - node1.y, node2[0] - node1.x)
        return Node(node1.x + step_size * math.cos(theta), node1.y + step_size * math.sin(theta))
def generate_path(nodes):
    path = []
    last_node = nodes[-1]
    while last_node:
        path.append((last_node.x, last_node.y))
        last_node = last_node.parent
    return path[::-1]
def dist(point1, point2):
    return math.sqrt((point1[0] - point2[0])**2 + (point1[1] - point2[1])**2)
def sort_goals_by_distance(start_point, goals):
    sorted_goals = sorted(goals, key=lambda goal: dist(start_point, goal))
    return sorted_goals
def main():
    rospy.init_node("path_planner")
    pub = rospy.Publisher("planned_path", ROSPoint, queue_size=50)
    global near_goal
    start = (-5.06, -3.12)
    near_goal = start
    goals = [(5.18, -2.19), (1.58, -2.26), (-2.28, 1.86), (0.57, 0.33), (-3.61, -2.20)]
    planned_paths = []
    for goal in sort_goals_by_distance(start, goals):
        path = rrt(start, goal)
        start = near_goal
        if path:
            planned_paths.append(generate_path(path))
    # for wall in obsdet.maze:
    #     x, y = wall.polygon.exterior.xy
    #     plt.plot(x, y)
    # for path in planned_paths:
    #     x,y = zip(*path)
    #     plt.plot(x, y)
    # plt.show()
    for path in planned_paths:
        for nodes in path:
            if(nodes == path[0]):
                continue
            next = ROSPoint()
            next.x = nodes[0]
            next.y = nodes[1]
            next.z = 0
            pub.publish(next)
            rospy.sleep(9)
if __name__ == "__main__":
    main()