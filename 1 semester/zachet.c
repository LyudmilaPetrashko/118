СЕМИНАРЫ 

1)!!! https://cmp.phys.msu.su/sites/default/files/Seminar12_0.pdf

CHAR один байт, в котором может находиться один символ из внутреннего набора
символов.
  INT Целое, обычно соответствующее естественному размеру целых в используемой
машине.
  FLOAT С плавающей точкой одинарной точности.
  DOUBLE С плавающей точкой двойной точности.
  Кроме того имеется ряд квалификаторов, которые можно использовать с типом
INT: SHORT (короткое), LONG (длинное) и UNSIGNED (без знака). Квалификаторы
SHORT и LONG указывают на различные размеры целых. Числа без знака
подчиняются законам арифметики по модулю 2 в степени N, где N — число битов в
INT; числа без знаков всегда положительны. Описания с квалификаторами имеют
вид:
  SHORT INT X;
  
  Символьная константа — это один символ, заключенный в одинарные кавычки,
как, например, 'х'. Значением символьной константы является численное значение
этого символа во внутреннем машинном наборе символов. Например, в наборе
символов ASCII символьный нуль, или '0', имеет значение 48
  
  Константное выражение — это выражение, состоящее из одних констант. Такие
выражения обрабатываются во время компиляции, а не при прогоне программы, и
соответственно могут быть использованы в любом месте, где можно использовать константу, как, например в
#DEFINE MAXLINE 1000
CHAR LINE[MAXLINE+1];
  
  Строчная константа — это последовательность, состоящая из нуля или более
символов, заключенных в двойные кавычки, как, например,
  
  Такие выражения, как
  I=I+2
в которых левая часть повторяется в правой части могут быть
записаны в сжатой форме
  I += 2
используя операцию присваивания вида +=.
Большинству бинарных операций (операций подобных +, которые имеют левый
и правый операнд) соответствует операция присваивания вида оп=, где оп — одна из
операций
  + — * / % << >> & \^ \!
  
  

2) !!! https://cmp.phys.msu.su/sites/default/files/Seminar13_0.pdf
  

3)ОБЪЕДИНЕНИЯ И СТРУКТУРЫ https://prog-cpp.ru/c-struct/
                       !!!  https://cmp.phys.msu.su/study/programming/c-book
                       

4) ИСТИНА И ЛОЖЬ. ЛОГИЧЕСКИЕ ОПЕРАТОРЫ https://learnc.info/c/logic_operators.html
   КРАТКИЕ ПОЛЕЗНОСТИ ! http://www.100byte.ru/stdntswrks/c/c.html#p1_4 !
  

5) Оператор IF — ELSE используется при необходимости сделать выбор. 
  Где часть ELSE является необязательной. Сначала вычисляется выражение; если
оно "истинно" /т.е. значение выражения отлично от нуля/, то выполняется оператор1.
Если оно ложно /значение выражения равно нулю/, и если есть часть с ELSE, то
вместо оператора-1 выполняется оператор-2.
Так как IF просто проверяет численное значение выражения, то возможно
некоторое сокращение записи. Самой очевидной возможностью является запись
IF (выражение) вместо
IF (выражение !=0)
иногда такая запись является ясной и естественной, но временами она становится
загадочной

Оператор SWITCH дает специальный способ выбора одного из многих вариантов,
который заключается в проверке совпадения значения данного выражения с одной
из заданных констант и соответствующем ветвлении. В главе 1 мы привели
программу подсчета числа вхождений каждой цифры, символов пустых промежутков
и всех остальных символов, использующую последовательность IF...ELSE IF...ELSE.1
Переключатель вычисляет целое выражение в круглых скобках (в данной
программе — значение символа с) и сравнивает его значение со всеми случаями
(CASE). Каждый случай должен быть помечен либо целым, либо символьной
константой, либо константным выражением. Если значение константного выражения, стоящего после вариантного префикса CASE, совпадает со значением целого
выражения, то выполнение начинается с этого случая. Если ни один из случаев не
подходит, то выполняется оператор после префикса DEFAULT. Префикс DEFAULT
является необязательным, если его нет, и ни один из случаев не подходит, то вообще
Оператор BREAK приводит к немедленному выходу из переключателя. Поскольку
случаи служат только в качестве меток, то если вы не предпримите явных действий
после выполнения операторов, соответствующих одному случаю, вы провалитесь на
следующий случай. Операторы BREAK и RETURN являются самым обычным способом
выхода из переключателя. Как мы обсудим позже в этой главе, оператор BREAк
можно использовать и для немедленного выхода из операторов цикла WHILE, FOR и
DO.
Проваливание сквозь случаи имеет как свои достоинства, так и недостатки. К
положительным качествам можно отнести то, что оно позволяет связать несколько
случаев с одним действием, как было с пробелом, табуляцией и новой строкой в
нашем примере. Но в то же время оно обычно приводит к необходимости
заканчивать каждый случай оператором BREAK, чтобы избежать перехода к
следующему случаю. Проваливание с одного случая на другой обычно бывает
неустойчивым, так как оно склонно к расщеплению при модификации программы. За
исключением, когда одному вычислению соответствуют несколько меток,
проваливание следует использовать умеренно.  


