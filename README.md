# Структура проекта

- `data/` - папка с данными, сейчас `src.01.png` используется во всех трёх упражнениях;
- `src/` - упражнения и оценка качества выполнения:
	+ `exerAA` - проект (упражнение) с номером АА;
	+ `quality_assessment` - модуль с функциями проверки качества (используется в каждом упражнении).
	
# Упражнения

В каждом модуле (упражнении) в функции `main`:
- загружается исходное изображение;
- формируется эталонное изображение (одно или несколько, в зависимости от задания) посредством 
вызова функции `ideal_solution`;
- вызывается функция `test_solution`, в которой предполагается загрузка изображения (одного или нескольких), 
сформированного алгоритмом студента. Так как таких данных нет, стоит заглушка - вызывается `ideal_solution`.
- идеальное изображение и изображение студента сравниваются в функции `measureQuality`.

Для оценки качества результата изображения, сформированного алгоритмом студента), `measureQuality` 
используется нормализованную (от 0 до 1) функцию MAE (mean absolute error):

$$
quality = \frac{1}{255} \cdot \frac{1}{width \cdot height} \Sigma_{x, y} |Ideal(x, y) - Result(x, y)|
$$

`measureQuality` выводит информацию о качестве выполнения задания (от 0 до 1, где 1 - полное совпаденияе 
с идеальным решением) в консоль и выводит изображения (идеальное и сформированное алгоритмом студента) на экран.

## 01 Изменение размеров изображения

Увеличить ширину картинки в 1.5 раза и уменьшить высоту на 30%.

Использовать `src.01.png`.

## 02 Перевод в оттенки серого

Перевести цветное изображение в оттенки серого, используя стандартный функционал OpenCV.

Использовать `src.01.png`.

## 02 Перевод в цветовые пространства

Перевести цветное изображение из пространства RGB в пространства HSV, HLS, Lab.

Использовать `src.01.png`.
