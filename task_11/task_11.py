import cv2
import numpy as np

# Загрузка картинки
image = cv2.imread("input.jpg")

# Блюр картинки для удаления лишнего шума
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)

# Переводим картинку из формата BGR в формат HSV
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

# Задаем границы зеленого цвета в формате HSV
# Нижняя граница зеленого
hsv_min = np.array((36, 25, 25), np.uint8)
# Верхняя граница зеленого
hsv_max = np.array((70, 255, 255), np.uint8)

# Создание маски
green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)

# Поиск контуров на маске
contours, hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

# Сортировка контуров по их площади по убыванию
sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)

# Проверяем наличие зелёных фигур
if len(sorted_contours) > 0:
    largest_contour = sorted_contours[0]

    # Находим прямоугольник, который полностью описывает наш контур
    # x, y - координаты левого верхнего угла прямоугольника
    # w, h - его ширина и высота
    x, y, w, h = cv2.boundingRect(largest_contour)

    # Находим центр прямоугольника
    center_x = int(x + w / 2)
    center_y = int(y + h / 2)

    # Рисуем красную точку
    cv2.circle(image, (center_x, center_y), 10, (0, 0, 255), -1)

# Выводим итоговую картинку на экран
cv2.imshow("Result", image)

# Ожидание ввода любой клавиши
cv2.waitKey(0)
# Закрытие всех окон
cv2.destroyAllWindows()