6)!!! https://cmp.phys.msu.su/sites/default/files/Seminar12_0.pdf
                        
7)!!! https://cmp.phys.msu.su/sites/default/files/Seminar14.pdf

8)!!! https://cmp.phys.msu.su/sites/default/files/Seminar16.pdf
 УКАЗАТЕЛИ НА СТРУКТУРЫ https://metanit.com/cpp/c/6.3.php
 ОПЕРАЦИИ С УКАЗАТЕЛЯМИ https://metanit.com/cpp/c/5.2.php
                       
9)https://learnc.info/c/arrays_vs_pointers.html
  

10)!!! https://cmp.phys.msu.su/sites/default/files/Seminar16.pdf
   https://learnc.info/c/memory_allocation.html
  
  
11)!!! https://cmp.phys.msu.su/sites/default/files/Seminar17c.pdf


12)!!! https://cmp.phys.msu.su/sites/default/files/Seminar17c.pdf
       https://prog-cpp.ru/c-files/


13) https://prog-cpp.ru/c-objects-namespace/

Программа на языке "C" состоит из набора внешних объектов, которые являются
либо переменными, либо функциями. Термин "внешний" используется главным
образом в противопоставление термину "внутренний", которым описываются
аргументы и автоматические переменные, определенные внурти функций. Внешние
переменные определены вне какой-либо функции и, таким образом, потенциально
доступны для многих функций. Сами функции всегда являются внешними, потому
что правила языка "C" не разрешают определять одни функции внутри других. По
умолчанию внешние переменные являются также и "глобальными", так что все
ссылки на такую переменную, использующие одно и то же имя (даже из функций,
скомпилированных независимо), будут ссылками на одно и то же.

Областью действия имени является та часть программы, в которой это имя
определено. Для автоматической переменной, описанной в начале функции, областью
действия является та функция, в которой описано имя этой переменной, а
переменные из разных функций, имеющие одинаковое имя, считаются не относящимися друг к другу.
Это же справедливо и для аргументов функций

Статические переменные могут быть либо внутренними, либо внешними.
Внутренние статические переменные точно так же, как и автоматические, являются
локальными для некоторой функции, но, в отличие от автоматических, они остаются
существовать, а не появляются и исчезают вместе с обращением к этой функции. это
означает, что внутренние статические переменные обеспечивают постоянное,
недоступное извне хранение внутри функции. Символьные строки, появляющиеся
внутри функции, как, например, аргументы PRINTF, являются внутренними
статическими.
Внешние статические переменные определены в остальной части того исходного
файла, в котором они описаны, но не в каком-либо другом файле. Таким образом, они
дают способ скрывать имена, подобные BUF и BUFP в комбинации GETCH-UNGETCH,
которые в силу их совместного использования должны быть внешними, но все же не
доступными для пользователей GETCH и UNGETCH, чтобы исключалась возможность
конфликта. Если эти две функции и две переменные объеденить в одном файле
следующим образом


14) !!! https://cmp.phys.msu.su/sites/default/files/Seminar18.pdf


15) unsigned char c;
for (int i = 7; i >= 0; --i) cout << ((c >> i) & 1);


16) !!! https://cmp.phys.msu.su/sites/default/files/Seminar17c.pdf
    https://prog-cpp.ru/c-string/
    
17) !!! https://cmp.phys.msu.su/sites/default/files/Seminar13_0.pdf
        https://prog-cpp.ru/c-directives/
       
       
       
ЛЕКЦИИ

4) ПУЗЫРЕК(20) https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf
  

5) QUICKSORT(22) https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf
  СЛИЯНИЕ https://prog-cpp.ru/sort-merge/

6) ПОСЛЕДОВАТЕЛЬНЫЙ ПОИСК https://prog-cpp.ru/search-serial/
   БИНАРНЫЙ ПОИСК https://prog-cpp.ru/search-binary/
   
7) http://www.mkurnosov.net/teaching/uploads/DSA/dsa-spring2015-lec6.pdf

8) https://prog-cpp.ru/data-struct/
    ! 43 https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf

9) https://prog-cpp.ru/data-tree/
    ! 48 https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf
    
10) https://prog-cpp.ru/mnk/

11) https://prog-cpp.ru/digital-find/
    ! https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf

12) 1 ПОРЯДОК http://aco.ifmo.ru/el_books/numerical_methods/lectures/glava1.html
      

13) ТРАПЕЦИИ https://prog-cpp.ru/integral-trapecia/
    ! https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf

14) ! https://cmp.phys.msu.ru/sites/default/files/Informatics-2015.pdf

15) 
                            
  
  