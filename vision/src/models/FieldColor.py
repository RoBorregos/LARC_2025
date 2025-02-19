from dataclasses import dataclass

@dataclass
class FieldColor:
    """
    A class that represents a color of the field

    Attributes:
        color: The color of the field (rgb)
        color_range: The range of the color of the field (rgb) to be accepted (for each color)
        name: The name of the color of the field
    """
    color: tuple[int, int, int]
    color_range: tuple[tuple[int, int, int], tuple[int, int, int]]
    name: str

    def is_color_in_range(self, color: tuple[int, int, int]) -> bool:
        """
        Checks if the color is in the range of the color of the field

        Returns:
            True if the color is in the range of the color of the field, False otherwise
        """

        return (
            self.color_range[0][0] <= color[0] <= self.color_range[1][0] and
            self.color_range[0][1] <= color[1] <= self.color_range[1][1] and
            self.color_range[0][2] <= color[2] <= self.color_range[1][2]
        )
