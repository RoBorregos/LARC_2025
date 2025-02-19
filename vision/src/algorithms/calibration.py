import numpy as np
from models.FieldColor import FieldColor
from algorithms.color_detect import detect_color

def color_calibration(name: str, frame: np.ndarray, range: tuple[tuple[int, int, int], tuple[int, int, int]] = ((0, 0, 0), (255, 255, 255))) -> FieldColor:
    """
    Calibrates the color of the field

    Args:
        frame: The frame to calibrate the color of the field
        range: The range of the color of the field to be accepted (for each color)
    Returns:
        The color of the field
    """

    color = detect_color(frame, range)

    range = (
        (max(0, color[0] - range[0][0]), max(0, color[1] - range[0][1]), max(0, color[2] - range[0][2])),
        (min(255, color[0] + range[1][0]), min(255, color[1] + range[1][1]), min(255, color[2] + range[1][2]))
    )

    return FieldColor(color=color, color_range=range, name=name)