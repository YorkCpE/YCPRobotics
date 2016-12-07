import numpy as np
import cv2
import imutils
import gc
import rospy

colors = []
tracking = False
windowTitle = "OpenCV HSV Color Tool"
controls = """
#####################################################################
############################ Controls ###############################
#####################################################################

While not tracking, click to capture color to add to average.
Press 't' to toggle between tracking mode and color selection mode.
Press 'q' to exit.

#####################################################################
#####################################################################
#####################################################################
           """
lowerBound = None
upperBound = None


def onmouse(event, x, y, flags, frame):
    if event == cv2.EVENT_LBUTTONUP and not tracking:
        colors.append(frame[y, x].tolist())

if __name__ == "__main__":
    print controls
    camera = cv2.VideoCapture(0)
    while True:
        (grabbed, image) = camera.read()
        #image = cv2.imread("img.png")
        image = imutils.resize(image, width=600)

        hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
        if not tracking:
            if colors:
                cv2.putText(image, str(colors[-1]), (10, 50), cv2.FONT_HERSHEY_SCRIPT_SIMPLEX, 2, (0, 0, 0), 2)
        if tracking:
            if colors:
                avgH = int(sum(c[0] for c in colors) / len(colors))
                avgS = int(sum(c[0] for c in colors) / len(colors))
                avgV = int(sum(c[0] for c in colors) / len(colors))

                minH = min(c[0] for c in colors)
                minS = min(c[1] for c in colors)
                minV = min(c[2] for c in colors)
                maxH = max(c[0] for c in colors)
                maxS = max(c[1] for c in colors)
                maxV = max(c[2] for c in colors)

                lowerBound = np.array([minH, minS, minV], np.uint8)
                upperBound = np.array([maxH, maxS, maxV], np.uint8)
                print "Upper bound: ", upperBound, " HSV\nLower bound: ", lowerBound, " HSV"
                colors = []
                gc.collect()

            #hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

            mask = cv2.inRange(hsv, lowerBound, upperBound)
            mask = cv2.erode(mask, None, iterations=2)   # make the selection closer to a
            mask = cv2.dilate(mask, None, iterations=2)  # regular polygon, if possible

            # find contours in the masked image and keep the largest one
            cnts = None
            (cnts, _) = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            if cv2.__version__ == "3.1.0":
                (_, cnts, _) = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            if cnts:
                c = max(cnts, key=cv2.contourArea)

                # approximate the contour
                peri = cv2.arcLength(c, True)
                approx = cv2.approxPolyDP(c, 0.05 * peri, True)

                # draw a green bounding box surrounding the red game
                # cv2.drawContours(image, [approx], -1, (0, 255, 0), 4)

                M = cv2.moments(c)
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"])

                # draw the contour and center of the shape on the image
                cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
                cv2.circle(image, (cX, cY), 7, (255, 255, 255), -1)
                cv2.putText(image, "center", (cX - 20, cY - 20), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
        gc.collect()
        cv2.imshow(windowTitle, image)
        cv2.setMouseCallback(windowTitle, onmouse, hsv)
        key = cv2.waitKey(1) & 0xFF

        # if the 'q' key is pressed, stop the loop
        if key == ord("q"):
            break
        if key == ord("t"):
            tracking = not tracking

camera.release()
cv2.destroyAllWindows()
cv2.waitKey(1)

