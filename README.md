# UniqueEngine
Бесплатный игровой движок с открытым исходным кодом на базе технологий Qt и SFML.

# Требования для компиляции
- Среда программирования Qt Creator 5.14.2.

# Требуемые знания программиста
- Языки программирования: C++, JavaScript;
- Технологии: Qt, Xml;
- ООП на высоком уровне.

# Описание
Игровой движок состоит из следующих базовых компонентов:
_ Уровень
__ Нормальный слой
___ Чанки
____ Элемент карты
__ Объектный слой
___ Нормальный объект

## Уровень
Набор слоёв, загрузка которых осуществляется из внешнего файла.

## Нормальный слой
Слой, который хранит только элементы карты, для которых не нужна обработка.

## Чанки
Набор графических элементов по x:y, используются ради оптимизации (Проверяется пересечение чанков с областью экрана игрока, они намного больше, чем один элемент карты).

## Элемент карты
Спрайт, без обработки и сложной внутренней структуры классов.

## Объектный слой
Слой, который хранит только нормальные объекты.

## Нормальный объект
Спрайт, с сложной внутренней структуры классов, есть возможность обработки через JavaScript.

# Установка
- git clone https://github.com/Xummuk97/UniqueEngine.git
