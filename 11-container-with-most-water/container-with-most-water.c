int maxArea(int* height, int heightSize) {
    int p1 = 0, p2 = heightSize - 1;
    int max_area = 0;

    while (p1 < p2) {
        int h = (height[p1] < height[p2]) ? height[p1] : height[p2];
        int width = p2 - p1;
        int curr_area = h * width;

        if (curr_area > max_area) {
            max_area = curr_area;
        }

        if (height[p1] < height[p2]) {
            p1++;
        } else {
            p2--;
        }
    }

    return max_area;
}
