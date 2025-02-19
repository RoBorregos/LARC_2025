import cv2
import numpy as np

def detect_color(detection_size:int, frame:np.ndarray, debug:bool = True):
    """
    Detects the average color of the detection_size * detection_size square in the center of the frame

    Returns the average color of the square in RGB format
    """
    center = (frame.shape[1] // 2, frame.shape[0] // 2)
    rect = cv2.rectangle(frame, (center[0] - detection_size // 2, center[1] - detection_size // 2), (center[0] + detection_size // 2, center[1] + detection_size // 2), (0, 0, 255), 2)

    square = frame[center[1] - detection_size // 2:center[1] + detection_size // 2, center[0] - detection_size // 2:center[0] + detection_size // 2]

    average_color = np.mean(square, axis=(0, 1)).astype(np.uint8)

    color_frame = np.zeros((detection_size, detection_size, 3), dtype=np.uint8)   
    color_frame[:] = average_color

    if debug:
        cv2.imshow('square', color_frame)
        cv2.imshow('rect', rect)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            return average_color
    return average_color
