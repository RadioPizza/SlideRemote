# Пульт для презентаций на ESP8266

* [Описание проекта](#chapter-0)
* [Папки проекта](#chapter-1)
* [Схемы подключения](#chapter-2)
* [Материалы и компоненты](#chapter-3)
* [Как скачать и прошить](#chapter-4)

<a id="chapter-0"></a>
## Описание проекта
Представляем вашему вниманию пульт для выступлений с презентациями на основе ESP8266! Проект предствляет собой замену дорогих импортных аналогов. Его главные преимущества - цена и кастомизация. Вы можете создать для него индвидуальный корпус и добавить функции, нужные именно вам.

### Железо
- Проект собран на базе пары микроконтроллеров ESP8266.
- Для реализации USB HID используется микроконтроллер Attiny85 за неимением у ESP8266 аппаратного USB (можно попробовать отказаться от AVR костыля, используя V-USB, проект открыт для ваших PR.

### Фишки
- Пара кнопок для навигации по слайдам: "впёрёд" и "назад"
- Встроенная лазерная указка
- Автономное питание от литиевого аккумулятора и встроенная зарядка для него - батарейки не понадобятся
- Быстрое соединение благодаря ESP-NOW - ничего устанавливать на компьютер и настраивать не нужно

<a id="chapter-1"></a>
## Папки
- **libraries** - библиотеки проекта
- **firmware** - прошивки для микроконтроллеров
- **schemes** - схемы подключения компонентов

<a id="chapter-2"></a>
## Схемы
- В разработке

<a id="chapter-3"></a>
## Материалы и компоненты
| Наименование          | Цена  | Кол-во | Стоимость | Ссылка                                                                                                                                                                                                                                                        | Комментарий                                                      |
|-----------------------|-------|--------|-----------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------|
| Wemos D1 Mini         | 150 ₽ | 2 шт.  | 300 ₽     | https://aliexpress.ru/item/1005004691735010.html?sku_id=12000030118892637&spm=.search_results.2.b5fe6debne6nar https://aliexpress.ru/item/1005001621784437.html?sku_id=12000030876907542&spm=.search_results.0.b5fe6debne6nar                                 | Можно использовать любые другие отладочные платы на базе ESP8266 |
| Кнопки                | 5 ₽   | 3 шт.  | 15 ₽      | https://aliexpress.ru/item/1005002483504604.html?sku_id=12000020816258869&spm=a2g2w.productlist.search_results.0.295d5690FECFoV https://aliexpress.ru/item/32815841388.html?sku_id=64712982838&spm=a2g2w.productlist.search_results.0.5ebf17d7lz9Jjz          | Подойдут абсолютно любые                                         |
| Лазерный диод         | 30 ₽  | 1 шт.  | 30 ₽      | https://aliexpress.ru/item/32436757591.html?sku_id=65633931684&spm=a2g2w.productlist.search_results.2.372f151e5sMS8q https://aliexpress.ru/item/590519565.html?sku_id=65690681743&spm=a2g2w.productlist.search_results.0.372f151e5sMS8q                       | 5 В, 5 мВт, 650 нм                                               |
| Модуль зарядки TP4056 | 30 ₽  | 1 шт.  | 30 ₽      | https://aliexpress.ru/item/32467578996.html?sku_id=10000003716909975&spm=a2g2w.productlist.search_results.0.3c313100BdBFoH https://aliexpress.ru/item/1005005741783050.html?sku_id=12000034179251543&spm=a2g2w.productlist.search_results.2.5f2666cfGdj9Ts    | Необходимо выбирать со встроенной схемой защиты                  |
| Аккумулятор           | 250 ₽ | 1 шт.  | 250 ₽     | https://aliexpress.ru/item/1005005684424738.html?sku_id=12000037283578784&spm=a2g2w.productlist.search_results.3.b37f312dNCFooa https://aliexpress.ru/item/4000939330410.html?sku_id=10000011329005536&spm=a2g2w.productlist.search_results.10.38178760eEMGWR | Можно использовать аккумуляторы из одноразок                     |
| Digispark             | 250 ₽ | 1 шт.  | 250 ₽     | https://aliexpress.ru/item/32807895683.html?sku_id=10000007831801690&spm=a2g2w.productlist.search_results.0.57674f500AUV34 https://aliexpress.ru/item/1005004203065658.html?sku_id=12000028365468636&spm=a2g2w.productlist.search_results.3.5d115ba6QB8ZHz    |                                                                  |
| Переключатель         | 20 ₽  | 1 шт.  | 20 ₽      | https://aliexpress.ru/item/4001202080623.html?sku_id=10000015286215548&spm=a2g2w.productlist.search_results.15.36e9243dFkvmUQ https://aliexpress.ru/item/1005001513148147.html?sku_id=12000031633680801&spm=a2g2w.productlist.search_results.0.6c5450dcP7qKsL | Нужен для откючения питания                                      |

Можно вместо одной из плат Wemos D1 Mini и платы TP4056 использовать очень интересную плату [ESP-Wroom-02 D1 Mini + 18650](https://aliexpress.ru/item/33060514583.html?sku_id=67531965171&spm=a2g2w.productlist.search_results.9.57387298mYMHuy), представляющую собой ESP8266 со встроенной зарядкой для литиевых аккумуляторов и холдером для аккумуляторов 18650.

Итоговая стоимость варьируется от **450 рублей** (при покупке мелким оптом и повторном использовании кнопок и аккумулятора) до **2000 рублей** (при покупке в розницу в местных магазинах и использовании нового большого аккумулятора)

<a id="chapter-4"></a>
## Как скачать и прошить
1. Установить и запустить Arduino IDE - [официальный сайт](https://www.arduino.cc/en/software')
2. Установить драйвера для контроллеров
  * CH340/CH341 - [официальный сайт](https://wch-ic.com/downloads/CH341SER_EXE.html)
  * CP2102 - [официальный сайт](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers)
3. Добавить допополнительные ссылки для менеджера плат
  * `Arduino IDE/Файл/Настройки/` В `Дополнительные ссылки …` добавить через `;`
    - `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
    - `https://raw.githubusercontent.com/digistump/arduino-boards-index/master/package_digistump_index.json`
4. Установить в менеджере плат:
  * `ESP8266 boards` рекомендуется версия 2.7.4
  * `Digistump AVR Boards` рекомендуется версия 1.6.7
5. Скачать архив с проектом (зелёная кнопка Code/Download ZIP)
6. Установить библиотеки (заменить имеющиеся версии) в 
  * `C:\Program Files (x86)\Arduino\libraries\` (Windows x64)  
  * `C:\Program Files\Arduino\libraries\` (Windows x86)
7. По очереди открыть файлы прошивки для каждого из микроконтроллеров, выбирая использумые платы и порт, прошить их
  * `LOLIN Wemos D1 R2 & mini` изменяйте в зависимости от используемой платы
  * `Digispark (Default – 16.5mhz)` ДО ПОДКЛЮЧЕНИЯ платы нажимаем загрузка, ждём компиляции. Появится надпись “подключите плату”. Втыкаем плату в USB и прошивка загружается.

### Настройки в коде
#### SlideRemoteTX.ino
```cpp
// Настройка пинов подключения
#define BTN_PREV_PIN D1
#define BTN_NEXT_PIN D2
#define BTN_LASER_PIN D3
#define LED_LASER_PIN D0

// MAC адрес приёмника
const uint8_t broadcastAddress[] = {0x48, 0x55, 0x19, 0xDE, 0xB3, 0x6B};
```
#### SlideRemoteRX.ino
```cpp
// Настройка пинов подключения
#define PREV_PIN D4
#define NEXT_PIN D3
```
#### SlideRemoteHID.ino
```cpp
// Настройка пинов подключения
#define PREV_PIN 0
#define NEXT_PIN 1
```
