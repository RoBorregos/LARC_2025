from algorithms.color_detect import detect_color
from models.FieldColor import FieldColor
from algorithms.calibration import color_calibration
import numpy as np
import cv2

field_color = None
while True: 
    cap = cv2.VideoCapture(0)
    ret, frame = cap.read()

    cv2.imshow("Frame", frame)

    if not ret:
        break

    # Check for key press to set and calibrate field color
    if cv2.waitKey(1) & 0xFF != 255:  # If a key is pressed
        field_color = color_calibration("white", frame, ((10, 10, 10), (10, 10, 10)))
    
        calibration_color = np.zeros((100, 100, 3), dtype=np.uint8)
        calibration_color[:] = field_color.color
        cv2.imshow("Calibration Color", calibration_color)

    # Move color detection logic here to continuously check after calibration
    detected_color = detect_color(100, frame, debug=False)
    if field_color is not None:
        if field_color.is_color_in_range(detected_color):
            print("Color is in range")
        else:
            print("Color is not in range")

    cv2.waitKey(1)

cap.release()
cv2.destroyAllWindows()